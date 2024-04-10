#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "gestion_personal.h"

int hashP(const char *cadena) {
    if (cadena!= NULL && cadena[0] != '\0') {
        return (int)cadena[0] - 48;
    }
    return -1; 
}

int main(int argc, char const *argv[])
{   
    ptrPerson arrayPersons[TAM];
    int ok;

    //Pruebo el hash 
    printf("El hash de nuria es el %i\n", hashP("Muria"));


    //Pruebo el initialice;
    inicialize(arrayPersons);
    for (int i = 0; i<TAM; i++){
        assert(arrayPersons[i]==NULL);
    }
    printf("Prueba initialice superada.\n");

    //Probamos añadir persona
    addPerson(arrayPersons,"Joaquin","Ballesteros", "aoisrhg487456q46$&", 45, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Joaquin","Ballesteros", "aa!$%SGshijsgioj", 37, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Joaquin","Ballesteros", "az!$%SGshijsgioj", 50, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Joaquin","Maroto", "ab!$%SGshijsgioj", 35, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Ana", "Mato", "boisrhg487456q46$&", 45, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Lucia","Maria", "ha!$%asdoasdad", 56, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Gustavo", "Ronce", "ij!$%SGshijsgioj", 34, &ok);
    assert(ok==1);
    addPerson(arrayPersons,"Andrea", "Guti", "al89Jhah", 32, &ok);
    assert(ok==1);
    printf("Pruebas addPerson superadas.\n");
    
    //Probamos eliminar una persona.
    removePerson(arrayPersons, "aoisrhg487456q46$&", &ok);
    assert(ok==1);
    removePerson(arrayPersons, "aa!$%SGshijsgioj", &ok);
    assert(ok==1);
    printf("Pruebas removePerson superadas.\n");
    
    //Probamos a destruir todo
    //destruir(arrayPersons);

    saveTextFile("Fichero Texto Prueba.txt", arrayPersons);
    printf("Pruebas saveTextFile superadas\n");

    saveBinaryFile("Fichero Binario Prueba.bin", arrayPersons);
    printf("Pruebas saveBinaryFIle superadas\n");
    
    printf("He empezado a guardar\n");
    loadTextFile("data.csv", arrayPersons);
    printf("He acabado de guardar con texto\n");

    printf("Probamos de nuevo el saveTextFile");
    saveTextFile("Fichero TXT Prueba2", arrayPersons);
    printf("Parece que va bien");
    
    //Pruebas binary
    printf("Comezamos a probar el saveBinary\n");
    saveBinaryFile("Fichero Binario Prueba.bin", arrayPersons);
    

    printf("He empezado a guardar con binario\n");
    loadBinaryFile("Fichero Binario Prueba.bin", arrayPersons);
    printf("He acabado de guardar con binario\n");

    printf("\nVamos a imprimir los datos\n");
    listInOrder(arrayPersons);

    return 0;


}
