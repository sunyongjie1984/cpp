/**************************************************************************************************************
 **文件:client.c
 **编写者:huangminqiang
 **编写日期:2012年11月5号
 **简要描述:广播客户端
 **修改者:
 **修改日期:
 **注:
 **************************************************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define PORT            8888            // 端口号
#define IP_FOUND        "IP_FOUND"      // IP发现命令
#define IP_FOUND_ACK    "IP_FOUND_ACK"  // IP发现应答命令
#define IFNAME          "eth0"          // 网卡名字

/***** 获取本地Mac地址 ******************************************************************************************/
int GetLocalMac(int sock, unsigned char *vmac)
{
    struct sockaddr sa;
    struct ifreq ifr;
    unsigned char mac[6];

    strncpy(ifr.ifr_name, IFNAME, IFNAMSIZ);
    ifr.ifr_name[IFNAMSIZ - 1] = 0;
    //获取Mac地址
    memset(mac, 0, sizeof(mac));
    if (0 > ioctl(sock, SIOCGIFHWADDR, &ifr))
    {
        perror("ioctl");
        return -1;
    }

    memcpy(&sa, &ifr.ifr_addr, sizeof(struct sockaddr_in));
    memcpy(mac, sa.sa_data, 6);
    sprintf(vmac,"%.2X:%.2X:%.2X:%.2X:%0.2X:%0.2X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    printf("MacAddr : %s", vmac);
    return 0;
}

/***** 获取接口广播地址 *****************************************************************************************/
int GetBroadcastAddr(int sock, struct sockaddr_in *broadcast_addr)
{
    struct ifreq ifr;

    //获取网络接口字符串名字
    strncpy( ifr.ifr_name, IFNAME, strlen(IFNAME)+1 );
    //获取网络接口的广播地址
    if(0 > ioctl(sock, SIOCGIFBRDADDR, &ifr))
    {
        perror("ioctl");
        return -1;
    }
    memcpy(broadcast_addr, &ifr.ifr_broadaddr, sizeof(struct sockaddr_in));

    return 0;
}


/***** 设置广播 *************************************************************************************************/
int SetBroadcast(int sock, struct sockaddr_in *broadcast_addr)
{
    int ret = -1;
    int so_broadcast = 1;                       // 设置连接侦测超时时间为1秒 
    broadcast_addr->sin_port = htons(PORT);     // 设置广播端口

    //set broadcast
    ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &so_broadcast, sizeof(so_broadcast));
    if(0 > ret)
    {
        perror("client set broadcast err");
        return -1;
    }

    return 0;
}

/***** 客户端广播 ***********************************************************************************************/
int ClientBroadcast(void)
{
    int ret = -1;
    int sock = -1;
    char buf[20];
    fd_set readfd;
    struct timeval timeout;
    struct sockaddr_in broadcast_addr; // 本地地址
    struct sockaddr_in from_addr;      // 客户端地址
    int len = sizeof(struct sockaddr_in);

    //socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(0 > sock)
    {
        perror("client socket err");
        return -1;
    }

    // get broadcast addr
    if( GetBroadcastAddr(sock, &broadcast_addr) )
    {
        printf("get broadcast addr failed!\n");
        goto _out;
    }

    // set broadcast
    if( SetBroadcast(sock, &broadcast_addr) )
    {
        printf("set broadcast failed!\n");
        goto _out;  
    }

    while(1)
    {
        // send
        ret = sendto(sock, IP_FOUND, strlen(IP_FOUND) + 1, 0, (struct sockaddr *)&broadcast_addr, len);
        if(0 > ret)
        {
            perror("server send err");
            goto _out;
        }

        // 文件描述符集合清零
        FD_ZERO(&readfd);
        // 将套接字文件描述符加入读集合
        FD_SET(sock, &readfd);

        // 超时时间
        timeout.tv_sec = 5;         // 秒
        timeout.tv_usec = 0;        // 微秒

        // 监听套接字sock是否有数据可读，超时为5秒
        ret = select(sock+1, &readfd, NULL, NULL, &timeout);
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
                    //sock套接口有数据可读
                    if( FD_ISSET(sock, &readfd) )
                    {
                        //recieve
                        ret = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, &len);
                        if(0 > ret)
                        {
                            perror("server recieve err");
                            goto _out;
                        }
                        printf("buf : %s\n", buf);

                        //如果与IP_FOUND吻合
                        if( strstr(buf, IP_FOUND_ACK) )
                        {
                            printf("IP is %s\n", inet_ntoa(from_addr.sin_addr));
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


/***** 主函数 ****************************************************************************************************/
int main(void)
{
    if( ClientBroadcast() )
    {
        printf(" client broadcast failed!\n");
        return -1;
    }

    return 0;
}
