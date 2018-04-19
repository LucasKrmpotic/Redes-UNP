# REDES Y TRANSMISIÓN DE DATOS
## Trabajo de Laboratorio 1

### Capa de Aplicación - HTTP.

## Cátedra: 
* ### Prof: Mg. Ing. Ricardo López
* ### JTP: Lic. Nahuel Defossé

## Alumnos: 
* ### Maximiliano Aguila
* ### Lucas Krmpotic
 ---


**Nota:** una de las pruebas documentadas en el notebook requieren las librerías *netifaces* y *python-nmap* para python. Se puede usar el siguiente [Dockerfile](../Dockerfile) hecho en base a [esta](https://hub.docker.com/r/jupyter/minimal-notebook/) imagen de jupyter-notebook. 

La imagen se puede correr con:

```bash
docker run --user=root --name=notebook -p < puerto >:8888 < nombreimg >
```

Es necesario el --user=root porque la imagen base setea por defecto un usuario no privilegiado que no tendría permisos para instalar las dependencias. 

**Nota:** en la salida del docker run se imprime el tocken para acceder a los archivos. 