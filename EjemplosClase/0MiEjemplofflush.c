#include <stdio.h>
#include <unistd.h>

int main(int argvc, char argv[]) {
    printf("Hola, mundo");  //funcion C de E/S
    fflush(stdout);
    write(1, "Adios, mundo ", 13); // llamada al sistema, costosa, no buffer /
    char *str;
    str = "basura"; // el compilador lo interpreta como que no se puede modificar
    *(str+10) = 'k';  //Lo intentamos modificar, y explota.
    return 0;
}