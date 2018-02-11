#include<Winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma comment(lib,"ws2_32.lib")//添加连接库

#define MAX_PACK_LEN 4096//接受的最大ip报文
#define MAX_ADDR_LEN 16//点分十进制地址的最大长度
#define MAX_HOSTNAME_LAN 255//最大主机名长度
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)//i/o控制命令

typedef struct _iphdr  //IP首部
{
	unsigned char h_lenver; //4位IP版本号 + 4位首部长度
	unsigned char tos; //8位服务类型TOS
	unsigned short total_len; //16位总长度 
    unsigned short ident; //16位标识
	unsigned short frag_and_flags; //3位标志位和13位片偏移
	unsigned char ttl; //8位生存时间
    unsigned char proto;//8位协议
	unsigned short checksum; //16位IP首部校验和
	unsigned int sourceIP; //32位源IP地址
	unsigned int destIP; //32位目的IP地址
}IP_HEADER;

typedef struct _icmphdr  //ICMP首部
{
	unsigned char type; //8位类型
	unsigned char code; //8位代码
	unsigned short  checksum; //16位校验和 
}ICMP_HEADER;



//ip解包程序
int DecodeIPPack(char *buf,int iBufSize){
	
	//显示IP头部
	
	//创建包头指针
	IP_HEADER *pIpheader=(IP_HEADER *)buf;
	//显示ip包版本号
	int iIphVer = ((pIpheader->h_lenver)>>4 &0xf);
	//显示ip包头长度
	int iIphLen = sizeof(unsigned long)*(pIpheader->h_lenver &0xf);
	//显示服务类型
	int iIphTos = pIpheader->tos;
	//显示总长度
	int iIphToatl_len = ntohs(pIpheader->total_len);
	//显示标识
	int iIphIdent = ntohs(pIpheader->ident);
	//显示标志
	int iIphFrag = ((pIpheader->frag_and_flags)>>13 &0x7);
	//显示片偏移
	int iIphFlags = ((pIpheader->frag_and_flags &0x1fff));
	//显示生存时间
	int iTTL = pIpheader->ttl;
	//显示上层协议标识
	int iIphProto = pIpheader->proto;
	//显示头部检验和
	int iIphChecksum = ntohs(pIpheader->checksum);
	//显示源ip,目的ip
	char szSourceIP[MAX_ADDR_LEN],szDestIP[MAX_ADDR_LEN];
	SOCKADDR_IN saSource,saDest;
	//获取源ip地址
	saSource.sin_addr.s_addr=pIpheader->sourceIP;
	//得到点分十进制字符串形式的ip地址
	strncpy(szSourceIP,inet_ntoa(saSource.sin_addr),MAX_ADDR_LEN);
	//获取目标IP地址
	saDest.sin_addr.s_addr=pIpheader->destIP;
	//得到点分十进制字符串形式的IP地址
	strncpy(szDestIP,inet_ntoa(saDest.sin_addr),MAX_ADDR_LEN);
	
	
	if(iIphProto==1){
		
		static int count_check = 1;
		static int count_reply = 1;
		//显示ICMP头部
	
		//创建包头指针
		ICMP_HEADER *pIcmpheader=(ICMP_HEADER *)(buf+iIphLen);
		//显示类型
		int type = pIcmpheader->type;
		//显示代码
		int code = pIcmpheader->code;

		//存放主机名称
		char hostname[256];
		gethostname(hostname,sizeof(hostname));
		//主机信息指针
		hostent *pHostent1;
		struct sockaddr_in sa1;
		int n;
		pHostent1 = gethostbyname(hostname);
		for(n=0; pHostent1->h_addr_list[n]; n++){
			memcpy(&sa1.sin_addr.s_addr, pHostent1->h_addr_list[n], pHostent1->h_length);
			//printf("Address: %s\n", inet_ntoa(sa1.sin_addr));
		}
		//
		//
		if(type==8&&code==0/*&&szDestIP==inet_ntoa(sa1.sin_addr)*/){
			printf("类型: 探测本机的icmp包 第 %d 个\n",count_check);
			printf("源地址: %s\n",szSourceIP);
			printf("目的地址: %s\n\n",szDestIP);
			++count_check;
		}else if(type==0&&code==0/*&&szSourceIP==inet_ntoa(sa1.sin_addr)*/){
			printf("类型:本机应答的icmp包 第 %d 个\n",count_reply);
			printf("源地址: %s\n",szSourceIP);
			printf("目的地址: %s\n\n",szDestIP);
			++count_reply;

		}

	}

	//------------------------
	return 0;
}

SOCKET SockRaw;
//sock错误处理程序
void CheckSockError(int iErrorCode, char *pErrorMsg){
	if(iErrorCode==SOCKET_ERROR){
		printf("%s Error:%d\n", pErrorMsg, GetLastError());
		closesocket(SockRaw);
		exit(0);
	}
}



void main(int argc,char ** argv){


	int iErrorCode;
	char RecvBuf[MAX_PACK_LEN]={0};
	WSADATA wsaData;
	char name[MAX_HOSTNAME_LAN];
	struct hostent * pHostent;
	SOCKADDR_IN sa;
	DWORD dwBufferLen [10];
	DWORD dwBufferInLen=1;
	DWORD dwBytesReturned=0;

	printf("---- Now sniffing pass,CTRL+C to exit...\n\n");
	//
	iErrorCode=WSAStartup(0x0202,&wsaData);
	CheckSockError(iErrorCode,"WSAStartup");
	SockRaw=socket(AF_INET,SOCK_RAW,IPPROTO_IP);
	CheckSockError(SockRaw,"socket");

	iErrorCode=gethostname(name,MAX_HOSTNAME_LAN);
	CheckSockError(iErrorCode,"gethostname");
	pHostent=(struct hostent *)malloc(sizeof(struct hostent));
	pHostent=gethostbyname(name);
	sa.sin_family=AF_INET;
	sa.sin_port=htons(6000);
	memcpy(&sa.sin_addr.S_un.S_addr,pHostent->h_addr_list[0],pHostent->h_length);
	//绑定套接字
	iErrorCode=bind(SockRaw,(PSOCKADDR)&sa,sizeof(sa));
	CheckSockError(iErrorCode,"bind");
	//将网卡的接受模式设置为混杂模式（设置SOCK_RAW为SIO_RCVALL）,以便接受所有的ip1包
	iErrorCode=WSAIoctl(SockRaw,SIO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),
		&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL);
	CheckSockError(iErrorCode,"Ioctl");

	//存放主机名称
	char hostname[256];
	gethostname(hostname,sizeof(hostname));
	printf("本机名: %s\n", hostname);
	
	//主机信息指针
	hostent *pHostent1;
	struct sockaddr_in sa1;
	int n;
	pHostent1 = gethostbyname(hostname);
	for(n=0; pHostent1->h_addr_list[n]; n++){
		memcpy(&sa1.sin_addr.s_addr, pHostent1->h_addr_list[n], pHostent1->h_length);
		printf("Address: %s\n", inet_ntoa(sa1.sin_addr));
	}
	
	while(1)
	{
		memset(RecvBuf,0,sizeof(RecvBuf));
		iErrorCode=recv(SockRaw,RecvBuf,sizeof(RecvBuf),0);
		CheckSockError(iErrorCode,"recv");
		iErrorCode=DecodeIPPack(RecvBuf,iErrorCode);//对收到的ip包进行解包
		CheckSockError(iErrorCode,"Decode");
	}
}



























