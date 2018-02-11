#include "winsock2.h"
#include "stdio.h"
#pragma comment (lib, "ws2_32.lib") //制定链接库

void main(){
	//step1:初始化winsock
	WSAData wsa;
	WSAStartup(WINSOCK_VERSION,&wsa);

	//
	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
	if(ServerSocket ==  INVALID_SOCKET){
		printf("Creating Socket error!");
		system("pause");
		return;
	}
	struct sockaddr_in ServerAddr;
	memset(&ServerAddr,0,sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("172.20.10.5");//
	ServerAddr.sin_port = htons(5005);

	//
	if(bind(ServerSocket,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr))){
		printf("Binding error!");
		closesocket(ServerSocket);
		WSACleanup();
		system("pause");
		return;
	}

	//
	if(listen(ServerSocket,5)==SOCKET_ERROR){
		printf("Listeming error!");
		closesocket(ServerSocket);
		WSACleanup();
		system("pause");
		return;
	}else{
		printf("Server start...\n");
	}

	//
	while(1){
		SOCKET SocketClient;
		struct sockaddr_in from;
		int len = sizeof(from);
		SocketClient = accept(ServerSocket,(struct sockaddr*)&from,&len);//
		if(SocketClient != INVALID_SOCKET){
			printf("远程主机:%s 通过端口: %d 连接到服务器...\n", inet_ntoa(from.sin_addr),ntohs(from.sin_port));
			//
			
			
			char buf[1924],sendData[1024] = {"请输入你的账号和密码 "};
			
	
			
			len = strlen(sendData);
			sendData[len] = '\0';//
			if(send(SocketClient,sendData,strlen(sendData)+1,0)!=SOCKET_ERROR){
				printf(" send %s to client successful \n",sendData);
			}

			//
			if(recv(SocketClient,buf,sizeof(buf),0) >0){
				printf(" receive data from client: %s \n",buf);
			}
			if(closesocket(SocketClient)!=SOCKET_ERROR){
				printf(" close client Socket successful \n\n");
			}
		}
	}
}
