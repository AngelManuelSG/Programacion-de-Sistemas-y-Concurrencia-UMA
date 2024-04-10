#include <stdio.h>
int main(int argc, char const *argv[])
{
    char c;
    while ((c=getchar())!='f'){
        putchar(c);
    }

    return 0;
}