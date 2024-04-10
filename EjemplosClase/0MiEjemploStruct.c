#include<stdio.h>
#include<string.h>
struct str_Libro
{
    char titulo[200];
    char autor[200];
    int paginas;
    float precio;
}; //Que no se te pase este punto y coma que cierra la estructura.

int main (int argc, char const *argv[]){
    // Ejercicio 1. Definir una variable llamada libro Nuevo
    struct str_Libro nuevoLibro; 
    // Ejercicio 2. Rellenar sus datos 
    nuevoLibro.precio = 33;
    nuevoLibro.paginas = 1;
    strcpy(nuevoLibro.titulo, "ProgSisConcu");
    strcpy(nuevoLibro.autor, "elProfe");
    //Ejercicio 3. Crear un alias para este tipo de datos usando typedef.
    typedef struct str_Libro Libro;
    //Ejercicio 4. Definir una nueva variable con el tipo Libro.
    Libro libro1;
}

