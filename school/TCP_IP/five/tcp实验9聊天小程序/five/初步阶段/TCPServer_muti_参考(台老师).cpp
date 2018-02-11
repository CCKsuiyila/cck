#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 5012

#define MaxNum 10 //���������
#define MaxLength 1024 //�����Ϣ����

DWORD ClientTread(void * PD);  //
SOCKET ServerSock;
sockaddr_in ServerAddr;
int Addrlen;

HANDLE HdTread[MaxNum];	
struct {
	char name[10];
	char ToName[10]; 
	bool Priv;      
	int num; 
	DWORD ThreadId;
	SOCKET Socket;
	sockaddr_in Addr;
}Client[MaxNum];

DWORD StartSock();
DWORD CreateTCPSocket();
DWORD BindSocket();
DWORD ConnectProcess();
DWORD ClientTread(void * PD);
DWORD TCPSend(SOCKET s, char data[]);
DWORD TCPRecv(SOCKET s, char data[]);
void DeleteOne(int i);

int main()
{
	if(StartSock()==-1) //��ʼ��socket
		return -1;

    if(CreateTCPSocket()==-1) //����tcp socket
		return -1;

	if(BindSocket() == -1) //��socket
		return -1;

	if(ConnectProcess()==-1) //���Ӵ���
		return -1;

	return 1;
}

DWORD StartSock() //��ʼ��socket
{
	WSADATA WSAData;
	if(WSAStartup(MAKEWORD(2,2),&WSAData)!=0)
	{
		printf("socket init Failed:%d\n",WSAGetLastError());
		getchar();
		return -1;
    }
	return 1;
}

DWORD CreateTCPSocket() //����tcp socket
{
	ServerSock = socket(AF_INET,SOCK_STREAM,0); //create a tcp socket

	if(ServerSock == SOCKET_ERROR)
	{
		printf("sock create Failed:%d\n",WSAGetLastError());		
		WSACleanup();
		getchar();
		return -1;
	}

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("172.20.10.5");
	ServerAddr.sin_port = htons(RECV_PORT);

	return 1;
}

DWORD BindSocket() //��socket
{
	if(bind(ServerSock,(struct sockaddr FAR*)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR)
	{
		printf("bind Failed:%d\n",WSAGetLastError());
		getchar();
		return -1;
	}

	return 1;
}

DWORD ConnectProcess() //���Ӵ���
{	
	int i=0,k;

	Addrlen = sizeof(sockaddr_in);
    if(listen(ServerSock,MaxNum)<0)
	{
		printf("listen Failed:%d\n",WSAGetLastError());
		getchar();
		return -1;
	}
	
	for(i=0;i<MaxNum;i++)		   
	{
		Client[i].num = -1; //��ʼ����ţ�-1��ʾ��δʹ�ã�	
	}

	printf("Server listening....\n");

	for(;;)
	{  
		for(i=0;i<MaxNum;i++){		   		
			if(Client[i].num==-1 || Client[i].Socket==INVALID_SOCKET){   
				Client[i].Socket=accept(ServerSock,(struct sockaddr FAR*)&Client[i].Addr,&Addrlen);
				if(Client[i].Socket!=INVALID_SOCKET){		   //have got a socket Id	     
					printf("Զ������:%s ͨ���˿�: %d ����������...\n", inet_ntoa(Client[i].Addr.sin_addr),ntohs(Client[i].Addr.sin_port));
					Client[i].num=i;   			
					break;		
				}
			}	  
		}
		if(i >= MaxNum) { //reach the max numbers!
			Sleep(1000); 
			continue;  			
		}

		k = i; //get a index 
		HdTread[i] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ClientTread,(void *)&k,0,&Client[i].ThreadId); 
	}		
}

//�̴߳�����������PDΪ�ͻ�������
DWORD ClientTread(void * PD){	
	char buff[1024], temp[1024]; // buff[]:Recieve Message 		
	int  client_id = *(int *)PD;
	int len;
	DWORD ExitCode = 0;
	
	//�����¼
	while(1){
		memset(buff,'\0',sizeof(buff));
		
		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //���տͻ�client_id����Ϣ	
		
		char temp_save[] = {"talker:"};
		if(!strncmp(buff,temp_save,7)){ 			// the user quit talk 
				
			char name[10];
			for(int j =7;j<12;++j){
				name[j-7] = buff[j];
			}
			name[5] = '\0';
			for(int k =0;k<MaxNum;++k){
				if(!strncmp(name,Client[k].name,6)){
					TCPSend(Client[client_id].Socket, "The name has been used. Please input again.");
					continue;
				}
			}
			Client[client_id].Priv = false;
			Client[client_id].num = client_id;
			memset(Client[client_id].name,'\0',sizeof(Client[client_id].name));
			strcpy(Client[client_id].name ,name);
			memset(Client[client_id].ToName,'\0',sizeof(Client[client_id].ToName));
			strcpy(Client[client_id].ToName,"all");
			TCPSend(Client[client_id].Socket, "��ӭ����Ҭ������������\n________________________________\nThe method that you send a message:\nyour_words\n//(all)your_words\n//(name)your_words\n//{name}your_words--means private talk\n________________________________\n");
			
			//���������û�
			char online_user[1024];
			memset(online_user,'\0',sizeof(online_user));
			strncat(online_user,"��ǰ�����û�:",strlen("��ǰ�����û�:"));
			for(j=0; j<MaxNum; ++j){
				if(Client[j].num!=-1){
					strcat(online_user,Client[j].name);
					strcat(online_user,"  ");
				}
				strcat(online_user,"\0");
			}
			TCPSend(Client[client_id].Socket,online_user);
			
			//�������û����͸��û�����
			char send_join[100];
			memset(send_join,'\0',sizeof(send_join));
			strncat(send_join,name,strlen(name)+1);
			strncat(send_join," join us",8);
			printf("%s\n",send_join);
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					TCPSend(Client[i].Socket,send_join);
				}
			}//end of ת��
			break;
		}
	}
	
	//*********** deal with the talking words *******************
	while(1){
		memset(buff,'\0',sizeof(buff));
			
		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //���տͻ�client_id����Ϣ	
		
		//------- ������Ϣ ---------------------
		//...
		
		//���������뿪
		if (!strncmp(buff, "Down", 4)){  // the user quit talk 
			printf("%s go down\n", inet_ntoa(Client[client_id].Addr.sin_addr));

			DeleteOne(client_id);  //ɾ����ǰ�û�
			ExitThread(client_id);	//�˳��߳� 			
		}
		
		//����ת��
		char change_ToName[10];
		memset(change_ToName,'\0',sizeof(change_ToName));
		if(!strncmp(buff, "//(all)",7)){
			printf("(all)");
			memset(Client[client_id].ToName,'\0',sizeof(Client[client_id].ToName));
			strcpy(Client[client_id].ToName,"all");
			
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// ���û������˳���
						printf("%s exceptionally go down...\n", Client[i].name);
					
						DeleteOne(i); ////ɾ�����û�
						TerminateThread(HdTread[i], ExitCode);//��ֹ���û����߳�						
					}
				}
				
			}
			
		}else if(!strncmp(buff, "//(",3)){
			printf("(name)");
			memset(Client[client_id].ToName,'\0',sizeof(Client[client_id].ToName));
			for(int j =3;buff[j]!=')';++j){
				change_ToName[j-3] = buff[j];
			}
			strcpy(Client[client_id].ToName,change_ToName);
			
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// ���û������˳���
						printf("%s exceptionally go down...\n", Client[i].name);
					
						DeleteOne(i); ////ɾ�����û�
						TerminateThread(HdTread[i], ExitCode);//��ֹ���û����߳�						
					}
				}
				
			}
		}else if(!strncmp(buff, "//{",3)){
			printf("{name}");
			memset(Client[client_id].ToName,'\0',sizeof(Client[client_id].ToName));
			for(int j =3;buff[j]!='}';++j){
				change_ToName[j-3] = buff[j];
			}
			strcpy(Client[client_id].ToName,change_ToName);
			
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET && strncmp(Client[i].name, Client[client_id].ToName,5)==0){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// ���û������˳���
						printf("%s exceptionally go down...\n", Client[i].name);
					
						DeleteOne(i); ////ɾ�����û�
						TerminateThread(HdTread[i], ExitCode);//��ֹ���û����߳�						
					}
				}
				
			}
		}else{
			printf("��ǰ׺");
			//���͸������û�
			if(!strncmp(Client[client_id].ToName,"all" ,3)){
				for (int i = 0; i<MaxNum; ++i) {
					if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
						int len = TCPSend(Client[i].Socket, buff);
						if (len <= 0){// ���û������˳���
							printf("%s exceptionally go down...\n", Client[i].name);
					
							DeleteOne(i); ////ɾ�����û�
							TerminateThread(HdTread[i], ExitCode);//��ֹ���û����߳�						
						}
					}
				}
			}
			//���͸��ض��û�
			for (int i = 0; i<MaxNum; ++i) {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET && strncmp(Client[i].name, Client[client_id].ToName,5) == 0){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// ���û������˳���
						printf("%s exceptionally go down...\n", Client[i].name);
					
						DeleteOne(i); ////ɾ�����û�
						TerminateThread(HdTread[i], ExitCode);//��ֹ���û����߳�						
					}
					break;
				}
			}
		}
		
		
		/*
		// -------------------------------------
		//----------------------  ������ת�����������߿ͻ� ------------------------------
		for (int i = 0; i<MaxNum; i++)  {

			if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET)
			{
				len = TCPSend(Client[i].Socket, buff);
				if (len <= 0)  // ���û������˳���
				{
					printf("%s exceptionally go down...\n", Client[i].name);
					
					DeleteOne(i); ////ɾ�����û�
					TerminateThread(HdTread[i], ExitCode);//��ֹ���û����߳�						
				}
			}
		}//end of ת��
		*/
	}
}

DWORD TCPSend(SOCKET s, char data[]){
	int length;
	length = send(s, data, strlen(data)+1, 0);
	if (length <= 0)
		return -1;
	return 1;
}

DWORD TCPRecv(SOCKET s, char data[]){
	int length;
	length = recv(s, data, MaxLength, 0);  //�˴���3������������ sizeof(data)
	if (length <= 0)
		return -1;
	return 1;
}

void DeleteOne(int i){  //ɾ��һ���ͻ�������ռ�õ�socket����ȥ
	Client[i].num = -1;
	memset(Client[i].name,'\0',sizeof(Client[i].name));
	memset(Client[i].ToName,'\0',sizeof(Client[i].ToName));
	if (Client[i].Socket != INVALID_SOCKET)
	{
		Client[i].Socket = INVALID_SOCKET;
	}

	//����������
	//...
}

