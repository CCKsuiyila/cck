
#include"Winsock.h"
#include"windows.h"
#include"stdio.h"
#include "string.h"
#include"iostream"
using namespace std;

#pragma comment(lib,"wsock32.lib")


SOCKET sock;
sockaddr_in ServerAddr;
#define RECV_PORT 5012

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
	ServerAddr.sin_addr.s_addr = inet_addr("172.20.10.5");
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


DWORD ConnetProcess()
{
	char buff[100], temp[100];
	//DWORD ExitCode=0;

	memset(buff, 0, sizeof(buff));

	//******** deal with the recieve message from sever *********************
	while (1)
	{
		memset(buff, 0, sizeof(buff));
		memset(temp, 0, sizeof(temp));
		//TCPRecv(buff);
		recv(sock, buff, sizeof(buff), 0); // ������Ϣ

		if (strlen(buff) <= 0) continue;
		printf("\n");
		printf("%s\n", buff);
		
	}//end of while(1)
}

int main(){
	
	char buff[100];
	HANDLE HdTread;
	DWORD ThreadId;
	DWORD ExitCode = 0;
	
	
	//************ create socket and connect to the sever ******************************
	if (StartSock() == -1) return -1;
	if (CreateSocket() == -1) return -1;
	while (CallServer() == -1);
	
	//��¼������
	while(1){  
		printf("������(talker:������)(������������5��Ӣ����ĸ)Ȼ�����س���: ");
		char data[50];
		memset(data,'\0',sizeof(data));
		scanf("%s",&data);

		char buf[1024];
		memset(buf,'\0',sizeof(buf));
		if(send(sock,data,strlen(data)+1,0)!= SOCKET_ERROR){
			if(recv(sock,buf,sizeof(buf),0)>0){
				if(!strncmp(buf,"The name",8)){    // the name has been used
					printf("%s\n",buf);
					continue;
				}else{
					if(!strncmp(buf,"��ӭ",4)){    // the name has been used
						printf("%s\n",buf);
					}
					break;
				}
			}
		}else{
			printf("send fail\n");
		}
	}
	
	//���������߳�
	HdTread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnetProcess, NULL, 0, &ThreadId);
	Sleep(1000);

	//������Ϣ
	//****** Get information from keyboard ******************************
	while (1)
	{
		Sleep(100);
		
		memset(buff, 0, sizeof(buff));
		cin.getline(buff, sizeof(buff), '\n'); //��ȡ�û�����
		//gets(buff); //��ȡ�û�����

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
			return;
		}

		TCPSend(buff);

	}	//end of while(1)
		
	
	
	if(sock !=INVALID_SOCKET){
		closesocket(sock);
	}
	WSACleanup();
	
}


