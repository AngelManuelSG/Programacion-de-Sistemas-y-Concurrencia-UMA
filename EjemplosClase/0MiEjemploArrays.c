#include <stdio.h>
int main()
{
    // Ejercicio 0. Cuanto ocupa en tu maquina el tipo que mas bytes ocupa?
    int tam;
    tam = sizeof(long double);
    printf("El tamanyo mayor es de: %i\n", tam);
    // Ejercicio 1. Genera un array de doubles. Necesita el tamaño? Puede imprimirse con printf?
    float numeros[] = {1.0, 2.0, 3.0, 5.0};
    printf("%f\n", numeros[5]);
    // Ejercicio 2. Rellenar matriz doble a mano.
    float array2d[4][4] = {{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0,0.0,0.0},{0.0,0.0,1.0,0.0},{0.0,0.0,0.0,1.0}};
    // Ejercicio 3. Imprimir la matriz con precisión 2. Necesita tamaño? Fila cuatro columna 5?
    for (int i = 0; i<4; i++){
        printf("\n");
        for (int j = 0; j<4; j++){
            printf("%.2f ", array2d[i][j]);
        }
    }
    printf("\n%f", array2d[4][5]);


    return 0;
}