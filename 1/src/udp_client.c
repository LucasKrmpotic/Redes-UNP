/*
    Simple udp client
*/
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define SERVER "127.0.0.1"
#define MAXBUFF 1024  
#define PORT 12345  
 
int main(void)
{
    struct sockaddr_in server;
    int s, i, slen=sizeof(server);
    char buf[MAXBUFF], message[MAXBUFF];
    char * req = (char*)malloc(sizeof(MAXBUFF));

    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        perror("Error en socket()");
        exit(1);
    }
 
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
     
    if (inet_aton(SERVER , &server.sin_addr) == 0) 
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
 
    while(1)
    {
        printf("Enter message : ");
        fgets(req, MAXBUFF, stdin);
         
        if (sendto(s, req, strlen(req)+1 , 0 , (struct sockaddr *) &server, slen)==-1)
        {
            perror("Error en sendto()");
            exit(1);
        }
         
        memset(buf,'\0', MAXBUFF);
        
        if (recvfrom(s, buf, MAXBUFF, 0, (struct sockaddr *) &server, &slen) == -1)
        {
            perror("Error en recvfrom()");
            exit(1);
        }
         
        puts(buf);
    }
 
    close(s);
    return 0;
}