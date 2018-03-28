
/* 
PrimerServidorTCP.c
Servicio: Las cadenas de texto recibidas de un Cliente son enviadas a la salida estándar.
Nota: Por simplicidad del código no se realiza ningún tipo de control de errores. No obstante el servidor es totalmente funcional.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define PORTNUMBER 12345

int connection_handler(int n, int ns, char* buf){
    
    while ((n = recv(ns, buf, sizeof(buf), 0)) > 0)
        write(1, buf, n);
    
    return 1;
}

int main(void){
    char buf[10];
    int s, n, ns, len;
    struct sockaddr_in direcc;
    s = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    bind(s, (struct sockaddr *) &direcc, len);
    listen(s, 5);
    
    if ((ns = accept(s, (struct sockaddr *) &direcc, &len))==-1) {
        printf("error en accept()\n");
        exit(-1);
    } else {
        connection_handler(n, ns, buf);
    }
    
    
    
     close(ns); close(s);
     exit(0);
    
}