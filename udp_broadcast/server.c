/**************************************************************************************************************
 **�ļ�:server.c
 **��д��:huangminqiang
 **��д����:2012��11��5��
 **��Ҫ����:�㲥������
 **�޸���:
 **�޸�����:
 **ע:
 **************************************************************************************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdio.h>

#define PORT            8888            // �˿ں�
#define IP_FOUND        "IP_FOUND"      // IP��������
#define IP_FOUND_ACK    "IP_FOUND_ACK"  // IP����Ӧ������

/***** �����������㲥 *******************************************************************************************/
int ServerListenBroadcast(void)
{
    int ret = -1;
    int sock = -1;
    int len = -1;
    char buf[20];
    fd_set readfd;
    struct timeval timeout;
    struct sockaddr_in local_addr;      // ���ص�ַ
    struct sockaddr_in from_addr;       // �ͻ��˵�ַ

    //socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(0 > sock)
    {
        perror("client socket err");
        return -1;
    }

    //init local_addr
    len = sizeof(struct sockaddr_in);
    memset(&local_addr, 0, sizeof(struct sockaddr_in)); // ����ڴ�����
    local_addr.sin_family = AF_INET;                    // Э����
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);     // ���ص�ַ
    local_addr.sin_port = htons(PORT);                  // �����˿�

    //bind
    ret = bind(sock, (struct sockaddr *)&local_addr, sizeof(struct sockaddr_in));
    if(0 > ret)
    {
        perror("server1 bind err");
        goto _out;
    }

    while(1)
    {
        // �ļ���������������
        FD_ZERO(&readfd);
        // ���׽����ļ����������������
        FD_SET(sock, &readfd);

        // ��ʱʱ��
        timeout.tv_sec = 2;  // ��
        timeout.tv_usec = 0; // ΢��

        // �����׽���sock�Ƿ������ݿɶ�����ʱΪ2��
        ret = select(sock + 1, &readfd, NULL, NULL, &timeout);
        switch(ret)
        {
            case -1:
                printf("select error!\n");
                goto _out;
            case 0:
                printf("time out!\n");
                break;
            default:
                {
                    // sock�׽ӿ������ݿɶ�
                    if( FD_ISSET(sock, &readfd) )
                    {
                        // recieve
                        ret = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, &len);
                        if(0 > ret)
                        {
                            perror("server recieve err");
                            goto _out;
                        }
                        printf("buf : %s\n", buf);

                        // �����IP_FOUND�Ǻ�
                        if( strstr(buf, IP_FOUND) )
                        {
                            // send
                            ret = sendto(sock, IP_FOUND_ACK, strlen(IP_FOUND_ACK) + 1, 0, (struct sockaddr *)&from_addr, len);
                            if(0 > ret)
                            {
                                perror("server send err");
                                goto _out;
                            }
                            printf("IP is %s\n", inet_ntoa(from_addr.sin_addr));
                            goto _out;  // �˳�
                        }

                    }

                }
        }
    }

    // close
    close(sock);
    return 0;
_out:
    close(sock);
    return -1;
}


/***** ������ ****************************************************************************************************/
int main(void)
{
    if(ServerListenBroadcast())
    {
        printf(" server listen broadcast failed!\n");
        return -1;
    }
    return 0;
}
