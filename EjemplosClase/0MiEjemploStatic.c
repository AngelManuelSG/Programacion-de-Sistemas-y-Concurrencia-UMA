#include<stdio.h>

void add2(){
    static int var = 1;
    printf("%d\n", var+=2);
}

int main(int argc, char **argv){
    add2();
    add2();
    add2();
    return 0;
}