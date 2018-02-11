#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 5001

#define MaxNum 10  //���������
#define MaxLength 1024 //�����Ϣ����

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
	if (StartSock() == -1) //��ʼ��socket
		return -1;

	if (CreateTCPSocket() == -1) //����tcp socket
		return -1;

	if (BindSocket() == -1) //��socket
		return -1;

	if (ConnectProcess() == -1) //���Ӵ���
		return -1;

	return 1;
}

DWORD StartSock() //��ʼ��socket
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

DWORD CreateTCPSocket() //����tcp socket
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

DWORD BindSocket() //��socket
{
	if (bind(ServerSock, (struct sockaddr FAR*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		printf("bind Failed:%d\n", WSAGetLastError());
		getchar();
		return -1;
	}

	return 1;
}

DWORD ConnectProcess() //���Ӵ���
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
		Client[i].num = -1; //��ʼ����ţ�-1��ʾ��δʹ�ã�	
	}

	printf("Server listening....\n");

	for (;;)
	{
		for (i = 0; i<MaxNum; i++)
		if (Client[i].num == -1 || Client[i].Socket == INVALID_SOCKET)//������
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

//�̴߳�����������PDΪ�ͻ�������
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
		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //�ȴ���ȡ�û���

		//---------- �ж��Ƿ��������û�����ͻ -------------
		//...
		//-------------------------------------------------

		// if ( ����ͻ)
		{
			strcpy(Client[client_id].name, buff);// ��Ч����

			printf(Client[client_id].name); printf("  ");
			printf(inet_ntoa(Client[client_id].Addr.sin_addr));
			printf(" has connected. \n");

			//---------- ���͸����������û�������***�����������ң�����***����������Ա�б� ---------
			//...
			//-------------------------------------------------------------------------------------
			break;
		}
	}

	//*********** deal with the talking words *******************
	while (1)
	{
		memset(buff, 0, sizeof(buff));

		while (TCPRecv(Client[client_id].Socket, buff) <= 0); //���տͻ�client_id����Ϣ		

		//------- ������Ϣ ---------------------
		//...
		// -------------------------------------

		//----------------------  ������ת�����������߿ͻ� ------------------------------
		for (int i = 0; i<MaxNum; i++)  {

			if (Client[i].num != -1 && Client[i].Socket != INVALID_SOCKET)
			{
				c
			}
		}//end of ת��

		if (!strncmp(buff, "Down", 4))   // the user quit talk 
		{
			printf("%s go down\n", inet_ntoa(Client[client_id].Addr.sin_addr));

			DeleteOne(client_id);  //ɾ����ǰ�û�
			ExitThread(client_id);	//�˳��߳� 			
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
	length = recv(s, data, MaxLength, 0);  //�˴���3������������ sizeof(data)
	if (length <= 0)
		return -1;
	return 1;
}

void DeleteOne(int i)  //ɾ��һ���ͻ�������ռ�õ�socket����ȥ
{
	Client[i].num = -1;

	if (Client[i].Socket != INVALID_SOCKET)
	{
		Client[i].Socket = INVALID_SOCKET;
	}

	//����������
	//...
}

