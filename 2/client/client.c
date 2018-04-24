
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<arpa/inet.h>
 
#define HOST "192.168.2.116"
#define PORT 12345
#define MAXBUFF 1024

int main(void) {

    int s;
    struct sockaddr_in server;
    char req[MAXBUFF], resp[MAXBUFF];
     
    if ((s = socket(AF_INET, SOCK_STREAM, 0))==-1){
        perror("Error en socket()");
        return 1;
    }
     
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_port = htons(PORT);
 
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0){
        perror("Error en connect()");
        return 1;
    }
     
    while(1){
         
        fgets(req, MAXBUFF, stdin);

        if( send(s, req, strlen(req)+1, 0) < 0){
            perror("Error en send()");
            return 1;
        }
         
        if( recv(s, resp, MAXBUFF, 0) < 0){
            perror("Error en recv()");
            return 1;
        }
            
        printf("response: %s\n", resp);
        
        bzero(req, MAXBUFF);
    }
     
    close(s);
    return 0;
}
