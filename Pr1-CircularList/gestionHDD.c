/*
 ============================================================================
 Name        : gestionHDD.c
 Author      : Joaquín Ballesteros
 Version     : V3
 Copyright   : Your copyright notice
 Description : Test 
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "circular_list.h"


int main(void)
{

	int ok;
	TListaPtr listaHDD;

	//Inicializamos
	iniciar(&listaHDD);
	assert(listaHDD==NULL);

	//No debería mostrar nada.
	mostrar(listaHDD);

 	//Insertamos 3 elementos, al final deberías tener (ojo que no termina)
	// listaHDD -> Tercer insertado -> Primer insertado -> Segundo insertado -> Tercer insertado -> ...

	char * primerElemento="Primer insertado";

	addDato(&listaHDD, primerElemento, &ok);
	assert(strcmp(listaHDD->dato,primerElemento)==0);
	assert(primerElemento!=listaHDD->dato); //No apuntan al mismo sitio, recuerda copiar el string strdup or strcpy 
	assert(listaHDD->sig == listaHDD);
	assert(ok == 1);

	
	addDato(&listaHDD, "Segundo insertado", &ok);
	assert(strcmp(listaHDD->dato,"Segundo insertado")==0);
	assert(strcmp(listaHDD->sig->dato,primerElemento)==0);
	assert(listaHDD->sig->sig == listaHDD);
	assert(ok == 1);

	addDato(&listaHDD, "Tercer insertado", &ok);
	assert(strcmp(listaHDD->dato,"Tercer insertado")==0);
	assert(strcmp(listaHDD->sig->dato,primerElemento)==0);
	assert(listaHDD->sig->sig->sig == listaHDD);
	assert(ok == 1);

    // Vamos ahora a mostrar la lista
	mostrar(listaHDD);

	//Vamos a eliminar todos los insertados
    char * extraido;

	extraerDato(&listaHDD, &extraido, &ok);
	assert(strcmp(extraido,"Primer insertado")==0);
	assert(listaHDD->sig->sig == listaHDD);
	assert(ok == 1);
	free(extraido);

	extraerDato(&listaHDD, &extraido, &ok);
	assert(strcmp(extraido,"Segundo insertado")==0);
	assert(listaHDD->sig == listaHDD);
	assert(ok == 1);
	free(extraido);

	extraerDato(&listaHDD, &extraido, &ok);
	assert(strcmp(extraido,"Tercer insertado")==0);
	assert(listaHDD==NULL);
	assert(ok == 1);
	free(extraido);

	extraerDato(&listaHDD, &extraido, &ok);
	assert(ok == 0);


	//Vamos a probar el destruir con un poco de maldad, mira el gestor de procesos, busca tu a.exe y mira cuanto ocupa antes y despues de bucle este.
	int contE=10000;
	int cont;
	while (contE>0){
		cont =10000;
		while (cont >0){
			addDato(&listaHDD, primerElemento, &ok);
			assert(ok == 1);
			cont--;
		}
		destruir(&listaHDD);
		contE--;
	}
	assert(listaHDD==NULL);

	return 0;
}
