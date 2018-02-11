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
	printf("请输入你想发送给服务器的一串小写英文字符(不要超过1024个字符): ");
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
			printf(" 调用sendto()函数给服务器发送的信息是: %s\n",send_buf);
			printf(" 调用sendto()函数给服务器发送的信息长度是: %d字节\n",iSend);
			printf(" sendto() succeeded.(调用sendto()函数发送信息成功)\n\n");
			
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
		printf(" 调用recvfrom()函数从服务器接收到的信息是:%s\n",recv_buf);
		printf("-----------------------------------\n");
	}
	closesocket(sClient);
	WSACleanup();
	system("pause");
}

