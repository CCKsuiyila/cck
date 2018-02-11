#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>
//指定链接库
#pragma comment (lib,"ws2_32.lib")
//服务器端口号为5050
#define DEFAULT_PORT 5050
//接收数据缓冲区长度
#define BUFFER_LENGTH 1024
void main()
{
	int           iPort=DEFAULT_PORT;
	WSADATA       wsaData;
	SOCKET        sSocket;
	//客户地址长度
	int           iLen;
	//发送的数据长度
	int           iSend;
	//接受的数据长度
	int           iRecv;
	
	//接收数据的缓冲区
	char          recv_buf[BUFFER_LENGTH];
	//客户端地址
	struct sockaddr_in  ser ,cli;
	//初始化Socket
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		printf("Failed to load winsock.\n");
		system("pause");
			return;
	}
	//产生服务器端套接口
	sSocket = socket(AF_INET,SOCK_DGRAM,0);
	if(sSocket == INVALID_SOCKET)
	{
		printf("socket() Failed:%d\n" , WSAGetLastError());
		system("pause");
		return;
	}
	//建立服务器端地址
	ser.sin_family=AF_INET;
	ser.sin_port=htons(DEFAULT_PORT);
	ser.sin_addr.s_addr=inet_addr("172.20.10.5");
	//绑定地址
	if( bind(sSocket,(const sockaddr*)&ser, sizeof(ser)) == SOCKET_ERROR)
	{
		printf("blid() Failed: %d \n", WSAGetLastError());
		system("pause");
		return;
	}
	//服务器开始运行
	printf(" Server_cck start ...\n\n");
	iLen = sizeof(cli);
	//进入一个无限循环，等待接受客户端数据
	while(1)
	{
		//初始化接受缓冲区
		memset(recv_buf,'\0',sizeof(recv_buf));
		//从客户端接收数据
		iRecv=recvfrom(sSocket,recv_buf,BUFFER_LENGTH,0,(SOCKADDR*)&cli,&iLen);
		if(iRecv ==SOCKET_ERROR)
		{
			printf("recvfrom() Failed :%d \n", WSAGetLastError());
			continue;
		}
		else    if(iRecv==0)
			continue;
		else
		{
			//输出接收到的数据
			printf("\n-------------------------------------------\n");
			printf(" 从客户端收到的信息是 : %s\n",recv_buf);
			printf(" 从客户端收到的信息长度为: %d字节\n",iRecv);
			//输出客户端IP地址和端口号
			printf(" Accepted client IP:[%s],port:[%d}\n\n",
				     inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));
		}
		//给客户发送信息

		//要发送给客户的信息
		char   send_buf[BUFFER_LENGTH];

		for(int i = 0; i<strlen(recv_buf); ++i){
			send_buf[i] = recv_buf[i]-32;
		}
		send_buf[strlen(recv_buf)]='\0';
		iSend=sendto(sSocket,send_buf,strlen(send_buf)+1,0,
			(SOCKADDR*)&cli,sizeof(cli));
		if(iSend == SOCKET_ERROR)
		{
			printf(" sendto() Failed.:%d\n",   WSAGetLastError());
		}
		else   if(iSend==0)
		{    }
		else
		{
			printf(" 将从客户端接受的信息转换为大写,然后调用sendto()函数再给客户发送回去\n");
			printf(" sendto() succeeded!(调用sendto()函数发送成功)\n");
		}
	}

	closesocket(sSocket);
	WSACleanup();
}