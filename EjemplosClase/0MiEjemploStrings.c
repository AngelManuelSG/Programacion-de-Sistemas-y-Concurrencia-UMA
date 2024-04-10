#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]){
    char cadena[11] = "Hola gatos";
    //Ejercicio 1. Generar una cadena nueva de tamanyo 15 y copiar en ella el contenido de la anterior.
    char nueva[15];
    strcpy(nueva, cadena);

    //Ejercicio 2. ¿Cual es el tamnyo de la nueva cadena?¿Cuenta el terminador? 
    int tam = strlen(nueva);
    //No, no cuenta.

    //Ejercicio 3. Crea una cadena de tamaño 30 y pega dos veces el contenido de la priemra cadena.
    char otra [30];
    strcat(otra, cadena);
    strcat(otra, cadena);

    //Ejercicio 4. Leer con scanf la cadena "Hola gatos". comparala con la cadena del primer ejercicio.
    //Hazlo con == y con strcmp.
    printf("Introduce la cadena Hola gatos por teclado\n");
    char leida[11];
    scanf("%[^\n]", leida);
    if(leida==cadena){
        printf("Comparando con == son iguales\n");
    } else if (strcmp(cadena, leida)==0){
        printf("Comparando con strcmp son iguales\n");
    }else {
        printf("No son iguales de ninguna manera\n");
    }

    //Ejercicio 5. La generación de cadenadas combinando variables de cualquier tipo se puede realizar con sprintf.
    //Prueba a concatenar la cadena generada anteriormente con una nueva variable entera con vallor 5 (y width 10 alineado a la izquierda.)
    int entero = 5;
    sprintf(cadena, "%s %-10i", cadena, entero);
    printf("%s", cadena);

    return 0;
}