#include <stdio.h>

void print(int n){
    do{
        puts("Hello World!"); //Short for put string
        n--;
    }while(n>0);
}

int main(int argc, char** argv) {

    int i = 5;
    print(i);
    return 0;
}
