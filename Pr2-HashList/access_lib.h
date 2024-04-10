/*
============================================================================
 Name        : access_lib.h
 Author      : Ángel Manuel Soria Gil
 Version     : V1.0
 Copyright   : Your copyright notice
 Description : Práctica 2.
 ============================================================================
 */

#ifndef _ACCESS_LIB_
#define _ACCESS_LIB_

typedef struct Person* ptrPerson;

struct Person{
    char * nombre;
    char * huella;
    ptrPerson siguiente;
};


/**
 * @brief Inicializa la lista a vacio. Partimos de un array de punteros a struct Person, así que debes inializarlos a NULL.
 * @param ptrArray Array de \p size elementos.
 * @param size Tamaño del \p ptrArray.
 */
void inicialize(struct Person *ptrArray[], int size);


/**
 * @brief Añadimos una persona a la estructura \p ptrArray con \p nombre y \p huella. En caso de que exista ya una persona en una posición del array, se insertará de forma ordenada (menor a mayor) por su huella (usa strcmp)
 * @param ptrArray Estructura de \p size elementos.
 * @param size Tamaño del array para el hash.
 * @param nombre Nombre de la persona.
 * @param huella Cadena de caractéres con la codificación de la huella.
 * @param ok Si el nombre y huella ya existe, o si no se puede reservar memoria, se devuelve \p ok a 0. Si se puede insertar \p ok será 1.
 */
void addPerson(struct Person *ptrArray[], int size, const char * nombre, const char * huella, int *ok);

/**
 * @brief Destruye toda la memoria reservada en la estructura (ojo el name y huella hay que liberarlo antes que el nodo en sí). Se recomienda crear una función privada para borrar el nodo y dejar el puntero apuntando a NULL.
* @param ptrArray Estructura de \p size elementos.
 * @param size Tamaño del array para el hash.
 */
void destruir(struct Person *ptrArray[], int size);

/**
 * @brief Almacena todos las personas en un fichero de texto con el formato \a nombre;huella\n Se almacenan por orden, primero todos los que ocupan la posición 0 en el array (y en orden en su lista), luego la 1, ..., hasta \p size -1.
 * @param fileName Nombre del fichero en el que se almacenarán los datos.
 * @param ptrArray Estructura de \p size elementos a salvar.
 * @param size Tamaño del array para el hash.
 */
void saveTextFile(char * fileName, struct Person *ptrArray[], int size);

/**
 * @brief Almacena todos las personas en un fichero binario. Se almacenara por cada persona: Un int con el tamaño de su nombre (teniendo el cuenta el carácter terminador). Una cadena con el nombre. Un int con el tamaño de su huella (teniendo el cuenta el carácter terminador). Una cadena con su huella. Ojo, se almacenan por orden, primero todos los que ocupan la posición 0 en el array (y en orden en su lista), luego la 1, ..., hasta \p size -1.
 * @param fileName Nombre del fichero en el que se almacenarán los datos.
 * @param ptrArray Estructura de \p size elementos a salvar.
 * @param size Tamaño del array para el hash.
 */
void saveBinaryFile(char * fileName, struct Person *ptrArray[], int size);

/**
 * @brief Carga desde un fichero de texto. Se deben BORRAR los datos existentes.
 * @param fileName Nombre del fichero del que se cargarán los datos.
 * @param ptrArray Estructura de \p size elementos a cargar.
 * @param size Tamaño del array para el hash.
 */
void loadTextFile(char * fileName, struct Person *ptrArray[], int size);

/**
 * @brief Carga desde un fichero Binario. Se deben BORRAR los datos existentes
 * @param fileName Nombre del fichero del que se cargarán los datos.
 * @param ptrArray Estructura de \p size elementos a cargar.
 * @param size Tamaño del array para el hash.
 */
void loadBinaryFile(char * fileName, struct Person *ptrArray[], int size);

/**
 * @brief Busca si la persona existe, se recomienda generar una función que compruebe si dos personas son iguales...
 * @param ptrArray Estructura de \p size elementos a buscar.
 * @param size Tamaño del array para el hash.
 * @param nombre Nombre de la persona a buscar.
 * @param huella Huella de la persona a buscar.
 * @return devuelve 0 si la persona no existe, otro valor si sí (puede ser 1 para simplificar).
 */
int autorize(struct Person *ptrArray[], int size,const char * nombre, const char * huella);

/**
 * @brief Elimina una persona de la estructura. 
 * @param ptrArray Estructura de \p size elementos a buscar.
 * @param size Tamaño del array para el hash.
 * @param nombre Nombre de la persona a eliminar.
 * @param huella Huella de la persona a eliminar.
 * @param ok devuelve 1 si se ha podido borrar, 0 en otro caso.
 */
void removePerson(struct Person *ptrArray[], int size, const char * nombre, const char * huella, int *ok);


#endif
