
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * carpeta;
    char * aux;
    
    for (int i = 0; i<10; i++){
        sprintf(carpeta, "prueba %d", i);
        mkdir(carpeta, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
return 0;
}