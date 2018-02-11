/*-----------------UDP客户端------------------------------------
------------接受UDP服务器的广播并显示广播信息
------------如果是“点名”命令，则回传自己的学号和姓名--------*/

#include "Winsock2.h"
#include "stdio.h"
#include "string.h"
#pragma comment(lib,"wsock32.lib")

#define SEND_PORT 3000     //发送端口
#define RECV_PORT 3001     //接收端口

SOCKET sock;
sockaddr_in ServerAddr;     //服务器地址
sockaddr_in ClientAddr;     //客户端（本地）地址

void main()
{
	int n;
	//-----------------------初始化套接字----------------------
	WSADATA WSAData;
	if(WSAStartup(MAKEWORD(2,2), &WSAData)!=0)
	{
		printf("socket init fail!\n");
		system("pause");
		return;
	}

	//----------------------创建用于收发的套接字------------------
	sock=socket(AF_INET,SOCK_DGRAM,0);
	if(sock==SOCKET_ERROR)
	{
		printf("socket create fail!\n");
		WSACleanup();
		system("pause");
		return;
	}

	//---------------设置客户端（本地）地址---------------------
	memset(&ClientAddr,0,sizeof(ClientAddr));
	ClientAddr.sin_family=AF_INET;
	ClientAddr.sin_addr.s_addr=inet_addr("10.0.6.25");// INADDR_ANY；
    ClientAddr.sin_port=htons(RECV_PORT);

	//----------------绑定套接字到本地址-------------------------
	n=bind(sock,(struct sockaddr*)&ClientAddr,sizeof(ClientAddr));
    if(n==SOCKET_ERROR)
	{
		printf("Bind error!\n");
		system("pause");
		return;
	}
	else
	{
		printf("Bind Address ok! \n");
	}

	//----------------在指定端口侦听，并接受服务器广播的信息-------------
	char buf[1024]="\0";
	int len;
	printf("Bengin receiving datas... \n");
	while(1) //无限循环侦听
	{
		memset(&buf,'\0',sizeof(buf));  //清空接收缓存区
		memset(&ServerAddr,0,sizeof(ServerAddr));  //清空地址空间
		len=sizeof(ServerAddr);

		//接受服务器广播信息
		n=recvfrom(sock,buf,sizeof(buf),0,(struct sockaddr*)&ServerAddr,(int *)&len);

		if(n==SOCKET_ERROR)
		{
			printf("\n  Get BROADCAST Data error! \n");
			printf("\n  The error code: %d \n",WSAGetLastError());
		}
		else
		{
          //---------收到广播信息，则显示---------------------------
		  printf("\n Get BROADCAST Data:\"%s\n", buf,inet_ntoa(ServerAddr.sin_addr));

		  if( strcmp(buf,"/name") >=0)  //如果是"点名"命令
		  {
		  //------------设置服务器地址，准备回传--------------------
		  ServerAddr.sin_family=AF_INET;
		  ServerAddr.sin_addr.s_addr=inet_addr("10.0.6.25");
		  ServerAddr.sin_port = htons(SEND_PORT);

		  //------------回传自己的学号和姓名------------------------
		  memset(&buf,'\0',sizeof(buf));
		  strcpy(buf,"20151681310210 崔晨凯");
		  n=sendto(sock,buf,strlen(buf)+1,0,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));
          if(n==SOCKET_ERROR)
		  {
			  printf(" Send back my name false!\n");
		  }
		  else if(n==0)
		  {
			  printf(" Send back my name false 0 \n!");
		  }
		  else if(n!=SOCKET_ERROR)
		  {
			  printf(" Send back my name success!\n");
		  }
		  }
		}

		Sleep(1000);
	}

	getchar();
	closesocket(sock);
	WSACleanup();
}
   
