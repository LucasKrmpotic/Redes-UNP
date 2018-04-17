/*
    Simple udp server
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAXBUFF 1024
 
int main(void)
{
    char buf[MAXBUFF];
    int s, i, slen = sizeof(struct sockaddr_in), recv_len;
    struct sockaddr_in direcc, direcc2;
     
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        perror("Error en socket()");
        exit(1);
    }
     
    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORT);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    if( bind(s , (struct sockaddr*)&direcc, sizeof(direcc) ) == -1){
        perror("Error en bind()");
        exit(1);
    }
     
    while(1){
        fflush(stdout);
         
        if ((recv_len = recvfrom(s, buf, MAXBUFF, 0, (struct sockaddr *) &direcc2, &slen)) == -1)
        {
                perror("Error en recvfrom()");
                exit(1);
        }
         
        printf("Mensaje recibido de %s:%d\n", inet_ntoa(direcc2.sin_addr), ntohs(direcc2.sin_port));
        printf("Mensaje: %s\n" , buf);
         
        if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &direcc2, slen) == -1)
        {
            perror("Error en sendto()");
            exit(1);
        }
    }
 
    close(s);
    return 0;
}