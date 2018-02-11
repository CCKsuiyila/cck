#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 5001

#define MaxNum 10  //最大连接数
#define MaxLength 1024 //最大消息长度

DWORD ClientTread(void * PD);
SOCKET ServerSock;
sockaddr_in ServerAddr;
int Addrlen;

HANDLE HdTread[MaxNum];
struct {
	int num;
	char name[10];
	char ToName[10];  //the talk target
	bool Priv;       //the talk target is or not private 
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
	if (StartSock() == -1) //初始化socket
		return -1;

	if (CreateTCPSocket() == -1) //创建tcp socket
		return -1;

	if (BindSocket() == -1) //绑定socket
		return -1;

	if (ConnectProcess() == -1) //连接处理
		return -1;

	return 1;
}

DWORD StartSock() //初始化socket
{
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
	{
		printf("socket init Failed:%d\n", WSAGetLastError());
		getchar();
		return -1;
	}
	return 1;
}

DWORD CreateTCPSocket() //创建tcp socket
{
	ServerSock = socket(AF_INET, SOCK_STREAM, 0); //create a tcp socket

	if (ServerSock == SOCKET_ERROR)
	{
		printf("sock create Failed:%d\n", WSAGetLastError());
		WSACleanup();
		getchar();
		return -1;
	}

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("192.168.0.10");
	ServerAddr.sin_port = htons(RECV_PORT);

	return 1;
}

DWORD BindSocket() //绑定socket
{
	if (bind(ServerSock, (struct sockaddr FAR*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		printf("bind Failed:%d\n", WSAGetLastError());
		getchar();
		return -1;
	}

	return 1;
}

DWORD ConnectProcess() //连接处理
{
	int i = 0, k;

	Addrlen = sizeof(sockaddr_in);
	if (listen(ServerSock, MaxNum)<0)
	{
		printf("listen Failed:%d\n", WSAGetLastError());
		getchar();
		return -1;
	}

	for (i = 0; i<MaxNum; i++)
	{
		Client[i].num = -1; //初始化编号（-1表示尚未使用）	
	}

	printf("Server listening....\n");

	for (;;)
	{
		for (i = 0; i<MaxNum; i++)
		if (Client[i].num == -1 || Client[i].Socket == INVALID_SOCKET)//有问题
		{
			Client[i].Socket = accept(ServerSock, (struct sockaddr FAR*)&Client[i].Addr, &Addrlen);
			if (Client[i].Socket != INVALID_SOCKET)   //have got a socket Id
			{
				Client[i].num = i;
				break;
			}
		}
		if (i >= MaxNum) { //reach the max numbers!
			Sleep(1000);
			continue;
		}

		k = i; //get a index 
		HdTread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClientTread, (void *)&k, 0, &Client[i].ThreadId);
	}
}

//线程处理函数（参数PD为客户索引）
DWORD ClientTread(void * PD)
{
	char buff[MaxLength], temp[MaxLength]; // buff[]:Recieve Message 		
	int  client_id = *(int *)PD;
	int len;
	DWORD ExitCode = 0;

	//*********** Revieve user's login name **********************************
	while (1)
	{
		memset(buff, 0, sizeof(buff));
		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //等待获取用户名

		//---------- 判断是否与在线用户名冲突 -------------
		//...
		//-------------------------------------------------

		// if ( 不冲突)
		{
			strcpy(Client[client_id].name, buff);// 有效名字

			printf(Client[client_id].name); printf("  ");
			printf(inet_ntoa(Client[client_id].Addr.sin_addr));
			printf(" has connected. \n");

			//---------- 发送给所有在线用户，声明***加入了聊天室，并向***传送在线人员列表 ---------
			//...
			//-------------------------------------------------------------------------------------
			break;
		}
	}

	//*********** deal with the talking words *******************
	while (1)
	{
		memset(buff, 0, sizeof(buff));

		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //接收客户client_id的消息		

		//------- 解析消息 ---------------------
		//...
		// -------------------------------------

		//----------------------  服务器转发至所有在线客户 ------------------------------
		for (int i = 0; i<MaxNum; i++)  {

			if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET)
			{
				c
			}
		}//end of 转发

		if (!strncmp(buff, "Down", 4))   // the user quit talk 
		{
			printf("%s go down\n", inet_ntoa(Client[client_id].Addr.sin_addr));

			DeleteOne(client_id);  //删除当前用户
			ExitThread(client_id);	//退出线程 			
		}

	}//end of while

}

DWORD TCPSend(SOCKET s, char data[])
{
	int length;
	length = send(s, data, strlen(data)+1, 0);
	if (length <= 0)
		return -1;
	return 1;
}

DWORD TCPRecv(SOCKET s, char data[])
{
	int length;
	length = recv(s, data, MaxLength, 0);  //此处第3个参数不能用 sizeof(data)
	if (length <= 0)
		return -1;
	return 1;
}

void DeleteOne(int i)  //删除一个客户，将其占用的socket还回去
{
	Client[i].num = -1;

	if (Client[i].Socket != INVALID_SOCKET)
	{
		Client[i].Socket = INVALID_SOCKET;
	}

	//其它处理工作
	//...
}

