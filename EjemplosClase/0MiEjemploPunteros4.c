#include<stdio.h>
#include<string.h>

void copiarcadena(char *salida, char *entrada){
    int tam = strlen(entrada);
    for (int i=0; (i<tam && *entrada!='\000'); i++){
        *salida = *entrada;
        salida = salida+1;
        entrada = entrada+1;
    }
    *salida = *entrada;
}


int main (int argc, char const *argv[]){
    char cadena[20] = "mi rey";
    char *ptr;
    ptr = cadena;
    //printf("El tamanyo de la cadena es %i y coincide con el indicado por el puntero, que es %i ", strlen(cadena), strlen(ptr));
    char copia[20];
    copiarcadena(copia, cadena);
    printf("El contenido en la copia es: %s y coincide con el original %s", copia, cadena);
    return 0;
}

//Preguntas: Funciona? Encriptar y desencriptar se modifican?
//Respuesta: Funcionar funciona mirando la salida. Tras mirar en la terminal si que cambian las cadenas.


