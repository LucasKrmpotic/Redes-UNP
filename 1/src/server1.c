
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

int main(void){
    
    char buf[10];
    int s, n, ns, len;
    struct sockaddr_in direcc;

    if ((s = socket(AF_INET, SOCK_STREAM, 0))==-1){
        perror("Error en socket()");
        exit (-1);
    };

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);

    if (bind(s, (struct sockaddr *) &direcc, len)==-1){
        perror("Error en bind()");
        exit(-1);
    };
    
    if (listen(s, 5)==.1){
        perror("Error en listen()");
        exit(-1);
    };
    
    while(1){
        
        if ((ns = accept(s, (struct sockaddr *) &direcc, &len))==-1){
            perror("Error en acept()");
            exit(-1);
        };

        while ((n = recv(ns, buf, sizeof(buf), 0)) > 0)
            write(1, buf, n);

         close(ns);
    }
    
     close(s);
     exit(0);
    
}