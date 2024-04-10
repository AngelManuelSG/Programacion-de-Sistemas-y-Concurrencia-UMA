#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a, b;
    printf("Introduce dos float separados por un espacio, luego un retorno de carro\n");

    while (scanf("%f %f", &a, &b) == 2)
        printf("Resultado: %f\n", a * b);

    perror("Se esperaban dos float separados por un espacio y no se han encontrado\n");

    return 0;
}

//Pregunta: ¿Por qué podemos dar un retorno de carro sin salir del while?
//Respuesta: Porque scanf sigue ejectándose. Una vez entra al bucle scanf busca leer dos floats, si lee algún retorno de carro no cuenta como caracter,
//           por tanto podemos darlo todas las veces que queramos que scanf sigue esperando, está leyendo todo el rato la entrada estándar y cuando
//           lee dos floats entonces se ejecuta y se vuelve a leer... está en bucle infinito hasta que se introduzca algo que no sea un float.

//Pregunta: ¿Qué pasa si ponemos tres numeros?
//Respuesta: Lee los dos primeros y el tercero lo deja en el buffer a la espera de recibir otro cuarto de forma que de nuevo sean dos floats y volver a ejecutar.

//Pregunta: ¿Y si son tres numeros con decimales indicados con punto?
//Respuesta: Ocurre igual, son floats lo que lee al fin y al cabo.

//Pregunta: ¿Y si se introducen con comas? 
//Respuesta: No se detectan como floats y da error.
