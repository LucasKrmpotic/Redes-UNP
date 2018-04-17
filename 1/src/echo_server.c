
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
#include<arpa/inet.h>

#define PORT 12345
#define MAXBUFF 100

// manejador de la conexion
void connection_handler(int ns, char* buf, char * direcc){
    
    int n;
        
    printf("%s se conectó al servidor\n", direcc);
    while ((n = recv(ns, buf, sizeof(buf), 0)) > 0){
        send(ns, buf, n, 0);
    }
    
    printf("%s se desconectó\n", direcc);

}

int main(void){
    char buf[MAXBUFF];
    int s, ns, len;
    struct sockaddr_in direcc;

    if ((s = socket(AF_INET, SOCK_STREAM, 0))==-1){
        perror("Error en socket()");
        exit (-1);
    };

    bzero((char *) &direcc, sizeof(direcc));
    direcc.sin_family = AF_INET;
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);
    direcc.sin_port = htons(PORT);

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

        connection_handler(ns, buf, inet_ntoa(direcc.sin_addr));
    }
    
    close(ns); close(s);
    exit(0);
    
}