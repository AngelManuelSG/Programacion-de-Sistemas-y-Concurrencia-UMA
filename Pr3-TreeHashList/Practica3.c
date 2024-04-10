/*
 ============================================================================
 Name        : Practica3.c 2024
 Authors     : Ángel Manuel Soria Gil y Elena Galacho Jiménez.
 ============================================================================
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "gestion_personal.h"


int main(void) {
	
	//declara tu estructura
	ptrPerson arrayPersons[TAM];

	//inicializa la estructura
	inicialize(arrayPersons);

	printf ("Leo de fichero de texto:\n");
	//llama a leer con "data.csv"
	loadTextFile("data.csv", arrayPersons);
	//Crea, assert para ver que se han leido bien al menos los dos primeros
	assert(autorize(arrayPersons, "0CnQhMcMrdpy")>0);
	assert(autorize(arrayPersons, "BMK968UcfmlpjPOWRFsL461DcCg")>0);
	printf("asserts  loadTextFile superados\n");


	printf ("Escribo a fichero binario:\n");
	// escribe a "data.bin"
	saveBinaryFile("data.bin",arrayPersons);

	printf ("Leo de fichero de binario:\n");
	//llama a leer con "data.bin"
	loadBinaryFile("data.bin", arrayPersons);
	//Crea, assert para ver que se han leido bien al menos los dos primeros (proporcionado en data.csv)
	assert(autorize(arrayPersons, "0CnQhMcMrdpy")>0);
	assert(autorize(arrayPersons, "BMK968UcfmlpjPOWRFsL461DcCg")>0);
	printf("asserts  loadBinaryFile superados\n");
	
	printf ("Escribo a fichero de texto:\n");
	// escribe a "data1.csv", mira a ojo que se escribe bien, compara la última línea
	saveTextFile("data1.csv", arrayPersons);
	//aunque no coincidan las últimas líneas, no influye en el hecho de que estén bien o no se especifica ni que se deban guardar los datos en orden en la estructura
	//ni que se deban escribir en la estructura con el mismo orden que había en el fichero. 
	printf("vamos a ordenar!\n");
	//Llama a ordenar
	listInOrder(arrayPersons);


	return 0;
}
