#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
//#include "my_inet.h"
#include <arpa/inet.h>
#define MAXBUF 256
#define PUERTO 5000
#define GRUPO "224.0.1.1"

int main(void)
{
    int fd, n, r;
    struct sockaddr_in srv, cli;
    struct ip_mreq mreq;
    char buf[MAXBUF];
    memset( &srv, 0, sizeof(struct sockaddr_in) );
    memset( &cli, 0, sizeof(struct sockaddr_in) );
    memset( &mreq, 0, sizeof(struct ip_mreq) );
    srv.sin_family = AF_UNSPEC;
    srv.sin_port = htons(PUERTO);
    if( inet_aton(GRUPO, &srv.sin_addr ) < 0 ) {
        perror("inet_aton");
        return -1;
    }
    if( (fd = socket( MY_AF_INET, SOCK_DGRAM, 0) ) < 0 ){
        perror("socket");
        return -1;
    }
    if( bind(fd, (struct sockaddr *)&srv, sizeof(srv)) < 0 ){
        perror("bind");
        return -1;
    }
    if (inet_aton(GRUPO, &mreq.imr_multiaddr) < 0) {
        perror("inet_aton");
        return -1;
    }
    inet_aton( "172.16.48.2", &(mreq.imr_interface) );
    if( setsockopt(fd, SOL_IP, IP_ADD_MEMBERSHIP, &mreq,sizeof(mreq)) < 0 ){
        perror("setsockopt");
        return -1;
    }
    n = sizeof(cli);
    while(1){
        if( (r = recvfrom(fd, buf, MAXBUF, 0, (struct sockaddr *)&cli, (socklen_t*)&n)) < 0 ){
            perror("recvfrom");
        }else{
            buf[r] = 0;
            fprintf(stdout, "Mensaje desde %s: %s", inet_ntoa(cli.sin_addr), buf);
        }
    }
}
