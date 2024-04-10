
/*
============================================================================
 Name        : circular_list.c
 Author      : Ángel Manuel Soria Gil
 Version     : 1.2
 Copyright   : Your copyright notice
 Description : Práctica 1.
 ============================================================================
 */

#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// @brief Inicializa la lista a vacio. Ojo que inicializar es simplemente asegurar que la lista apunta a NULL, no hay que pedir memoria NUNCA para inicializar un puntero.
/// @param nueva_lista Lista a inicializar.
void iniciar(TListaPtr *ptrNuevaLista){
    (*ptrNuevaLista) = NULL;
};


/// @brief Añade un nuevo dato en la cola de la lista.
/// @param ptrLista Lista en la que insertar el nuevo elemento.
/// @param dato Dato a copiar en la lista, ojo, copiar, no apuntar al mismo sitio.
/// @param ok Parámetro de salida que vale 1 si se ha podido insertar y 0 si no.
void addDato(TListaPtr *ptrLista, const char *dato, int *ok){
    TListaPtr node = malloc(sizeof(struct CList_Nodo));                          
    if (node == NULL){                                                                   
        perror("Ha ocurrido un error inesperado al añadir el dato");
        *ok = 0;
    } else {
        node->dato = strdup(dato);                                                    
        if ((*ptrLista) == NULL){                                                          
            node->sig = node;                                                              
            (*ptrLista) = node;                                                              
        } else {                                                                           
            node->sig = (*ptrLista)->sig;                                                   
            (*ptrLista)->sig = node;                                                         
            (*ptrLista) = node;                                                                
        }
        *ok = 1;
    }
};

/// @brief Muestra los datos en orden, del más antiguo al más nuevo
/// @param lista Lista con los elementos a mostrar.
void mostrar (TListaPtr lista){
    if (lista!=NULL){
        TListaPtr aux = lista->sig;
        printf("%s \n", aux->dato);
        aux = aux->sig;
        while(aux != lista->sig){
            printf("%s \n", aux->dato);
            aux = aux->sig;    
        }
    }
};

/// @brief Extrae el elemento de la cabeza de la lista
/// @param ptrLista Lista de la que extraer el dato
/// @param datoExtraido Parámetro de salida en el que se almacenará el dato extraido, ojo, hay que pedir memoria para él.
/// @param ok Parámetro de salida que vale 1 si se ha podido extraer y 0 si no.
void extraerDato(TListaPtr *ptrLista, char ** datoExtraido, int *ok) {
    if (*ptrLista == NULL) {
        *ok = 0;
    } else {
        //*datoExtraido = malloc(sizeof(char*));
        if ((*ptrLista)->sig == *ptrLista) {
            *datoExtraido = strdup((*ptrLista)->dato);
            free((*ptrLista)->dato);
            (*ptrLista)->dato = NULL;
            free(*ptrLista);
            *ptrLista = NULL;
        } else {
            *datoExtraido = strdup((*ptrLista)->sig->dato);
            TListaPtr primer = (*ptrLista)->sig;
            (*ptrLista)->sig = primer->sig;
            free(primer->dato);
            primer->dato = NULL;
            free(primer);
            primer = NULL;
        }
        *ok = 1;
    }
}

/// @brief Destruye la memoria de la lista circular. Debe terminar apuntando a NULL *;
/// @param ptrLista Lista a liberar memoria de sus elementos
void destruir(TListaPtr *ptrLista){
    char* dato;
    int ok = 1;
    while (ok!=0){
        extraerDato(ptrLista, &dato, &ok);
        if (ok==1){
            free(dato);
        }
    }
    *ptrLista = NULL;
};
