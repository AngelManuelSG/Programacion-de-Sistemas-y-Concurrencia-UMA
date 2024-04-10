#include <stdlib.h> //free y malloc

int main(int argc, char const *argv[])
{
    int b = 3;
    int *a;
    a = &b;
    while (1)
    {
        a = malloc(sizeof(int));
        *a = 3;
        //free(a);
    }

    return 0;
}