
#ifndef GESTION_PERSONAL_H
#define GESTION_PERSONAL_H
/*
 ============================================================================
 Name        : Practica3.c 2024
 Authors     : Ángel Manuel Soria Gil y Elena Galacho Jiménez.
 ============================================================================
 */


#define TAM 75


typedef struct Person* ptrPerson;


struct Person{
    char* nombre;
    char* apellidos;
    int edad;
    char* descriptor;
    ptrPerson lt;
    ptrPerson rt;
    int altura;
};


/**
 * @brief Inicializa la lista a vacio. Partimos de un array de punteros a struct Person, así que debes inializarlos a NULL.
 * @param ptrArray Array de \p TAM elementos.
 */
void inicialize(struct Person *ptrArray[]);


/**
 * @brief Añadimos una persona a la estructura \p ptrArray con \p nombre y \p huella. En caso de que exista ya una persona en una posición del array, se insertará de forma ordenada (menor a mayor) por su huella (usa strcmp)
 * @param ptrArray Estructura de \p TAM elementos.
 * @param apellidos Apellidos de la persona
 * @param nombre Nombre de la persona.
 * @param descriptor Identificador de la persona.
 * @param edad Edad de la persona.
 * @param ok Si el nombre, apellidos, edad y descriptor ya existen devuelve \p ok a 0, si no se puede reservar memoria, se devuelve \p ok a -1. Si se puede insertar \p ok será 1.
 */
void addPerson(struct Person *ptrArray[], const char * nombre, const char * apellidos, const char* descriptor, int edad, int *ok);


/**
 * @brief Destruye toda la memoria reservada en la estructura (ojo el name y huella hay que liberarlo antes que el nodo en sí). Se recomienda crear una función privada para borrar el nodo y dejar el puntero apuntando a NULL.
 * @param ptrArray Estructura de \p TAM elementos.
 */
void destruir(struct Person *ptrArray[]);

/**
 * @brief Almacena todos las personas en un fichero de texto con el formato \a nombre;huella\n Se almacenan por orden, primero todos los que ocupan la posición 0 en el array (y en orden en su lista), luego la 1, ..., hasta \p TAM -1.
 * @param fileName Nombre del fichero en el que se almacenarán los datos.
 * @param ptrArray Estructura de \p TAM elementos a salvar.
 * @param size Tamaño del array para el hash.
 */
void saveTextFile(char * fileName, struct Person *ptrArray[]);

/**
 * @brief Almacena todos las personas en un fichero binario. Se almacenara por cada persona: Un int con el tamaño de su nombre (teniendo el cuenta el carácter terminador). Una cadena con el nombre. Un int con el tamaño de su huella (teniendo el cuenta el carácter terminador). Una cadena con su huella. Ojo, se almacenan por orden, primero todos los que ocupan la posición 0 en el array (y en orden en su lista), luego la 1, ..., hasta \p TAM -1.
 * @param fileName Nombre del fichero en el que se almacenarán los datos.
 * @param ptrArray Estructura de \p TAM elementos a salvar.

 */
void saveBinaryFile(char * fileName, struct Person *ptrArray[]);

/**
 * @brief Carga desde un fichero de texto. Se deben BORRAR los datos existentes.
 * @param fileName Nombre del fichero del que se cargarán los datos.
 * @param ptrArray Estructura de \p TAM elementos a cargar.
 * @param size Tamaño del array para el hash.
 */
void loadTextFile(char * fileName, struct Person *ptrArray[]);

/**
 * @brief Carga desde un fichero Binario. Se deben BORRAR los datos existentes
 * @param fileName Nombre del fichero del que se cargarán los datos.
 * @param ptrArray Estructura de \p TAM elementos a cargar.
 * @param size Tamaño del array para el hash.
 */
void loadBinaryFile(char * fileName, struct Person *ptrArray[]);

/**
 * @brief Busca si la persona existe en nuestra estructura.
 * @param ptrArray Estructura de \p TAM elementos a buscar.
 * @param descriptor Identificador de la persona a buscar.
 * @return devuelve 0 si la persona no existe, otro valor si sí (puede ser 1 para simplificar).
 */
int autorize(struct Person *ptrArray[], const char* descriptor);

/**
 * @brief Elimina una persona de la estructura. 
 * @param ptrArray Estructura de \p TAM elementos a buscar.
 * @param descriptor Huella de la persona a eliminar.
 * @param ok devuelve 1 si se ha podido borrar, 0 en otro caso.
 */
void removePerson(struct Person *ptrArray[], const char * descriptor, int *ok);


/**
 * @brief Muestra por pantalla los datos de las personas por orden creciente de descriptor biométrico
 * @param ptrArray Estructura de \p TAM elementos que vamos a mostrar.
*/
void listInOrder(struct Person *ptrArray[]);



#endif /* GESTION_PERSONAL_H */
