// int printf (const char * format, ...);
// format:
// %[flags][width][.precision][lenght]specifier
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char cadena[11]="Hola mundo";
    int a = 65;
    float b = 65.78;

    //Ejercicio 1. Imprimir las tres variables.
    printf("entero: %i\nfloat: %f\ncadena:%s\n", a,b,cadena);

    //Ejercicio 2. Justificar el entero a izquierda y width 5. 
    printf("\n");
    printf("%-5i \n", a);
    
    //Ejercicio 3. Justificar el float a izquierda con width 20 mostrando todas las variables.
    //Hacerlo igual pero sin justificación a izquierda.
    printf("\n");
    printf("entero: %i float: %-20f cadena: %s\n", a,b,cadena);
    printf("entero: %i float: %20f cadena: %s\n", a,b,cadena);

    //Ejercicio 4. Mostrar solo un decimal del float y cuatro caracteres de la cadena.
    printf("\n");
    printf("entero: %i float: %.1f cadena:%.4s\n", a,b,cadena);


 return 0; 
}