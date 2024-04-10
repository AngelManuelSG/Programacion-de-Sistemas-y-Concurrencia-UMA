#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Meses {
    ENE, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC
};

struct str_Revisa_Mensual
{
    char titulo[200];
    enum Meses mes;
    int anyo;
    float precio;
    struct str_Revisa_Mensual *siguiente;
};

 int main(int argc, char const *argv[])
{
    struct str_Revisa_Mensual *lista = malloc(sizeof(struct str_Revisa_Mensual));
    strcpy(lista->titulo, "Revista del mundo.");
    lista->mes = ENE;
    lista->anyo = 2023;
    lista->precio = 4.5;
    lista->siguiente = NULL;

    lista->siguiente = malloc(sizeof(struct str_Revisa_Mensual));
    strcpy(lista->siguiente->titulo, "Revista de Gatos.");
    lista->siguiente->mes = MAR;
    lista->siguiente->anyo = 2023;
    lista->siguiente->precio = 20.5;
    lista->siguiente->siguiente = NULL;

    lista->siguiente->siguiente = malloc(sizeof(struct str_Revisa_Mensual));
    strcpy(lista->siguiente->siguiente->titulo, "Revista de informatica.");
    lista->siguiente->siguiente->mes = FEB;
    lista->siguiente->siguiente->anyo = 2023;
    lista->siguiente->siguiente->precio = 13.5;
    lista->siguiente->siguiente->siguiente = NULL;


    /*
    EJERCICIO 1. Haz un bucle que recorra la lista teniendo en cuenta que el siguiente del último elemento es NULL.
    Imprime por pantalla para cada elemento su título y precio.
    */
    struct str_Revisa_Mensual *current = lista;
    while (current != NULL){
        printf("El titulo de de la revista es %s y su precio es %.2f\n", current->titulo, current->precio);
        current = current->siguiente;
    }
    
    /*
    EJERCICIO 2. Actual igual que en el ejercicio anterior pero parar de recorrer la lista cuando el precio sea superior
    a 20 euros.
    */
    current = lista;
    int fin = 0;
    while (current != NULL && !fin){
        if(current->precio>20){
            fin = 1;
        }
        printf("El titulo de de la revista es %s y su precio es %.2f\n", current->titulo, current->precio);
        current = current->siguiente;
    }

    /*
    EJERCICIO 3. Cambia la condición para que pare cuando el coste sea superior a 100 euros
    */
    current = lista;
    fin = 0;
    while (current != NULL && !fin){
        if(current->precio>100){
            fin = 1;
        }
        printf("El titulo de de la revista es %s y su precio es %.2f\n", current->titulo, current->precio);
        current = current->siguiente;
    }


    typedef struct str_Revisa_Mensual *ptrRevisa;
    /*
    EJERCICIO 4. Cómo se puede eliminar el primer elemento de la lista?
    */
   
     /*
    if (lista != NULL){
        ptrRevisa ptr = malloc(sizeof(struct str_Revisa_Mensual));
        ptr = lista;
        lista = lista->siguiente;
        free(ptr);
        ptr = NULL;
    }
    */
    //printf("El titulo de de la revista es %s y su precio es %.2f\n", lista->titulo, lista->precio);
    //Comprobamos que se imprime la revista de gatos.

    /*
    EJERCICIO 5. Comenta el código del ejercicio cuatro y haz uso de un bucle para eliminar la lista entera.
    */
    //ptrRevisa ptr = malloc(sizeof(struct str_Revisa_Mensual));
    //while(lista->siguiente!=NULL){
      //  ptr = lista;
      //  lista = lista->siguiente;
      //  free(ptr);
      //  ptr = NULL;
    //}
    //free(lista);
    //lista = NULL;

    /*
    EJERCICIO 6. Comenta el código del ejercicio 5 e inserta un nuevo elemento al comienzo de la lista.
    */
    struct str_Revisa_Mensual *aux = malloc(sizeof(struct str_Revisa_Mensual));
    strcpy(aux->titulo, "La nueva");
    aux->anyo = 2024;
    aux->mes = MAR;
    aux->precio = 17.89;
    aux->siguiente = lista;
    lista = aux;
    //COMPROBAMOS SI SE HA INSERTADO CORRECTAMENTE.
    current = lista;
    while (current != NULL){
        printf("El titulo de de la revista es %s y su precio es %.2f\n", current->titulo, current->precio);
        current = current->siguiente;
    }

    /*
    EJERCICIO 7. Inserta ahora un elemento al final de la lista asumiendo que no es vacía.
    */
    struct str_Revisa_Mensual *pre = malloc(sizeof(struct str_Revisa_Mensual));
    struct str_Revisa_Mensual *post = malloc(sizeof(struct str_Revisa_Mensual));
    struct str_Revisa_Mensual *elem = malloc(sizeof(struct str_Revisa_Mensual));
    strcpy(elem->titulo, "Renueva");
    elem -> anyo = 2025;
    elem->mes = ENE;
    elem->precio = 30;
    pre = lista;
    post = lista->siguiente;
    while(post!=NULL){
        pre = post;
        post = post->siguiente;
    }
    elem->siguiente = post;
    pre->siguiente = elem;

    
    //COMPROBAMOS
    current = lista;
    printf("\nEL ÚLTIMO\n");
    while (current != NULL){
        printf("El titulo de de la revista es %s y su precio es %.2f\n", current->titulo, current->precio);
        current = current->siguiente;
    }
    
    return 0;
}