/*
============================================================================
 Name        : access_lib.c
 Author      : Ángel Manuel Soria Gil
 Version     : V3.0
 Copyright   : Your copyright notice
 Description : Práctica 2.
 ============================================================================
 */
#include "access_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Zona privada, no se incluye en *.h
int hash(const char *nombre, int size) {
    int sum = 0;
    const char *ptr = nombre;
    while (*ptr != '\0') {
        sum += *ptr;
        ptr++;
    }
    return sum % (size); // Devuelve un número entre 0 y N-1
}

/**
 * @brief Procedimiento privado para la eliminación de una lista de la estructura.
 * @param lista Estructura o lista de la estructura original a ser liberada.
*/
void destruirNodos(ptrPerson lista){
    if (lista!=NULL){
        if(lista->nombre!=NULL){
            free(lista->nombre);                                //Liberamos la memoria del nombre
            lista->nombre = NULL;               
        }
        if(lista->huella!=NULL){
            free(lista->huella);                                //Liberamos la memoria de la huella
            lista->huella = NULL;
        }
        if(lista->siguiente!=NULL){                             //Comprobamos si el siguiente es nulo, en caso de no serlo
            destruirNodos(lista->siguiente);                    //Destruimos también dicho nodo
            free(lista->siguiente);                             //Liberamos el siguiente
            lista->siguiente = NULL;
        }
        //free(lista);                                            //Liberamos la lista
        //lista=NULL;                                             //Y la ponemos a nulo
    }

}

/**
 * @brief Dadas dos personas establece si son igualres o no.
 * @param p1 puntero que apunta a una de las dos personas a comparar.
 * @param p2 puntero que apunta a la otra persona a comparar.
 * @return Un entero que será 0 si no son iguales y 1 si sí lo son, -1 en caso de error.
*/
int equalsPerson(ptrPerson p1, ptrPerson p2){
    int i = -1;                                             //Inicializamos como si hubiese un error para cubrirnos las espaldas
    if (strcmp(p1->huella, p2->huella)==0){                 //En caso de que las huellas sean iguales
        if(strcmp(p1->nombre, p2->nombre)==0){              //Comparamos si los nombres coinciden
            i = 1;                                          //En caso de coincidir devolvemos que son la misma persona
        } else {                                            //En otro caso es raro que sean la misma persona pero se llamen diferente
            i = 0;                                          //Devolvemos por tanto error
        }                               
    } else {                                                //En caso de que las huellas no son iguales, no son la misma persona
        i = 0;                                              //Indicamos que no lo son devolviendo 0
    }
    return i;                                               //Devolvemos el resultado de la comparacion
}



/**
 * @brief Inicializa la lista a vacio. Partimos de un array de punteros a struct Person, así que debes inializarlos a NULL.
 * @param ptrArray Array de \p size elementos.
 * @param size Tamaño del \p ptrArray.
 */
void inicialize(struct Person* ptrArray[], int size){
    ptrPerson p = NULL;                 //Declaramos un puntero a persona como nulo 
    int i = 0;
    while (i<size){                     //Para cada elemento del array
        ptrArray[i] = p;                //Establecemos que su valor es el puntero nulo
        i++;
    }
}

/**
 * @brief Añadimos una persona a la estructura \p ptrArray con \p nombre y \p huella. En caso de 
 * que exista ya una persona en una posición del array, se insertará de forma 
 * ordenada (menor a mayor) por su huella (usa strcmp)
 * @param ptrArray Estructura de \p size elementos.
 * @param size Tamaño del array para el hash.
 * @param nombre Nombre de la persona.
 * @param huella Cadena de caractéres con la codificación de la huella.
 * @param ok Si el nombre y huella ya existe, o si no se puede reservar memoria, se devuelve \p ok a 0. Si se puede insertar \p ok será 1.
 */
void addPerson(struct Person* ptrArray[], int size, const char * nombre, const char * huella, int *ok){
    ptrPerson p = malloc(sizeof(struct Person));                //Reservamos espacio para la persona y creamos el puntero a ella
    if (p==NULL){                                               //Controlamos si se ha podido o no reservar
        *ok = 0;                                                //En caso de no haber podido reservar devolvemos 0 y salimos
    } else {
        int i = hash(nombre, size);                             //Accedemos a la lista del array en la que almacenaremos la persona.
        p->nombre = strdup(nombre);                             //Copiamos el nombre en la persona
        p->huella = strdup(huella);                             //Copiamos la huella
        ptrPerson act = ptrArray[i];                            //Extraemos la lista en otro puntero para facilitar la notación. Denotará la posición actual.
        ptrPerson sig = act;                                    //Es un puntero auxiliar que denotará quién es el siguiente.
        int fin = 0;                                            //Añadimos un indicador de fin del bucle
        int vez = 0;                                            //Variable de control para insertar la primera vez
        while (sig!=NULL && fin == 0){                          //Vamos a comparar con el siguiente elemento para insertar.
            vez++;
            if (strcmp(p->huella, sig->huella)<0){              //Si la huella es menor que la del siguiente
                if (vez == 1){                                  //En caso de que sea la primera vez y la lista en que estoy insertando no tenga elementos
                    p->siguiente = sig;
                    ptrArray[i] = p;
                } else {
                    p->siguiente = sig;                         //Establezco el siguiente de p como el que era hasta ahora el siguiente
                    act->siguiente = p;                         //Y pongo a p como siguiente del actual, es decir, pongo p como eslabon entre el actual y el que antes era su siguiente                                         
                }
                fin = 1;                                        //Indico que ya lo he actualizado y salimos del bucle
                *ok = 1;                                        //Indicamos que se ha actualizado
            } else if (strcmp(p->huella, sig->huella)==0){      //En caso de coincidir las huellas
                if(strcmp(p->nombre, sig->nombre)==0){          //Verificamos que los nombres coinciden
                    *ok = 0;                                    //E indicamos que no se ha podido actualizar
                } else {                                        //En caso de no coincidir los nombres
                    perror ("Misma huella distinto nombre");    //Lanzamos un mensaje de error pues esto no debería ocurrir.
                }
                fin = 1;                                        //Indicamos que podemos salir del bucle
            }else {                                             //En caso de que aún no toque insertar actualizamos para iterar
                act = sig;                                      
                sig = sig->siguiente;
            }
        }
        if(act==NULL){                                          //En caso de deber insertar en el primero
            p->siguiente = NULL;
            ptrArray[i] = p;                                    //Insertamos
            *ok = 1;
        } else if(fin == 0){                                    //En caso de haber salido tras haber recorrido toda la lista y no haber encontrado su hueco
            p->siguiente = NULL;                                 
            act->siguiente = p;                                 //Insertamos al final de la lista.
            *ok = 1;                                            //Indicamos que se ha insertado
        } else{
            //Esta parte no debe hacer nada, está todo hecho
        }
    }                                                           //Acabamos la inserción.
}
    
/**
 * @brief Destruye toda la memoria reservada en la estructura (ojo el name y huella hay que liberarlo antes que el nodo en sí). Se recomienda crear una función privada para borrar el nodo y dejar el puntero apuntando a NULL.
 * @param ptrArray Estructura de \p size elementos.
 * @param size Tamaño del array para el hash.
 */
void destruir(struct Person *ptrArray[], int size){
    for(int i = 0; i<size; i++){                            //Para cada índice de la estructura
        ptrPerson lista = ptrArray[i];                      //Obtenemos la lista de dicho índice
        destruirNodos(lista);                               //Y la destruimos
        free(ptrArray[i]);                                  //Liberamos
        ptrArray[i]=NULL;                                   //La ponemos a nulo
    }
}

/**
 * @brief Almacena todos las personas en un fichero de texto con el formato \a nombre;huella\n Se almacenan por orden, primero todos los que ocupan la posición 0 en el array (y en orden en su lista), luego la 1, ..., hasta \p size -1.
 * @param fileName Nombre del fichero en el que se almacenarán los datos.
 * @param ptrArray Estructura de \p size elementos a salvar.
 * @param size Tamaño del array para el hash.
 */
void saveTextFile(char * fileName, struct Person *ptrArray[], int size){
    FILE* ptrfile = fopen(fileName, "wt");                              //Abrimos el fichero a escribir
    if (ptrfile != NULL){                                               //Comprobamos que se ha podido abrir
        ptrPerson sig = ptrArray[0];                                    //Cogemos la primera lista a imprimir
        for (int i = 1; i<=size; i++){                                  //Entramos en bucle para luego coger todas las listas
            while (sig!=NULL){                                          //Mientras no encontremos un elemento nulo en la lista
            fprintf(ptrfile, "%s;%s\n", sig->nombre, sig->huella);      //Guardamos nombre y huella en el fichero
            sig = sig->siguiente;                                       //Pasamos al siguiente elemento de la lista
            }
            sig=ptrArray[i];                                            //Pasamos a la siguiente lista
        }
    }
    fclose(ptrfile);                                                    //Cerramos el fichero
}

/**
 * @brief Almacena todos las personas en un fichero binario. Se almacenara por cada persona: Un int con el tamaño de su nombre (teniendo el cuenta el carácter terminador). Una cadena con el nombre. Un int con el tamaño de su huella (teniendo el cuenta el carácter terminador). Una cadena con su huella. Ojo, se almacenan por orden, primero todos los que ocupan la posición 0 en el array (y en orden en su lista), luego la 1, ..., hasta \p size -1.
 * @param fileName Nombre del fichero en el que se almacenarán los datos.
 * @param ptrArray Estructura de \p size elementos a salvar.
 * @param size Tamaño del array para el hash.
 */
void saveBinaryFile(char * fileName, struct Person *ptrArray[], int size){
    FILE* ptrfile = fopen(fileName, "wb");                                      //Abrimos el fichero a escribir
    if (ptrfile != NULL){                                                       //Comprobamos que se ha podido abrir
        ptrPerson sig = ptrArray[0];                                            //Cogemos la primera lista a imprimir
        for (int i = 1; i<=size; i++){                                          //Entramos en bucle para luego coger todas las listas
            while (sig!=NULL){                                                  //Mientras no encontremos un elemento nulo en la lista
            int tn = strlen(sig->nombre)+1;                                     //Construimos las cadena que vamos a escribir
            int th = strlen(sig->huella)+1;
            fwrite(&tn, sizeof(unsigned), 1, ptrfile);                          //Guardamos el tamanyo del nombre
            fwrite(sig->nombre, sizeof(char), strlen(sig->nombre), ptrfile);    //Guardamos el nombre
            fwrite(&th, sizeof(unsigned), 1, ptrfile);                          //Guardamos el tamanyo de la huella
            fwrite(sig->huella, sizeof(char), strlen(sig->huella), ptrfile);    //Guardamos la huella
            sig = sig->siguiente;                                               //Pasamos al siguiente elemento de la lista
            }
            sig=ptrArray[i];                                                    //Pasamos a la siguiente lista
        }
    }
    fclose(ptrfile);                                                            //Cerramos el fichero
}

/**
 * @brief Carga desde un fichero de texto. Se deben BORRAR los datos existentes.
 * @param fileName Nombre del fichero del que se cargarán los datos.
 * @param ptrArray Estructura de \p size elementos a cargar.
 * @param size Tamaño del array para el hash.
 */
void loadTextFile(char * fileName, struct Person *ptrArray[], int size){
    destruir(ptrArray, size);                                       //Borramos los datos existentes en la estructura.
    FILE* ptrfile = fopen(fileName, "rt");                          //Abrimos el fichero
    if(ptrfile==NULL){                                              //Controlamos errores
        perror("No se ha podido abrir el fichero");
    }
    char nombre[50];                                                //Preparamos los datos necesarios para la nueva persona 
    char huella[50];
    int ok = 0;
    while (fscanf(ptrfile, "%[^;];%s\n" ,nombre, huella)==2){       //Mientras que el fichero no sea vacío, guardo el nombre y huella extraidos por el formato
        //Por nombre y huella debería inicializarlos quizás
        addPerson(ptrArray, size, nombre, huella, &ok);             //Añado a esa persona
    }
    fclose(ptrfile);                                                //Cierro el fichero tras añadir a todas.
}

/**
 * @brief Carga desde un fichero Binario. Se deben BORRAR los datos existentes
 * @param fileName Nombre del fichero del que se cargarán los datos.
 * @param ptrArray Estructura de \p size elementos a cargar.
 * @param size Tamaño del array para el hash.
 */
void loadBinaryFile(char * fileName, struct Person *ptrArray[], int size){
    destruir(ptrArray, size);                                       //Borramos los datos existentes en la estructura.
    FILE* ptrfile = fopen(fileName, "rb");                          //Abrimos el fichero leyendo en binario
    if(ptrfile==NULL){                                              //Controlamos errores
        perror("No se ha podido abrir el fichero");
    }
    int ok = 0;                                                    //Esta variable será para añadir las personas usando addPerson
    int ctrol;                                                     //Esta variable será para controlar el tamaño del nombre y de la huella
    while (fread(&ctrol, sizeof(unsigned),1,ptrfile)!=0){          //Mientras haya una persona más, ie, puedo leer el tamanyo del nombre
        char nombre[50] = "";                                      //Preparamos char[] para leer el los datos de las personas
        char huella[50] = "";
        fread(nombre, sizeof(char), ctrol-1, ptrfile);              //Leo el nombre
        fread(&ctrol, sizeof(unsigned),1,ptrfile);                  //Leo el tamanyo de la huella
        fread(huella, sizeof(char), ctrol-1, ptrfile);              //Leo la huella
        addPerson(ptrArray, size, nombre, huella, &ok);             //Añado la persona
    }
    fclose(ptrfile);                                                //Cierro el fichero tras añadir a todas.
}

/**
 * @brief Busca si la persona existe, se recomienda generar una función que compruebe si dos personas son iguales...
 * @param ptrArray Estructura de \p size elementos a buscar.
 * @param size Tamaño del array para el hash.
 * @param nombre Nombre de la persona a buscar.
 * @param huella Huella de la persona a buscar.
 * @return devuelve 0 si la persona no existe, otro valor si sí (puede ser 1 para simplificar).
 */
int autorize(struct Person *ptrArray[], int size,const char * nombre, const char * huella){
    int found;                                      //Declaramos el resultado que devolveremos
    ptrPerson p = malloc(sizeof(struct Person));    //Reservamos memoria para crear la persona que queremos buscar
    p->nombre = strdup(nombre);                     //Copiamos los datos de la persona a buscar
    p->huella = strdup(huella);
    p->siguiente = NULL;
    int pos = hash(nombre, size);                   //Localizamos en qué lista debería estar dicha persona
    ptrPerson sig = ptrArray[pos];                  //Tomamos el primer elemento de esa lista
    int vez = 1;
    if (sig!=NULL){
        while (strcmp(p->huella, sig->huella)>0){       //Mientras la huella del que buscamos sea mayor
            sig = sig->siguiente;                       //Pasamos al siguiente y cuando salga del bucle la única opción posible es que la huella sea menor o igual que la de sig y 
            vez++;
        }  
    }
    if(vez == 1){
        found = 0;
    }                                               //mayor que la del anterior, luego, para que esté en la lista, la única opción es que coincida con la de sig
    if (sig ==NULL){                                //En caso de que sig sea nulo, es que no lo hemos encontrado
        found = 0;                                  
    } else {                                        //En otro caso
        found = equalsPerson(p, sig);               //Comparamos si son iguales
    }
    free(p->huella);                                //Liberamos la memoria
    p->huella = NULL;
    free(p->nombre);
    p->nombre = NULL;
    free(p);
    p = NULL;               
    return found;                                   //Devolvemos el resultado
}

/**
 * @brief Elimina una persona de la estructura. 
 * @param ptrArray Estructura de \p size elementos a buscar.
 * @param size Tamaño del array para el hash.
 * @param nombre Nombre de la persona a eliminar.
 * @param huella Huella de la persona a eliminar.
 * @param ok devuelve 1 si se ha podido borrar, 0 en otro caso.
 */
void removePerson(struct Person *ptrArray[], int size, const char * nombre, const char * huella, int *ok){
    if (autorize(ptrArray, size, nombre, huella)==0){
        *ok = 0;
    } else {
        int pos = hash(nombre, size);                   //Localizamos en qué lista debería estar dicha persona
        ptrPerson sig = ptrArray[pos];                  //Tomamos el primer elemento de esa lista
        ptrPerson prev = ptrArray[pos];
        int vez = 1;
        while (strcmp(huella, sig->huella)>0){          //Mientras la huella del que buscamos sea mayor
            vez++;
            prev = sig;                                 //Mantenemos en prev el elemento previo que había a la ejecución del bucle
            sig = sig->siguiente;                       //Pasamos al siguiente y cuando salga del bucle la única opción posible es que el elemento a borrar sea sig
        }
        if(vez==1){
            free(sig->nombre);                              //Liberamos su memoria sin borrar a su siguiente
            sig->nombre = NULL;
            free(sig->huella);
            sig->huella = NULL;
            free(ptrArray[pos]);
            ptrArray[pos] = NULL;
        } else {
            prev->siguiente = sig->siguiente;               //Borramos el elemento a borrar haciendo que el previo apunte ahora al siguiente del siguiente, es decir, nos los saltamos
            free(sig->nombre);                              //Liberamos su memoria sin borrar a su siguiente
            sig->nombre = NULL;
            free(sig->huella);
            sig->huella = NULL;
            free(sig);
            sig = NULL;
        }
        *ok = 1;
    }
}


    









