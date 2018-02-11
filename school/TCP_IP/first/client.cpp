
#include"winsock2.h"
#include"stdio.h"
#pragma comment(lib, "ws2_32.lib")
void main()
{
	WSAData wsa;
	WSAStartup(WINSOCK_VERSION,&wsa);
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
	if(ClientSocket==INVALID_SOCKET){
		printf("Creating Socket error!");
		system("pause");
		return;
	}
	struct sockaddr_in ServerAddr;
	memset(&ServerAddr,0,sizeof(ServerAddr));
	ServerAddr.sin_family=AF_INET;
	ServerAddr.sin_addr.s_addr=inet_addr("172.20.10.5");
	ServerAddr.sin_port = htons(5000);
	if(connect(ClientSocket,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR){
		printf("connect error!");
		closesocket(ClientSocket);
		WSACleanup();
		system("pause");
		return;
	}else{
		printf("connect to server:%s successfull \n",inet_ntoa(ServerAddr.sin_addr));
	}
	char buf[1024]="\0";
	if(recv(ClientSocket,buf,sizeof(buf),0)>0){
		printf("receive data from server:%s \n",buf);
	}
	
	//printf("请输入你想发送给服务器的一串小写英文字符(不要超过1024个字符):");
	char data[1024];
	scanf("%s",data);
	
	int len=strlen(data);
	data[len]='\0';
	if(send(ClientSocket,data,strlen(data)+1,0)== SOCKET_ERROR){
		printf("send hello to server error");
	}else{
		printf("send user and password to server successful \n");
	}
	if(ClientSocket !=INVALID_SOCKET){
		closesocket(ClientSocket);
	}
	WSACleanup();
	system("pause");
}
