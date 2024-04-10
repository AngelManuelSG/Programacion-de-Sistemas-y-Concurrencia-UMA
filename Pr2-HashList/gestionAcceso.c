#include "access_lib.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define SIZE 10


int main(int argc, char const *argv[])
{
    struct Person *arrayPersons[SIZE];
    int ok;

    //Probamos inicializar
    inicialize(arrayPersons,SIZE);
    for(int i = 0; i<SIZE;i++){
        assert(arrayPersons[i]==NULL);
    }
    printf("Pruebas inicialize superadas.\n");

    //Probamos añadir persona
    addPerson(arrayPersons,SIZE,"Joaquin","aoisrhg487456q46$&",&ok);
    assert(strcmp(arrayPersons[7]->huella,"aoisrhg487456q46$&")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Joaquin","aa!$%SGshijsgioj",&ok);
    assert(strcmp(arrayPersons[7]->huella,"aa!$%SGshijsgioj")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Joaquin","az!$%SGshijsgioj",&ok);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->huella,"az!$%SGshijsgioj")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Joaquin","ab!$%SGshijsgioj",&ok);
    assert(strcmp(arrayPersons[7]->siguiente->huella,"ab!$%SGshijsgioj")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Ana","boisrhg487456q46$&",&ok);
    assert(strcmp(arrayPersons[2]->huella,"boisrhg487456q46$&")==0);
    assert(strcmp(arrayPersons[2]->nombre,"Ana")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Luis","bajhuhAOUHEO)",&ok);
    assert(strcmp(arrayPersons[3]->huella,"bajhuhAOUHEO)")==0);
    assert(strcmp(arrayPersons[3]->nombre,"Luis")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Antonio","coisrhg487456q46$&",&ok);
    assert(strcmp(arrayPersons[8]->huella,"coisrhg487456q46$&")==0);
    assert(strcmp(arrayPersons[8]->nombre,"Antonio")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Maria","gasdf98IIU",&ok);
    assert(strcmp(arrayPersons[0]->huella,"gasdf98IIU")==0);
    assert(strcmp(arrayPersons[0]->nombre,"Maria")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Ricardo","fa!$asdi99!..",&ok);
    assert(strcmp(arrayPersons[8]->siguiente->huella,"fa!$asdi99!..")==0);
    assert(strcmp(arrayPersons[8]->siguiente->nombre,"Ricardo")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Lucia","ha!$%asdoasdad",&ok);
    assert(strcmp(arrayPersons[4]->huella,"ha!$%asdoasdad")==0);
    assert(strcmp(arrayPersons[4]->nombre,"Lucia")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Gustavo","ij!$%SGshijsgioj",&ok);
    assert(strcmp(arrayPersons[5]->huella,"ij!$%SGshijsgioj")==0);
    assert(strcmp(arrayPersons[5]->nombre,"Gustavo")==0);
    assert(ok==1);
    addPerson(arrayPersons,SIZE,"Andrea","kl89Jhah",&ok);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->siguiente->siguiente->huella,"kl89Jhah")==0);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->siguiente->siguiente->nombre,"Andrea")==0);
    assert(ok==1);
    printf("Pruebas addPerson superadas.\n");

    //Probamos a escribir y leer de fichero de texto (abre el fichero y lo ves...)
    saveTextFile("FicheroSalida.txt",arrayPersons,SIZE);
    loadTextFile("FicheroSalida.txt",arrayPersons,SIZE);
    assert(strcmp(arrayPersons[7]->huella,"aa!$%SGshijsgioj")==0);
    assert(strcmp(arrayPersons[2]->huella,"boisrhg487456q46$&")==0);
    assert(strcmp(arrayPersons[2]->nombre,"Ana")==0);
    assert(strcmp(arrayPersons[3]->huella,"bajhuhAOUHEO)")==0);
    assert(strcmp(arrayPersons[3]->nombre,"Luis")==0);
    assert(strcmp(arrayPersons[8]->huella,"coisrhg487456q46$&")==0);
    assert(strcmp(arrayPersons[8]->nombre,"Antonio")==0);
    assert(strcmp(arrayPersons[0]->huella,"gasdf98IIU")==0);
    assert(strcmp(arrayPersons[0]->nombre,"Maria")==0);
    assert(strcmp(arrayPersons[8]->siguiente->huella,"fa!$asdi99!..")==0);
    assert(strcmp(arrayPersons[8]->siguiente->nombre,"Ricardo")==0);
    assert(strcmp(arrayPersons[4]->huella,"ha!$%asdoasdad")==0);
    assert(strcmp(arrayPersons[4]->nombre,"Lucia")==0);
    assert(strcmp(arrayPersons[5]->huella,"ij!$%SGshijsgioj")==0);
    assert(strcmp(arrayPersons[5]->nombre,"Gustavo")==0);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->siguiente->siguiente->huella,"kl89Jhah")==0);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->siguiente->siguiente->nombre,"Andrea")==0);
    printf("Pruebas saveTextFile y loadTextFile superadas.\n");

    //¡Probamos el destruir!
    //El load debería llamar al destruir, probamos que no te dejas nada en memoria y el destruir funciona
    int cont = 10000;
    while (cont > 0){
        loadTextFile("FicheroSalida.txt",arrayPersons,SIZE);
        cont--;
    }
    printf("Primera prueba destruir superada aunque deberias mirar si consume memoria.\n");

    //Probamos a escribir y leer de fichero binario (ojo que el fichero no se ve nada)
    saveBinaryFile("FicheroSalida.bin",arrayPersons,SIZE);
    loadBinaryFile("FicheroSalida.bin",arrayPersons,SIZE);
    assert(strcmp(arrayPersons[7]->huella,"aa!$%SGshijsgioj")==0);
    assert(strcmp(arrayPersons[2]->huella,"boisrhg487456q46$&")==0);
    assert(strcmp(arrayPersons[2]->nombre,"Ana")==0);
    assert(strcmp(arrayPersons[3]->huella,"bajhuhAOUHEO)")==0);
    assert(strcmp(arrayPersons[3]->nombre,"Luis")==0);
    assert(strcmp(arrayPersons[8]->huella,"coisrhg487456q46$&")==0);
    assert(strcmp(arrayPersons[8]->nombre,"Antonio")==0);
    assert(strcmp(arrayPersons[0]->huella,"gasdf98IIU")==0);
    assert(strcmp(arrayPersons[0]->nombre,"Maria")==0);
    assert(strcmp(arrayPersons[8]->siguiente->huella,"fa!$asdi99!..")==0);
    assert(strcmp(arrayPersons[8]->siguiente->nombre,"Ricardo")==0);
    assert(strcmp(arrayPersons[4]->huella,"ha!$%asdoasdad")==0);
    assert(strcmp(arrayPersons[4]->nombre,"Lucia")==0);
    assert(strcmp(arrayPersons[5]->huella,"ij!$%SGshijsgioj")==0);
    assert(strcmp(arrayPersons[5]->nombre,"Gustavo")==0);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->siguiente->siguiente->huella,"kl89Jhah")==0);
    assert(strcmp(arrayPersons[7]->siguiente->siguiente->siguiente->siguiente->nombre,"Andrea")==0);
    printf("Pruebas saveBinaryFile y loadBinaryFile superadas.\n");

    //¡Probamos el destruir!
    //El load debe destruir el contenido y cargar lo que se le pida, vamos a ver si explota en memoria
    cont = 10000;
    while (cont > 0){
        loadBinaryFile("FicheroSalida.bin",arrayPersons,SIZE);
        cont--;
    }
    printf("Segunda prueba destruir superada.\n");

    //Probamos el autorizar
    assert(autorize(arrayPersons,SIZE,"Lucia","ha!$%asdoasdad")!=0);
    assert(autorize(arrayPersons,SIZE,"Ana","boisrhg487456q46$&")!=0);
    assert(autorize(arrayPersons,SIZE,"Lucia","boisrhg487456q46$&")==0);
    assert(autorize(arrayPersons,SIZE,"Amb","boisrhg487456q46$&")==0);
    printf("Pruebas autorize superadas.\n");

    //Probamos a borrar y ver si sigue autorizado
    removePerson(arrayPersons,SIZE,"Lucia","ha!$%asdoasdad",&ok);
    assert(ok==1);
    removePerson(arrayPersons,SIZE,"Lucia","ha!$%asdoasdad",&ok);
    assert(ok==0);
    printf("Pruebas removePerson superadas.\n");


    /* code */
    return 0;
}
