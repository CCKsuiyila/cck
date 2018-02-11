#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 5000
//#define SEND_PORT 5001

#define MaxNum 10 //最大连接数
DWORD ClientTread(void * PD);
SOCKET ServerSock;
sockaddr_in ServerAddr;
int Addrlen;

HANDLE HdTread[MaxNum];	
struct {
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
	//printf("%d\n",MaxNum);
	for(i=0;i<MaxNum;i++)		   
	{
		Client[i].num = -1; //初始化编号（-1表示尚未使用）	
	}

	printf("Server listening....\n");

	for(;;)
	{  
		for(i=0;i<MaxNum;i++)		   		
	      if(Client[i].num==-1 || Client[i].Socket==INVALID_SOCKET)			
		  {
		      Client[i].Socket=accept(ServerSock,(struct sockaddr FAR*)&Client[i].Addr,&Addrlen);
		      if(Client[i].Socket!=INVALID_SOCKET)   //have got a socket Id
			  {			     
					printf("远程主机:%s 通过端口: %d 进入聊天室...\n", inet_ntoa(Client[i].Addr.sin_addr),ntohs(Client[i].Addr.sin_port));
					Client[i].num=i;   			
					break;		
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
DWORD ClientTread(void * PD)
{	
	char buff[1024], temp[1024]; // buff[]:Recieve Message 		
	int  client_id = *(int *)PD;
	printf("此客户ID为：%d\n", client_id);

	//*********** deal with the talking words *******************
		while(1)
		{
			memset(buff,0,sizeof(buff));
			memset(temp,0,sizeof(temp));

			if( TCPRecv( Client[client_id].Socket, buff ) <= 0 ) //接收客户client_id的消息
				continue;	

			//------- 解析消息 ---------------------
			//...
		    // -------------------------------------
			printf("该用户发的消息为：%s\n", buff);
			//----------------------  服务器转发至所有在线客户 ------------------------------
			for(int i=0; i<MaxNum; i++)  { 

			         if(Client[i].num!=-1 && Client[i].Socket!=INVALID_SOCKET)
					 {
						 TCPSend(Client[i].Socket, buff);
					 }	
			 }//end of 转发

			 if(!strncmp(buff,"Down",4))   // the user quit talk 
			 {
				  DeleteOne(client_id);
				  ExitThread(client_id);
				  printf("%s go down\n", inet_ntoa(Client[client_id].Addr.sin_addr));	 							  
				  return 0;
			 }

		}//end of while

}

DWORD TCPSend(SOCKET s, char data[])
{
	int iSend;
	iSend = send(s,data,strlen(data)+1,0);

	if(iSend == SOCKET_ERROR)
	{
	   printf("sendto()Failed:%d\n",WSAGetLastError());
	   return -1;
	}
	else if(iSend == 0){
		return 0;
	}
	else{
		printf("sendto()succeeded.\n");	
	    return 1;
	}
}

DWORD TCPRecv(SOCKET s, char data[])
{
	int iRecv;
	iRecv = recv(s,data,sizeof(data),0);

	if(iRecv == SOCKET_ERROR)
	{
	   printf("sendto()Failed:%d\n",WSAGetLastError());
	   return -1;
	}
	else if(iRecv == 0){
		return 0;
	}
	else{
		printf("sendto()succeeded.\n");	
	    return 1;
	}
}

void DeleteOne(int i)  //删除一个客户，将其占用的socket还回去
{
	Client[i].num = -1;

	if(Client[i].Socket != INVALID_SOCKET)
	{
		Client[i].Socket = INVALID_SOCKET;	
	}
}

