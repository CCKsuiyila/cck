#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>
//ָ�����ӿ�
#pragma comment (lib,"ws2_32.lib")
//�������˿ں�Ϊ5050
#define DEFAULT_PORT 5050
//�������ݻ���������
#define BUFFER_LENGTH 1024
void main()
{
	int           iPort=DEFAULT_PORT;
	WSADATA       wsaData;
	SOCKET        sSocket;
	//�ͻ���ַ����
	int           iLen;
	//���͵����ݳ���
	int           iSend;
	//���ܵ����ݳ���
	int           iRecv;
	
	//�������ݵĻ�����
	char          recv_buf[BUFFER_LENGTH];
	//�ͻ��˵�ַ
	struct sockaddr_in  ser ,cli;
	//��ʼ��Socket
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		printf("Failed to load winsock.\n");
		system("pause");
			return;
	}
	//�������������׽ӿ�
	sSocket = socket(AF_INET,SOCK_DGRAM,0);
	if(sSocket == INVALID_SOCKET)
	{
		printf("socket() Failed:%d\n" , WSAGetLastError());
		system("pause");
		return;
	}
	//�����������˵�ַ
	ser.sin_family=AF_INET;
	ser.sin_port=htons(DEFAULT_PORT);
	ser.sin_addr.s_addr=inet_addr("172.20.10.5");
	//�󶨵�ַ
	if( bind(sSocket,(const sockaddr*)&ser, sizeof(ser)) == SOCKET_ERROR)
	{
		printf("blid() Failed: %d \n", WSAGetLastError());
		system("pause");
		return;
	}
	//��������ʼ����
	printf(" Server_cck start ...\n\n");
	iLen = sizeof(cli);
	//����һ������ѭ�����ȴ����ܿͻ�������
	while(1)
	{
		//��ʼ�����ܻ�����
		memset(recv_buf,'\0',sizeof(recv_buf));
		//�ӿͻ��˽�������
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
			//������յ�������
			printf("\n-------------------------------------------\n");
			printf(" �ӿͻ����յ�����Ϣ�� : %s\n",recv_buf);
			printf(" �ӿͻ����յ�����Ϣ����Ϊ: %d�ֽ�\n",iRecv);
			//����ͻ���IP��ַ�Ͷ˿ں�
			printf(" Accepted client IP:[%s],port:[%d}\n\n",
				     inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));
		}
		//���ͻ�������Ϣ

		//Ҫ���͸��ͻ�����Ϣ
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
			printf(" ���ӿͻ��˽��ܵ���Ϣת��Ϊ��д,Ȼ�����sendto()�����ٸ��ͻ����ͻ�ȥ\n");
			printf(" sendto() succeeded!(����sendto()�������ͳɹ�)\n");
		}
	}

	closesocket(sSocket);
	WSACleanup();
}