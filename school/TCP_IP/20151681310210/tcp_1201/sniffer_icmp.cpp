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
	
	
	if(iIphProto==1){
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



























