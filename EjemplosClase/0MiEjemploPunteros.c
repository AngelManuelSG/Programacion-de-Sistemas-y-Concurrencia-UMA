#include<stdio.h>
#include<string.h>

int main (int argc, char const *argv[]){
    //PRINCIPIO DE PUNTEROS.
    //Ejercicio 1. "Que valor tiene ptr? Imprimelo y razona si coincide con lo que has pensado.
    int xx = 10;
    int *ptr;
    ptr = &xx;
    printf("El valor de ptr es %p\n", ptr);
    

    //PUNTEROS Y ARRAYS.
    //Ejercicio 2. En el siguiente ejemplo vamos a declarar una cadena y dos punteros a esa cadena, 
    //uno haciendo uso del operador indirección y otro asignado directamente.
    char cadena[100] = "Hello!";
    char *c1;
    char *c2;
    c1 = &cadena[0];
    c2 = cadena; 
    printf("El primer puntero apunta a %p y el segundo a %p\n", c1, c2);
    // Ambos dan lo mismo puesto que cadena en verdad no es más que un puntero al primer valor del array.

    //Ejercicio 3. Un tipo puntero (car, int, double) permite ciertos operadores sobre el, por ejemplo la suma.
    double numeros[]={2.2, 3.3, 4.4, 5.5};
    double *d;
    d = numeros;
    printf("El valor al que apunta d es %.1lf y al que apunta d+2 es %.1lf\n", *d, *(d+2));

    //Ejercicio 4. Que valor tiene z[0] tras ejecutar el siguiente codigo.
    int x = 10; int y = 20;
    int z[] = {1,6,3};
    int *ptri = NULL;
    ptri = z;
    *ptri = *ptri+1;
    ptri = NULL;
    // El valor de z[0] tras esta acción es 2 pues le suma uno al z[0] que valía uno.

    //PUNTEROS Y ESTRUCTURAS.
    struct str_Libro{
        char titulo[200];
        char autor[200];
        int paginas;
        float precio;
    };

    // Ejercicio 5. Define una variable de esta estructura anterior llamada libro y rellena sus campos.
    struct str_Libro libro;
    strcpy(libro.autor, "Oscar Wilde");
    strcpy(libro.titulo, "El retrato de Dorian Gray");
    libro.paginas = 283;
    libro.precio = 10.95;
    
    // Ejercicio 6. Define un puntero a la estructura que apunte a esta variable. Comprueba que funciona con debugger.
    struct str_Libro *ptr_libro = &libro;
    
    // Ejercicio 7. Mostrar el autor y precio con un print usando el puntero, no el libro.
    printf("El autor del libro es %s y el precio es %f\n", ptr_libro->autor, (*ptr_libro).precio);
    
    return 0;
}

