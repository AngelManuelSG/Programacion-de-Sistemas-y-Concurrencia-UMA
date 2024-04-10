#include<stdio.h>
#include<string.h>

void encriptar_y_mostrar(char * entrada){
  printf("\n----Encriptar\n");
  for (size_t i = 0; i < strlen(entrada); i++)
  {
    entrada[i]++;
    printf("%c",entrada[i]);
  }
  printf("\n");
}

void desencriptar_y_mostrar(char * entrada){
  printf("\n----Desencriptar\n");
  for (size_t i = 0; i < strlen(entrada); i++)
  {
    entrada[i]--;
    printf("%c",entrada[i]);
  }
  printf("\n");
}


int main (int argc, char const *argv[]){
    char encriptar[11]="Hola mundo";
    char desencriptar[11]="Ipmb!nvoep";
    printf("La encriptacion de la cadena %s es:", encriptar);
    encriptar_y_mostrar(encriptar);
    printf("\n");
    printf("La desencriptacion de la cadena %s es:", desencriptar);
    desencriptar_y_mostrar(desencriptar);
    printf("\n");
    return 0;
}

//Preguntas: Funciona? Encriptar y desencriptar se modifican?
//Respuesta: Funcionar funciona mirando la salida. Tras mirar en la terminal si que cambian las cadenas.


