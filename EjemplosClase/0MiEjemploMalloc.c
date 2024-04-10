/* Para pedir memoria usamos la función malloc con el tamaño en bytes que necesitamos, esto nos devuelve un void * y se hace automáticamente el casting al tipo que se
le asigne, es decir, malloc pide memoria y devuelve un puntero a esa memoria.
Toda memoria, cuando deja de usarse, debe ser liberada, si no, no se puede volver a usar. Para ello se usa la función free que tiene como parámetro de entrada el puntero
cuya memoria deber ser liberada. 
*/



#include <stdio.h>
#include <stdlib.h>

/* Prueba a crear un entero con valor 3 y puntero a entero llamado a. Asigna primero a ese puntero la dirección donde está b.
Tras eso, usa malloc para pedir memoria para un entero y asigna esa dirección al puntero a.
Cambia el valor de a y libera la memoria.
Usa el debug.
*/

int main (int argc, char const *argv[]){
    int b = 3;
    int *a;
    a = &b;
    while(1){
        a = malloc(sizeof(int));
        *a = 5;
        free(a);
        a = NULL;
    }
    return 0;
}

/*
PREGUNTA: ¿Cambia la dirección de memoria de a cuando se le asigna la dirección de memoria de b? ¿Y cuando se llama a malloc?
Sí, cambia en ambas.
*/