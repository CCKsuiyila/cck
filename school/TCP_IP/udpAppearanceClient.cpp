/*-----------------UDP�ͻ���------------------------------------
------------����UDP�������Ĺ㲥����ʾ�㲥��Ϣ
------------����ǡ������������ش��Լ���ѧ�ź�����--------*/

#include "Winsock2.h"
#include "stdio.h"
#include "string.h"
#pragma comment(lib,"wsock32.lib")

#define SEND_PORT 3000     //���Ͷ˿�
#define RECV_PORT 3001     //���ն˿�

SOCKET sock;
sockaddr_in ServerAddr;     //��������ַ
sockaddr_in ClientAddr;     //�ͻ��ˣ����أ���ַ

void main()
{
	int n;
	//-----------------------��ʼ���׽���----------------------
	WSADATA WSAData;
	if(WSAStartup(MAKEWORD(2,2), &WSAData)!=0)
	{
		printf("socket init fail!\n");
		system("pause");
		return;
	}

	//----------------------���������շ����׽���------------------
	sock=socket(AF_INET,SOCK_DGRAM,0);
	if(sock==SOCKET_ERROR)
	{
		printf("socket create fail!\n");
		WSACleanup();
		system("pause");
		return;
	}

	//---------------���ÿͻ��ˣ����أ���ַ---------------------
	memset(&ClientAddr,0,sizeof(ClientAddr));
	ClientAddr.sin_family=AF_INET;
	ClientAddr.sin_addr.s_addr=inet_addr("10.0.6.25");// INADDR_ANY��
    ClientAddr.sin_port=htons(RECV_PORT);

	//----------------���׽��ֵ�����ַ-------------------------
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

	//----------------��ָ���˿������������ܷ������㲥����Ϣ-------------
	char buf[1024]="\0";
	int len;
	printf("Bengin receiving datas... \n");
	while(1) //����ѭ������
	{
		memset(&buf,'\0',sizeof(buf));  //��ս��ջ�����
		memset(&ServerAddr,0,sizeof(ServerAddr));  //��յ�ַ�ռ�
		len=sizeof(ServerAddr);

		//���ܷ������㲥��Ϣ
		n=recvfrom(sock,buf,sizeof(buf),0,(struct sockaddr*)&ServerAddr,(int *)&len);

		if(n==SOCKET_ERROR)
		{
			printf("\n  Get BROADCAST Data error! \n");
			printf("\n  The error code: %d \n",WSAGetLastError());
		}
		else
		{
          //---------�յ��㲥��Ϣ������ʾ---------------------------
		  printf("\n Get BROADCAST Data:\"%s\n", buf,inet_ntoa(ServerAddr.sin_addr));

		  if( strcmp(buf,"/name") >=0)  //�����"����"����
		  {
		  //------------���÷�������ַ��׼���ش�--------------------
		  ServerAddr.sin_family=AF_INET;
		  ServerAddr.sin_addr.s_addr=inet_addr("10.0.6.25");
		  ServerAddr.sin_port = htons(SEND_PORT);

		  //------------�ش��Լ���ѧ�ź�����------------------------
		  memset(&buf,'\0',sizeof(buf));
		  strcpy(buf,"20151681310210 �޳���");
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
   
