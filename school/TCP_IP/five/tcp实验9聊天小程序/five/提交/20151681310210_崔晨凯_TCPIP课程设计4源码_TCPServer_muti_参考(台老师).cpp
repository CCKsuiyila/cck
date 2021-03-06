#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 5012

#define MaxNum 10 //最大连接数
#define MaxLength 1024 //最大消息长度

DWORD ClientTread(void * PD);  //
SOCKET ServerSock;
sockaddr_in ServerAddr;
int Addrlen;

HANDLE HdTread[MaxNum];	
struct {
	char name[1024];
	char ToName[1024]; 
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
	if(StartSock()==-1) //初始化socket
		return -1;

    if(CreateTCPSocket()==-1) //创建tcp socket
		return -1;

	if(BindSocket() == -1) //绑定socket
		return -1;

	if(ConnectProcess()==-1) //连接处理
		return -1;

	return 1;
}

DWORD StartSock() //初始化socket
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

DWORD CreateTCPSocket() //创建tcp socket
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

DWORD BindSocket() //绑定socket
{
	if(bind(ServerSock,(struct sockaddr FAR*)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR)
	{
		printf("bind Failed:%d\n",WSAGetLastError());
		getchar();
		return -1;
	}

	return 1;
}

DWORD ConnectProcess() //连接处理
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
		Client[i].num = -1; //初始化编号（-1表示尚未使用）	
	}

	printf("Server listening....\n");

	for(;;)
	{  
		for(i=0;i<MaxNum;i++){		   		
			if(Client[i].num==-1 || Client[i].Socket==INVALID_SOCKET){   
				Client[i].Socket=accept(ServerSock,(struct sockaddr FAR*)&Client[i].Addr,&Addrlen);
				if(Client[i].Socket!=INVALID_SOCKET){		   //have got a socket Id	     
					printf("远程主机:%s 通过端口: %d 进入聊天室...\n", inet_ntoa(Client[i].Addr.sin_addr),ntohs(Client[i].Addr.sin_port));
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

//线程处理函数（参数PD为客户索引）
DWORD ClientTread(void * PD){	
	char buff[1024], temp[1024]; // buff[]:Recieve Message 		
	int  client_id = *(int *)PD;
	int len;
	DWORD ExitCode = 0;
	
	//处理登录
	while(1){
		memset(buff,'\0',MaxLength);
		
		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //接收客户client_id的消息	
		
		char temp_save[] = {"talker:"};
		if(!strncmp(buff,temp_save,7)){ 			// the user quit talk 
				
			char name[1024];
			memset(name,'\0',MaxLength);
			for(int j =7;j<12;++j){
				name[j-7] = buff[j];
			}
			int sign = 0;
			for(int k =0;k<MaxNum;++k){
				if(!strncmp(name,Client[k].name,6)){
					TCPSend(Client[client_id].Socket, "The name has been used. Please input again.");
					sign  = 1;
					break;
				}
			}
			if(sign==1){
				continue;
			}
			Client[client_id].Priv = false;
			Client[client_id].num = client_id;
			memset(Client[client_id].name,'\0',MaxLength);
			strcpy(Client[client_id].name ,name);
			memset(Client[client_id].ToName,'\0',MaxLength);
			strcpy(Client[client_id].ToName,"all");
			TCPSend(Client[client_id].Socket, "欢迎来到椰岛绿洲聊天室\n________________________________\nThe method that you send a message:\nyour_words\n//(all)your_words\n//(name)your_words\n//{name}your_words--means private talk\n________________________________\n");
			
			//发送在线用户
			char online_user[1024];
			memset(online_user,'\0',MaxLength);
			strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
			for(j=0; j<MaxNum; ++j){
				if(Client[j].num!=-1){
					strcat(online_user,Client[j].name);
					strcat(online_user,"  ");
				}
				strcat(online_user,"\0");
			}
			TCPSend(Client[client_id].Socket,online_user);
			
			//向所有用户发送该用户上线
			char send_join[1024];
			memset(send_join,'\0',MaxLength);
			strncat(send_join,name,strlen(name)+1);
			strncat(send_join," join us",8);
			printf("%s\n",send_join);
			for (int i = 0; i<MaxNum; ++i){
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					TCPSend(Client[i].Socket,send_join);
				}
			}//end of 转发
			break;
		}
	}
	
	//*********** deal with the talking words *******************
	while(1){
		memset(buff,'\0',MaxLength);
			
		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //接收客户client_id的消息	
		
		//处理正常离开
		if (!strncmp(buff, "Down", 4)){  // the user quit talk 
			printf("%s go down\n", inet_ntoa(Client[client_id].Addr.sin_addr));

			memset(buff,'\0',MaxLength);
			strncat(buff,Client[client_id].name,strlen(Client[client_id].name));
			strncat(buff," go down...\n",12);
						
			char online_user[1024];
			memset(online_user,'\0',MaxLength);
			strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
			for(int j=0; j<MaxNum; ++j){
				if(Client[j].num!=-1&&Client[j].num!=client_id){
					strcat(online_user,Client[j].name);
					strcat(online_user,"  ");
				}
				strcat(online_user,"\0");
			}
						
			strncat(buff,online_user,strlen(online_user));
						
			//广播该用户下线
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					TCPSend(Client[i].Socket, buff);
				}
			}
			

			//修改为all
			for (i = 0; i<MaxNum; ++i)  {
				if (!strncmp(Client[i].ToName,Client[client_id].name,5)){
					memset(Client[i].ToName,'\0',MaxLength);
					strcpy(Client[i].ToName,"all");
				}
			}
			
			
			DeleteOne(client_id);  //删除当前用户
			ExitThread(client_id);	//退出线程 			
		}
		
		//处理转发
		char change_ToName[1024];
		memset(change_ToName,'\0',MaxLength);
		if(!strncmp(buff, "//(all)",7)){
			memset(Client[client_id].ToName,'\0',MaxLength);
			strcpy(Client[client_id].ToName,"all");
			Client[client_id].Priv=false;
			
			memset(temp,'\0',MaxLength);
			strncat(temp,Client[client_id].name,strlen(Client[client_id].name));
			strncat(temp," to ",4);
			strncat(temp,Client[client_id].ToName,strlen(Client[client_id].ToName));
			strncat(temp," : ",3);
			strncat(temp,buff,strlen(buff));
			strcpy(buff,temp);
			
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// 该用户意外退出了
						printf("%s exceptionally go down...\n", Client[i].name);
						
						memset(buff,'\0',MaxLength);
						strncat(buff,Client[i].name,strlen(Client[i].name));
						strncat(buff," exceptionally go down...\n",26);
						
						DeleteOne(i); ////删除该用户
						TerminateThread(HdTread[i], ExitCode);//终止该用户的线程	
						
						char online_user[1024];
						memset(online_user,'\0',MaxLength);
						strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
						for(int j=0; j<MaxNum; ++j){
							if(Client[j].num!=-1){
								strcat(online_user,Client[j].name);
								strcat(online_user,"  ");
							}
							strcat(online_user,"\0");
						}
						
						strncat(buff,online_user,strlen(online_user));
						
						
						
						//广播该用户下线
						for (i = 0; i<MaxNum; ++i)  {
							if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
								TCPSend(Client[i].Socket, buff);
							}
						}
					
											
					}
				}
				
			}
		}else if(!strncmp(buff, "//(",3)){
			memset(Client[client_id].ToName,'\0',MaxLength);
			for(int j =3;buff[j]!=')';++j){
				change_ToName[j-3] = buff[j];
			}
			strcpy(Client[client_id].ToName,change_ToName);
			Client[client_id].Priv=false;
			
			memset(temp,'\0',MaxLength);
			strncat(temp,Client[client_id].name,strlen(Client[client_id].name));
			strncat(temp," to ",4);
			strncat(temp,Client[client_id].ToName,strlen(Client[client_id].ToName));
			strncat(temp," : ",3);
			strncat(temp,buff,strlen(buff));
			strcpy(buff,temp);
			
			for (int i = 0; i<MaxNum; ++i){
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// 该用户意外退出了
						printf("%s exceptionally go down...\n", Client[i].name);
						
						//改变聊天对象为all
						memset(Client[client_id].ToName,'\0',MaxLength);
						strcpy(Client[client_id].ToName,"all");
						Client[client_id].Priv=false;
						
						memset(buff,'\0',MaxLength);
						strncat(buff,Client[i].name,strlen(Client[i].name));
						strncat(buff," exceptionally go down...\n",26);
						
						DeleteOne(i); ////删除该用户
						TerminateThread(HdTread[i], ExitCode);//终止该用户的线程
						
						char online_user[1024];
						memset(online_user,'\0',MaxLength);
						strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
						for(int j=0; j<MaxNum; ++j){
							if(Client[j].num!=-1){
								strcat(online_user,Client[j].name);
								strcat(online_user,"  ");
							}
							strcat(online_user,"\0");
						}
						
						strncat(buff,online_user,strlen(online_user));
						
						
						//广播该用户下线
						for (i = 0; i<MaxNum; ++i)  {
							if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
								TCPSend(Client[i].Socket, buff);
							}
						}
						
											
					}
				}
				
			}
		}else if(!strncmp(buff, "//{",3)){
			memset(Client[client_id].ToName,'\0',MaxLength);
			for(int j =3;buff[j]!='}';++j){
				change_ToName[j-3] = buff[j];
			}
			strcpy(Client[client_id].ToName,change_ToName);
			Client[client_id].Priv=true;
			
			memset(temp,'\0',MaxLength);
			strncat(temp,Client[client_id].name,strlen(Client[client_id].name));
			strncat(temp," to ",4);
			strncat(temp,Client[client_id].ToName,strlen(Client[client_id].ToName));
			strncat(temp," : ",3);
			strncat(temp,buff,strlen(buff));
			strcpy(buff,temp);
			
			for (int i = 0; i<MaxNum; ++i)  {
				if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET && strncmp(Client[i].name, Client[client_id].ToName,5)==0){
					int len = TCPSend(Client[i].Socket, buff);
					if (len <= 0){// 该用户意外退出了
						printf("%s exceptionally go down...\n", Client[i].name);
						
						//改变聊天对象为all
						memset(Client[client_id].ToName,'\0',MaxLength);
						strcpy(Client[client_id].ToName,"all");
						Client[client_id].Priv=false;
						
						memset(buff,'\0',MaxLength);
						strncat(buff,Client[i].name,strlen(Client[i].name));
						strncat(buff," exceptionally go down...\n",26);
						
						DeleteOne(i); ////删除该用户
						TerminateThread(HdTread[i], ExitCode);//终止该用户的线程		
						
						char online_user[1024];
						memset(online_user,'\0',MaxLength);
						strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
						for(int j=0; j<MaxNum; ++j){
							if(Client[j].num!=-1){
								strcat(online_user,Client[j].name);
								strcat(online_user,"  ");
							}
							strcat(online_user,"\0");
						}
						
						strncat(buff,online_user,strlen(online_user));
						
						
						//广播该用户下线
						for (i = 0; i<MaxNum; ++i)  {
							if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
								TCPSend(Client[i].Socket, buff);
							}
						}
										
					}
				}
				
			}
		}else if(strlen(buff)>0){
			if(!strncmp(Client[client_id].ToName,"all" ,3)||Client[client_id].Priv==false){     //发送给所有用户
			
				memset(temp,'\0',MaxLength);
				strncat(temp,Client[client_id].name,strlen(Client[client_id].name));
				strncat(temp," to ",4);
				strncat(temp,Client[client_id].ToName,strlen(Client[client_id].ToName));
				strncat(temp," : ",3);
				strncat(temp,buff,strlen(buff));
				strcpy(buff,temp);
			
				for (int i = 0; i<MaxNum; ++i) {
					if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
						int len = TCPSend(Client[i].Socket, buff);
						if (len <= 0){// 该用户意外退出了
							printf("%s exceptionally go down...\n", Client[i].name);
							
							//改变聊天对象为all
							memset(Client[client_id].ToName,'\0',MaxLength);
							strcpy(Client[client_id].ToName,"all");
							Client[client_id].Priv=false;
							
							memset(buff,'\0',MaxLength);
							strncat(buff,Client[i].name,strlen(Client[i].name));
							strncat(buff," exceptionally go down...\n",26);
							
							DeleteOne(i); ////删除该用户
							TerminateThread(HdTread[i], ExitCode);//终止该用户的线程		
							
							char online_user[1024];
							memset(online_user,'\0',MaxLength);
							strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
							for(int j=0; j<MaxNum; ++j){
								if(Client[j].num!=-1){
									strcat(online_user,Client[j].name);
									strcat(online_user,"  ");
								}
								strcat(online_user,"\0");
							}
						
							strncat(buff,online_user,strlen(online_user));
						
							
							//广播该用户下线
							for (i = 0; i<MaxNum; ++i)  {
								if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
									TCPSend(Client[i].Socket, buff);
								}
							}
					
											
						}
					}
				}
			}else if(Client[client_id].Priv==true){                                             //发送给特定用户
				
				memset(temp,'\0',MaxLength);
				strncat(temp,Client[client_id].name,strlen(Client[client_id].name));
				strncat(temp," to ",4);
				strncat(temp,Client[client_id].ToName,strlen(Client[client_id].ToName));
				strncat(temp," : ",3);
				strncat(temp,buff,strlen(buff));
				strcpy(buff,temp);
			
				for (int i = 0; i<MaxNum; ++i){
					if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET && strncmp(Client[i].name, Client[client_id].ToName,5) == 0){
						int len = TCPSend(Client[i].Socket, buff);
						if (len <= 0){// 该用户意外退出了
							printf("%s exceptionally go down...\n", Client[i].name);
							
							//改变聊天对象为all
							memset(Client[client_id].ToName,'\0',MaxLength);
							strcpy(Client[client_id].ToName,"all");
							Client[client_id].Priv=false;
							
							memset(buff,'\0',MaxLength);
							strncat(buff,Client[i].name,strlen(Client[i].name));
							strncat(buff," exceptionally go down...\n",26);
							
							DeleteOne(i); ////删除该用户
							TerminateThread(HdTread[i], ExitCode);//终止该用户的线程	
					
							char online_user[1024];
							memset(online_user,'\0',MaxLength);
							strncat(online_user,"当前在线用户:",strlen("当前在线用户:"));
							for(int j=0; j<MaxNum; ++j){
								if(Client[j].num!=-1){
									strcat(online_user,Client[j].name);
									strcat(online_user,"  ");
								}
								strcat(online_user,"\0");
							}
						
							strncat(buff,online_user,strlen(online_user));
							
							//广播该用户下线
							for (i = 0; i<MaxNum; ++i)  {
								if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET){
									TCPSend(Client[i].Socket, buff);
								}
							}
						
												
						}
						break;
					}
				}
			}
		}
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
	length = recv(s, data, MaxLength, 0);  //此处第3个参数不能用 sizeof(data)
	if (length <= 0)
		return -1;
	return 1;
}

void DeleteOne(int i){  //删除一个客户，将其占用的socket还回去
	Client[i].num = -1;
	memset(Client[i].name,'\0',sizeof(Client[i].name));
	memset(Client[i].ToName,'\0',sizeof(Client[i].ToName));
	Client[i].Priv = false;
	if (Client[i].Socket != INVALID_SOCKET){
		Client[i].Socket = INVALID_SOCKET;
	}

	//其它处理工作
	//...
}

