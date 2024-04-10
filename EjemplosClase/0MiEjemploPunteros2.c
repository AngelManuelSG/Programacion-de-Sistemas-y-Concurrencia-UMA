#include<stdio.h>
#include<string.h>
void intercambiar1(int x, int y){
    int temporal;
    temporal = x;
    x = y;
    y = temporal;
}

void intercambiar2(int *x, int*y){
    int *temp;
    temp = x;
    x = y;
    y = temp;
}

void intercambiar(int *x, int*y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main (int argc, char const *argv[]){
    int x = 3; int y = 4;
    //PASO DE PARÁMETROS
    intercambiar1(x,y);
    printf("%i, %i\n", x,y);
    //No funciona intercambiar porque lo que se pasan son copias de las variables x e y
    intercambiar2(&x, &y);
    printf("%i, %i\n", x,y);
    //Lo corregimos. No cambia por lo mismo, al salir del void, no cambia las direcciones, 
    intercambiar(&x, &y);
    printf("%i, %i\n", x,y);
    return 0;
}

