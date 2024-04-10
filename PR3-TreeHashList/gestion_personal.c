/*
============================================================================
 Name        : practica3.c 2024
 Authors     : Ángel Manuel Soria Gil y Elena Galacho Jiménez.
 Version     : V
 Copyright   : Your copyright notice
 Description : Práctica 3.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_personal.h"


/*
==============================================================================
FUNCIONES AUXILIARES
==============================================================================
*/

int altura(ptrPerson nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

ptrPerson rotarDerecha(ptrPerson y) {
    ptrPerson x = y->lt;
    ptrPerson T2 = x->rt;
    // Realizar la rotación
    x->rt = y;
    y->lt = T2;
    // Actualizar alturas
    y->altura = max(altura(y->lt), altura(y->rt)) + 1;
    x->altura = max(altura(x->lt), altura(x->rt)) + 1;

    return x;
}

ptrPerson rotarIzquierda(ptrPerson x) {
    ptrPerson y = x->rt;
    ptrPerson T2 = y->lt;
    // Realizar la rotación
    y->lt = x;
    x->rt = T2;
    // Actualizar alturas
    x->altura = max(altura(x->lt), altura(x->rt)) + 1;
    y->altura = max(altura(y->lt), altura(y->rt)) + 1;

    return y;
}

ptrPerson balancear(ptrPerson nodo) {
    if (nodo == NULL)
        return nodo;
    // Calcular el factor de equilibrio
    int factorEquilibrio = altura(nodo->lt) - altura(nodo->rt);
    // Caso izquierda-izquierda
    if (factorEquilibrio > 1 && nodo->lt != NULL && altura(nodo->lt->lt) >= altura(nodo->lt->rt))
        return rotarDerecha(nodo);
    // Caso derecha-derecha
    if (factorEquilibrio < -1 && nodo->rt != NULL && altura(nodo->rt->rt) >= altura(nodo->rt->lt))
        return rotarIzquierda(nodo);
    // Caso izquierda-derecha
    if (factorEquilibrio > 1 && nodo->lt != NULL && altura(nodo->lt->lt) < altura(nodo->lt->rt)) {
        nodo->lt = rotarIzquierda(nodo->lt);
        return rotarDerecha(nodo);
    }
    // Caso derecha-izquierda
    if (factorEquilibrio < -1 && nodo->rt != NULL && altura(nodo->rt->rt) < altura(nodo->rt->lt)) {
        nodo->rt = rotarDerecha(nodo->rt);
        return rotarIzquierda(nodo);
    }
    return nodo;
}


/**
 * @brief Funcion hash será usada para determinar en qué árbol estará lal persona
 * @param cadena cadena de caracteres de la cual obtendrá el hash
 * @return ASCII del primer carácter - 48 ó -1 en caso de error.
*/
int hash(const char *cadena) {
    if (cadena!= NULL && cadena[0] != '\0') {
        return (int)cadena[0] - 48;
    }
    return -1; 
}

/**
 * @brief encuentra el mínimo elemento de un arbol 
 * @param tree puntero a la raiz del arbol 
 * @return puntero al mínimo elemento de un arbol
*/
ptrPerson minimo(ptrPerson tree){
    if (tree !=NULL){
        while (tree->lt!=NULL){
            tree = tree->lt;
        }
    }
    return tree;
}


/**
 * @brief funcion privada para eliminar una persona de un árbol en concreto de la estructura
 * @param tree arbol del que será eliminada la persona
 * @param descriptor identificador de la persona a eliminar
 * @param ok dirección de memoria del integer ok para indicar si se ha eliminado correctamente o no
*/
void removePersonFrom(ptrPerson* tree, const char* descriptor, int* ok) {
    if (*tree == NULL) {
        *ok = 0;
    } else {
        if (strcmp(descriptor, (*tree)->descriptor) < 0) {
            removePersonFrom(&((*tree)->lt), descriptor, ok);
        } else if (strcmp(descriptor, (*tree)->descriptor) > 0) {
            removePersonFrom(&((*tree)->rt), descriptor, ok);
        } else {
            free((*tree)->descriptor);
            (*tree)->descriptor = NULL;
            free((*tree)->apellidos);
            (*tree)->apellidos = NULL;
            free((*tree)->nombre);
            (*tree)->nombre = NULL;
            if ((*tree)->lt == NULL && (*tree)->rt == NULL) {
                (*tree)=NULL;
            } else if ((*tree)->lt == NULL) {
                (*tree)=(*tree)->rt;
            } else if ((*tree)->rt == NULL) {
                (*tree)=(*tree)->lt;
            } else {
                ptrPerson sustituto = minimo((*tree)->rt);
                (*tree)->descriptor = strdup(sustituto->descriptor);
                (*tree)->apellidos = strdup(sustituto->apellidos);
                (*tree)->nombre = strdup(sustituto->nombre);
                (*tree)->edad = sustituto->edad;
                removePersonFrom(&((*tree)->rt), sustituto->descriptor, ok);
            }
            *ok = 1;
        }
    }
}



/**
 * @brief Funcion auxiliar recursiva empleada para destruir todos los nodos de un árbol
 * @param tree arbol a destruir
*/
void destruirNodos(ptrPerson tree){
    if (tree!=NULL){
        free(tree->nombre);
        tree->nombre = NULL;
        free(tree->apellidos);
        tree->apellidos = NULL;
        free(tree->descriptor);
        tree->apellidos = NULL;
        //tree->edad = NULL;
        if(tree->lt!=NULL){
            destruirNodos(tree->lt);
            tree->lt = NULL;
        }
        if(tree->rt!=NULL){
            destruirNodos(tree->rt);
            tree->rt = NULL;
        }
    }
}

/**
 * @brief función recursiva auxiliar para la impresión de un árbol por fichero de texto
 * @param tree arbol a guardar
 * @param ptrfile dirección del fichero a donde guardar el árbol
*/
void saveTextInOrderAux(ptrPerson tree, FILE* ptrfile){
    if(tree->lt!=NULL){
        saveTextInOrderAux(tree->lt, ptrfile);
    }
    fprintf(ptrfile, "%s;%s;%i;%s;\n", tree->nombre, tree->apellidos, tree->edad, tree->descriptor);
    if(tree->rt!=NULL){
        saveTextInOrderAux(tree->rt, ptrfile);
    }
}

/**
 * @brief función recursiva auxiliar para la impresión de un árbol por fichero de texto
 * @param tree arbol a guardar
 * @param ptrfile dirección del fichero a donde guardar el árbol
*/
void saveBinaryInOrderAux(ptrPerson tree, FILE* ptrfile){
    if(tree->lt!=NULL){
        saveBinaryInOrderAux(tree->lt, ptrfile);
    }
    int tn = strlen(tree->nombre)+1;
    int ts = strlen(tree->apellidos)+1;
    int td = strlen(tree->descriptor)+1;
    fwrite(&tn, sizeof(unsigned), 1, ptrfile);
    fwrite(tree->nombre, sizeof(char), tn, ptrfile);
    fwrite(&ts, sizeof(unsigned), 1, ptrfile);
    fwrite(tree->apellidos, sizeof(char), ts, ptrfile);
    fwrite(&(tree->edad), sizeof(unsigned), 1, ptrfile);
    fwrite(&td, sizeof(unsigned), 1, ptrfile);
    fwrite(tree->descriptor, sizeof(char), td, ptrfile);
    if(tree->rt!=NULL){
        saveBinaryInOrderAux(tree->rt, ptrfile);
    }
}

/**
 * @brief función privada auxiliar que imprime por pantalla un árbol in Order
 * @param tree arbol a imprimir
*/
void imprimeInOrden(ptrPerson tree){
    if(tree->lt != NULL){
        imprimeInOrden(tree->lt);
    }
    printf("Nombre: %s; Apellido: %s; Edad: %i; Descriptor Biometrico: %s\n", tree->nombre, tree->apellidos, tree->edad, tree->descriptor);
    if(tree->rt!=NULL){
        imprimeInOrden(tree->rt);
    }
}

int buscar(ptrPerson tree, const char* descriptor){
    if (strcmp(descriptor, tree->descriptor)<0){
        if(tree->lt!=NULL){
            return buscar(tree->lt, descriptor);
        } else {
            return 0;
        }
    } else if (strcmp(descriptor, tree->descriptor)==0){
        return 1;
    } else {
        if(tree->rt!=NULL){
            return buscar(tree->rt, descriptor);
        } else {
            return 0;
        }
    }
}

/*
=========================================================================
*/

void inicialize(struct Person* ptrArray[]){
    ptrPerson p = NULL;                 //Declaramos un puntero a persona como nulo 
    int i = 0;
    while (i<TAM){                      //Para cada elemento del array
        ptrArray[i] = p;                //Establecemos que su valor es el puntero nulo
        i++;
    }
}

void addPerson(struct Person *ptrArray[], const char * nombre, const char * apellidos, const char* descriptor, int edad, int *ok){
    ptrPerson p = malloc(sizeof(struct Person));                                                        //Reservamos memoria 
    if (p==NULL){                                                                                       //Controlamos que se ha reservado
        *ok = -1;
    } else {                                                                                            //En caso de haber podido reservar
        int numTree = hash(descriptor);                                                                 //Localizamos el arbol en que insertamos la persona con la funcion hash
        if (numTree==-1){                                                                               //Controlamos que si en el hash se ha producido un error
            printf("error: descriptor proporcionado no cumple con los formatos dados"); 
            *ok = -1;                                                                                   //Devolvemos ok como -1 indicando que se ha producido error
        } else {                                                                                        //En caso de tener el arbol en que insertar
            p->nombre = strdup(nombre);                                                                 //Copiamos los datos en la persona 
            p->apellidos = strdup(apellidos);
            p->descriptor = strdup(descriptor);
            p->edad = edad;
            p->lt = NULL;
            p->rt = NULL;
            p->altura = 1;
            ptrPerson act = ptrArray[numTree];                                                          //Tomamos el árbol en el que vamos a insertar
            if(act==NULL){                                                                              //Si la raíz del árbol es nula
                ptrArray[numTree] = p;                                                                  //Insertamos ahí
                *ok = 1;                                                                                //Devolvemos ok como 1 indicando que se ha insertado
            } else {                                                                                    //En caso de que la raíz no sea nula
                ptrPerson prev;                                                                         //Tomamos un puntero auxiliar
                int fin = 0;                                                                            //Tomamos una variable de control del flujo del bucle
                while (act!=NULL && fin==0){                                                            //Mientras el nodo con el que vamos a comparar no sea nulo y no haya acabado
                    prev = act;                                                                         //Actualizo el valor del nodo previo
                    if (strcmp(p->descriptor, act->descriptor)<0){                                      //En caso de ser p menor que el ya existente
                        act = act->lt;                                                                  //Debemos seguir explorando por la izquierda
                    } else if (strcmp(p->descriptor, act->descriptor)==0){                              //En caso de que coincidan los descriptores
                        *ok = 0;                                                                        //Devolvemos ok a 0 indicando que ya estaba insertado
                        fin = 1;                                                                        //Indicamos que hemos acabado para no entrar en bucle infinito
                    } else {                                                                            //En caso de que p sea mayor
                        act = act->rt;                                                                  //Debemos explorar a la derecha del padre
                    }
                }                                                                                       //Una vez hemos acabado de iterar
                if (fin==0){                                                                            //Si no se ha encontrado la persona
                    if (strcmp(p->descriptor, prev->descriptor)<0){                                     //En caso de que el previo sea menor, insertamos a la izquierda
                        prev->lt = p;
                    } else {                                                                            //En otro caso (solo será posible que el previo sea mayor pues fin==0)
                        prev->rt = p;                                                                   //Insertamos a la derecha
                    }
                    *ok = 1;                                                                            //Indicamos que hemos insertado con ok a 1.
                }
                balancear(ptrArray[numTree]);                                                         //Balanceamos el árbol.
            }
        }
    }
}

void removePerson(struct Person *ptrArray[], const char* descriptor, int* ok){
    int numTree = hash(descriptor);                                                                     //Localizamos el árbol en el que debemos eliminar la persona
    if (numTree==-1){                                                                                   //Controlamos que no se produzca algún error con el hash
        *ok=-1;
        printf("error: descriptor proporcionado no cumple los formatos validos.");
    } else {                                                                                            //En caso de encontrarlo
        ptrPerson tree = ptrArray[numTree];                                                             //Tomamos dicho árbol
        removePersonFrom(&tree, descriptor, ok);                                                         //Eliminamos a la persona buscada de él.
        //balancear(ptrArray[numTree]); 
    }
}


void destruir(struct Person *ptrArray[]){
    for (int i = 0; i<TAM; i++){
        destruirNodos(ptrArray[i]);                         //Tomamos el árbol y lo destruimos
        free(ptrArray[i]);                                  //Liberamos
        ptrArray[i]=NULL;                                   //La ponemos a nulo
    }
}

void saveTextFile(char * fileName, struct Person *ptrArray[]){
    FILE* ptrfile = fopen(fileName, "wt");                                                                      //Abrimos el fichero a escribir
    if (ptrfile != NULL){                                                                                       //Comprobamos que se ha podido abrir  
        for (int i = 0; i<TAM; i++){                                                                            //Entramos en bucle para luego coger todas los árboles
            if(ptrArray[i]!=NULL){                                                                              //Si el árbol no es nulo                                                                    
                saveTextInOrderAux(ptrArray[i], ptrfile);                                                       //Imprimimos el árbol
            }                                         
        }
    }else {
        printf("Ha ocurrido un error al crear el fichero");                                                     //En caso de no poder abrir el fichero lanzamos un mensaje de error
    }
    fclose(ptrfile);                                                                                            //Cerramos el fichero
}

void saveBinaryFile(char * fileName, struct Person *ptrArray[]){
    FILE* ptrfile = fopen(fileName, "wb");                                                                          //Abrimos el fichero a escribir
        if (ptrfile != NULL){                                                                                       //Comprobamos que se ha podido abrir  
            for (int i = 0; i<TAM; i++){                                                                            //Entramos en bucle para luego coger todas los árboles
                if(ptrArray[i]!=NULL){                                                                              //Si el árbol no es nulo                                                                    
                    saveBinaryInOrderAux(ptrArray[i], ptrfile);                                                     //Imprimimos el árbol
                }                                         
            }
        }else {
            printf("Ha ocurrido un error al crear el fichero");                                                     //En caso de no poder abrir el fichero lanzamos un mensaje de error
        }
    fclose(ptrfile);                                                                                            //Cerramos el fichero
}

void loadTextFile(char * fileName, struct Person *ptrArray[]){
    destruir(ptrArray);                                             //Borramos los datos existentes en la estructura.
    FILE* ptrfile = fopen(fileName, "rt");                          //Abrimos el fichero
    if(ptrfile==NULL){                                              //Controlamos errores
        perror("No se ha podido abrir el fichero");
    }
    char nombre [50];                                                //Preparamos los datos necesarios para la nueva persona 
    char apellido [50];
    int edad=-1;
    char descriptor [100];
    int ok = -1;
    while (fscanf(ptrfile, "%[^;];%[^;];%i;%[^;];\n" ,nombre, apellido, &edad, descriptor)==4){  //Mientras que el fichero no sea vacío, guardo el nombre y huella extraidos por el formato
        addPerson(ptrArray, nombre, apellido, descriptor, edad, &ok);                            //Añado a esa persona
        if(ok!=1){
            perror("Ha fallado la inserción");
        }
        ok = -1;
    }
    fclose(ptrfile);                                                                             //Cierro el fichero tras añadir a todas.
}

void loadBinaryFile(char* fileName, struct Person *ptrArray[]){
    destruir(ptrArray);                                                 //Borramos los datos existentes en la estructura.
    FILE* ptrfile = fopen(fileName, "rb");                              //Abrimos el fichero leyendo en binario
    if(ptrfile==NULL){                                                  //Controlamos errores
        perror("No se ha podido abrir el fichero");
    }
    int ok = 0;                                                         //Esta variable será para añadir las personas usando addPerson
    int ctrol = 0;                                                      //Esta variable será para controlar el tamaño del nombre, apellidos y descriptor
    while (fread(&ctrol, sizeof(unsigned),1,ptrfile)!=0){               //Mientras haya una persona más, ie, pueda leer el tamanyo del nombre
        char nombre[50] = "";                                           //Preparamos char[] para leer el los datos de las personas
        char apellidos[50] = "";
        int edad = -1;
        char descriptor[100] = "";
        fread(nombre, sizeof(char), ctrol, ptrfile);                    //Leo el nombre
        ctrol = 0;
        fread(&ctrol, sizeof(unsigned), 1, ptrfile);                    //Leo el tamanyo de apellidos
        fread(apellidos, sizeof(char), ctrol, ptrfile);                 //Leo la apellidos
        fread(&edad, sizeof(unsigned), 1, ptrfile);                     //Leo la edad
        ctrol = 0;
        fread(&ctrol, sizeof(unsigned), 1, ptrfile);                    //Leo el tamño del descriptor
        fread(descriptor, sizeof(char), ctrol, ptrfile);                //Leo el descriptor
        addPerson(ptrArray, nombre, apellidos, descriptor, edad, &ok);  //Añado la persona
    }
    fclose(ptrfile);                                                    //Cierro el fichero tras añadir a todas.
}


void listInOrder(struct Person *ptrArray[]){
    for(int i = 0; i<TAM; i++){
        if(ptrArray[i]!=NULL){
            imprimeInOrden(ptrArray[i]);
        }
    }
}

int autorize(struct Person *ptrArray[], const char* descriptor){
    int res = 0;
    int numTree = hash(descriptor);
    if(numTree==-1){
        printf("Se ha producido un error, el descriptor proporcionado no es válido.\n");
    } else {
        ptrPerson tree = ptrArray[numTree];
        if (tree!=NULL){
            res = buscar(tree, descriptor);
        } 
    }
    return res;
}

    





