#include<WinSock2.h>
#include<stdio.h>
//
#pragma comment(lib,"ws2_32.lib")
//

#define Ser_PORT 5050
//
#define DATA_BUFFER 1024

void main(){
	WSADATA wsaData;
	SOCKET sClient;
	//
	int iLen;
	//
	int iSend;
	int iRecv;
	//
	printf("���������뷢�͸���������һ��СдӢ���ַ�(��Ҫ����1024���ַ�): ");
	char send_buf[DATA_BUFFER];
	scanf("%s",send_buf);
	//
	char recv_buf[DATA_BUFFER];
	//
	struct sockaddr_in ser;
	//
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
		printf("Failed to load Winsock.\n");
		system("pause");
		return;
	}
	sClient = socket(AF_INET,SOCK_DGRAM,0);
	if(sClient==INVALID_SOCKET){
		printf("socket()Failed:%d\n",WSAGetLastError());
		system("pause");  
		return;
	}
	//
	ser.sin_family=AF_INET;
	ser.sin_port = htons(Ser_PORT);
	ser.sin_addr.s_addr = inet_addr("172.20.10.5");
	iLen=sizeof(ser);
	//
	iSend = sendto(sClient,send_buf,strlen(send_buf)+1,0,(struct sockaddr*)&ser,iLen);
	if(iSend==SOCKET_ERROR){
		printf("sendto()Failed:%d\n",WSAGetLastError());
		system("pause");
		return;
	}else{
		if(iSend==0){
			system("pause");
			return;
		}else{
			printf("\n-----------------------------------\n");
			printf(" ����sendto()���������������͵���Ϣ��: %s\n",send_buf);
			printf(" ����sendto()���������������͵���Ϣ������: %d�ֽ�\n",iSend);
			printf(" sendto() succeeded.(����sendto()����������Ϣ�ɹ�)\n\n");
			
		}
	}
	//
	memset(recv_buf,'\0',sizeof(recv_buf));
	//
	iRecv = recvfrom(sClient,recv_buf,sizeof(recv_buf),0,(struct sockaddr*)&ser,&iLen);
	if(iRecv==SOCKET_ERROR){
		printf("recvfrom()Failed.:%d\n",WSAGetLastError());
		system("pause");
		return;
	}else if(iRecv==0){
		system("pause");
		return;
	}else{
		//
		printf(" ����recvfrom()�����ӷ��������յ�����Ϣ��:%s\n",recv_buf);
		printf("-----------------------------------\n");
	}
	closesocket(sClient);
	WSACleanup();
	system("pause");
}

