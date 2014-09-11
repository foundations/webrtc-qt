// PHGlobal.h: interface for the CBaseThread class.
//
//////////////////////////////////////////////////////////////////////
/* ! \file PHGlobal.h
*  \author skyvense
*  \date   2009-09-14
*  \brief PHDDNS �ͻ���ʵ��
*/

#ifndef __PHGLOBAL__H__
#define __PHGLOBAL__H__
#ifndef WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>
#endif

#ifdef WIN32
#define sleep(x) Sleep(x*1000)
#else
#define INVALID_SOCKET1 (-1)
#define MAX_PATH	260
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define	FALSE	0
#endif

#define MAX_TCP_PACKET_LEN	8192

// ! �ͻ���״̬
enum MessageCodes
{
    okConnected = 0,
    okAuthpassed,
    okDomainListed,
    okDomainsRegistered,
    okKeepAliveRecved,
    okConnecting,
    okRetrievingMisc,
    okRedirecting,

    errorConnectFailed = 0x100,
    errorSocketInitialFailed,
    errorAuthFailed,
    errorDomainListFailed,
    errorDomainRegisterFailed,
    errorUpdateTimeout,
    errorKeepAliveError,
    errorRetrying,
    errorAuthBusy,
    errorStatDetailInfoFailed,


    okNormal = 0x120,
    okNoData,
    okServerER,
    errorOccupyReconnect,
};

// ! TCPָ���
#define COMMAND_AUTH	"auth router6\r\n"
#define COMMAND_REGI    "regi a"
#define COMMAND_CNFM    "cnfm\r\n"
#define COMMAND_STAT_USER    "stat user\r\n"
#define COMMAND_STAT_DOM     "stat domain\r\n"
#define COMMAND_QUIT    "quit\r\n"

// ! ����������ָ��
#define UDP_OPCODE_UPDATE_VER2		0x2010
// ! ��������������������
#define UDP_OPCODE_UPDATE_OK		0x2050
// ! ���������������ش���
#define UDP_OPCODE_UPDATE_ERROR		1000

// ! ������ע����¼
#define UDP_OPCODE_LOGOUT			11

// ! ���������ܲ��ִ�С
#define KEEPALIVE_PACKET_LEN	20

// ! ת��״̬�뵽�ı���
extern const char *convert_status_code(int nCode);

// ! ת��IP��ַ���ı���
//extern const char *my_inet_ntoa(long ip);

// ! �������ṹ
typedef struct
{
    // ! �Ի�ID
    long lChatID;
    // ! ������
    long lOpCode;
    // ! ��ID
    long lID;
    // ! У���
    long lSum;
    // ! ������
    long lReserved;
} DATA_KEEPALIVE;

// ! ���°���չ�ṹ�����ڷ���������ʱIP��ַ
typedef struct
{
    DATA_KEEPALIVE keepalive;
    long ip;
} DATA_KEEPALIVE_EXT;

typedef void (*CALLBACK_OnStatusChanged)(int status, long data);
// ! �˺����õ�ע���������ÿ��������ִ��һ��
typedef void (*CALLBACK_OnDomainRegistered)(char *domainName);
// ! �˺����õ��û���Ϣ��XML��ʽ
typedef void (*CALLBACK_OnUserInfo)(char *userInfo, int length);
// ! �˺����õ��û�������Ϣ��XML��ʽ
typedef void (*CALLBACK_OnAccountDomainInfo)(char *domainInfo, int length);


// ! ȫ�ֱ���
typedef struct
{
//basic system info
    // ! Ƕ��ʽ�ͻ�����Ϣ��4λ�ͻ���ID + 4λ�汾��
    long clientinfo;
    // ! Ƕ��ʽ��֤��
    long challengekey;

    // ! ��������ַ
    char szHost[256];
    // ! �������˿ڣ�6060�̶�
    short nPort;
    // ! �û��˺���
    char szUserID[256];
    // ! �û���������
    char szUserPWD[256];
    // ! ���ذ󶨵�ַ��Ĭ����գ����ڶ������ʱָ������
    char szBindAddress[256];
//run-time controll variables
    // ! �û�����
    int nUserType;
    unsigned int bTcpUpdateSuccessed;
    char szChallenge[256];
    int nChallengeLen;
    int nChatID,nStartID,nLastResponseID;
    long tmLastResponse;
    int nAddressIndex;
    char szTcpConnectAddress[32];

    int cLastResult;
    unsigned long ip;

    long uptime;
    long lasttcptime;

    char szActiveDomains[255][255];

    // ! ��ǰ�Ƿ���Ҫ����TCP����
    unsigned int bNeed_connect;
    // ! ���һ�η�����������ʱ��
    long tmLastSend;
    // �ʺŵ�¼״̬
    char bStatue;
    int m_tcpsocket,m_udpsocket;

    CALLBACK_OnStatusChanged cbOnStatusChanged;
    CALLBACK_OnDomainRegistered cbOnDomainRegistered;
    CALLBACK_OnUserInfo cbOnUserInfo;
    CALLBACK_OnAccountDomainInfo cbOnAccountDomainInfo;
} PHGlobal;
extern void init_global(PHGlobal *global);
extern void set_default_callback(PHGlobal *global);

#endif