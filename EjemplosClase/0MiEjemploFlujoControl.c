//Vamos a hacer el esqueleto de un menú interactivo.
//El usuario introduce un carácter que representa una de las siguientes opciones de menú:
//   - i para iniciar
//   - 1 para opción de llamada 1.
//   - 2 para opción de mensaje
//   - f para finalizar.
// Usar getchar y swtich.

#include <stdio.h>
int main(int argc, char const *argv[])
{
    char c;
    do {
        printf("Introduzca una opción:\n");
        c = getchar();
        switch (c){
            case 'i':
                printf("Ha seleccionado la opción de inicio\n");
                break;
            case '1':
                printf("Ha seleccionado la opción de hacer una llamada\n");
                break;
            case '2': 
                printf("Ha seleccionado la opcción de mandar un mensaje\n");
                break;
            case 'f': 
                printf("Ha finalizado la ejecución\n");
                break;
            default:
                printf("No ha seleccionado una opción válida\n");
                break;
        }
        fflush(stdin);
    } while (c!='f');
    return 0;
}