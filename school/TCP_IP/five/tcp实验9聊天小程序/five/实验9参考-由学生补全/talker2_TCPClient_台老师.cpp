
#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#include "string.h"
#include"iostream"
using namespace std;

#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 5001

SOCKET sock;
sockaddr_in ServerAddr;
int HaveLogin = 0;
char name[20];

DWORD StartSock()
{
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
	{
		printf("socket init Failed:%d\n", WSAGetLastError());
		getchar();
		return -1;
	}
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("10.0.6.50");
	ServerAddr.sin_port = htons(RECV_PORT);
	return 1;
}

DWORD CreateSocket()
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == SOCKET_ERROR)
	{
		printf("socket create  Failed:%d\n", WSAGetLastError());
		getchar();
		WSACleanup();
		return -1;
	}
	return 1;
}

DWORD CallServer()
{

	if (connect(sock, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		printf("connect  Failed:%d\n", WSAGetLastError());
		Sleep(1000);
		closesocket(sock);
		return -1;
	}
	return 1;
}

DWORD TCPSend(char data[])
{
	int length;
	length = send(sock, data, strlen(data) + 1, 0);
	if (length <= 0)
	{
		printf("send data Failed:%d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
		return -1;
	}
	return 1;
}

DWORD TCPRecv(char data[])
{
	int length;
	length = recv(sock, data, sizeof(data), 0);
	if (length <= 0)
	{
		//printf("Recieve data error.\n");		
		//closesocket(sock);
		//WSACleanup();
		return -1;
	}
	return 1;
}

void Welcome()
{

	printf("*********************  欢迎来到椰岛绿洲聊天室  *************************\n");

	//************ print the usage of how to sent message ************************
	printf("**********************************************************************\n");
	printf("           The Method that you send a message:\n");
	printf("                      Your_words\n");
	printf("                  Or  //(all)   your_words\n");
	printf("                  Or  //(name)  your_words\n");
	printf("                  Or  //{name}  your_words -----means private talk. \n");
	printf("**********************************************************************\n");
}

DWORD ConnetProcess()
{
	char buff[100], temp[100];
	char *pt, *ptend;
	//DWORD ExitCode=0;

	memset(buff, 0, sizeof(buff));
	TCPSend(name);
	HaveLogin = 1;

	//******** deal with the recieve message from sever *********************
	while (1)
	{
		memset(buff, 0, sizeof(buff));
		memset(temp, 0, sizeof(temp));
		//TCPRecv(buff);
		recv(sock, buff, sizeof(buff), 0); // 接收消息

		if (strlen(buff) <= 0) continue;

		
		//****** Recieve the messages, and deal them  **************
                  //...
		   printf("%s\n", buff);
                  //...
                //***********************************

	}//end of while(1)
}

int  main(int argc, char * argv[])
{
	char buff[100], *pt;
	bool HaveChoose = false;
	HANDLE HdTread;
	DWORD ThreadId;
	DWORD ExitCode = 0;

	//************** get the initial login name **************************************	
	if (argc<2)
	{
		printf("Parameters error![talker name]\n");
		getchar();
		return 0;
	}

	memset(name, 0, sizeof(buff));
	strcpy(name, argv[1]);
	if (argc>2)
	{
		strcat(name, "  "); strcat(name, argv[2]);
	}
	if (strlen(name) >= 10)  //the max lenght of name is 10
	{
		pt = name;
		*(pt + 10) = '\0';
	}

	////strcpy(name, "Tom222");//测试用户

	//************ create socket and connect to the sever ******************************
	if (StartSock() == -1) return -1;
	if (CreateSocket() == -1) return -1;
	while (CallServer() == -1);

	Welcome();
	printf("your name is:%s\n", name);

	//*********** create thread *************************************************
	HdTread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnetProcess, NULL, 0, &ThreadId);
	Sleep(1000);

	//****** Get information from keyboard ******************************
	while (1)
	{
		Sleep(100);
		if (!HaveLogin) continue; 
		
		memset(buff, 0, sizeof(buff));
		cin.getline(buff, sizeof(buff), '\n'); //获取用户输入
		//gets(buff); //获取用户输入

		if (strlen(buff) <= 0) continue;
		strcat(buff, "\0");

		if (!strncmp(buff, "quit", 4))  //terminate
		{
			if (sock != INVALID_SOCKET)
			{
				TCPSend("Down");
				TerminateThread(HdTread, ExitCode);
				closesocket(sock);
			}
			return 0;
		}

		if (strncmp(buff, "//", 2))  // not beginning of "//"
		{
			//if(HaveChoose)
			TCPSend(buff);
			//else
			//	printf("You Haven't choose a target[//all Or //(wang) Or//{wang} ] !\n");
		}
		else
		{
			//**************其它情况************************************
                           //...
				printf("You Haven't choose a target[//all Or //(wang) Or//{wang} ] !\n");

                       //**************其它情况************************************

			//end of else
		}//end of if(strncmp())

	}	//end of while(1)

	return 0;
}