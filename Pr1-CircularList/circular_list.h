/*
============================================================================
 Name        : circular_list.h
 Author      : Ángel Manuel Soria Gil
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Práctica 1.
 ============================================================================
 */

#ifndef _CIRCULAR_LIST_
#define _CIRCULAR_LIST_

typedef struct CList_Nodo *TListaPtr;

struct CList_Nodo
{
    char *dato;
    TListaPtr sig;
};

/// @brief Inicializa la lista a vacio. Ojo que inicializar es simplemente asegurar que la lista apunta a NULL, no hay que pedir memoria NUNCA para inicializar un puntero.
/// @param nueva_lista Lista a inicializar.
void iniciar(TListaPtr *ptrNuevaLista);

/// @brief Añade un nuevo dato en la cola de la lista.
/// @param ptrLista Lista en la que insertar el nuevo elemento.
/// @param dato Dato a copiar en la lista, ojo, copiar, no apuntar al mismo sitio.
/// @param ok Parámetro de salida que vale 1 si se ha podido insertar y 0 si no.
void addDato(TListaPtr *ptrLista, const char * dato, int *ok);

/// @brief Muestra los datos en orden, del más antiguo al más nuevo.
/// @param lista Lista con los elementos a mostrar.
void mostrar(TListaPtr lista);


/// @brief Extrae el elemento de la cabeza de la lista.
/// @param ptrLista Lista de la que extraer el dato.
/// @param datoExtraido Parámetro de salida en el que se almacenará el dato extraido, ojo, hay que pedir memoria para él.
/// @param ok Parámetro de salida que vale 1 si se ha podido extraer y 0 si no.
void extraerDato(TListaPtr *ptrLista, char **datoExtraido, int *ok);

/// @brief Destruye la memoria de la lista circular. Debe terminar apuntando a NULL *
/// @param ptrLista Lista a liberar memoria de sus elementos.
void destruir(TListaPtr *ptrLista);




#endif