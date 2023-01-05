#include <stdio.h>
#include <stdlib.h>

// If on Windows compile these functions
#ifdef _WIN64
#include <string.h>

/* Declaring a buffer array for string input */
static char buffer[2048];

// Fake readline function for testing
char* readline(char* prompt){
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void add_history(char* unused){}

// Otherwise include the edit line headers
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {
    puts ("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+C to Exit.\n");


    // Looping for input (Infinite loop)

    while(1){

        // Now in either case readline will be correctly defined
        char* input = readline("lispy>");
        add_history(input);

        // Echo input back to user
        printf("No you're a %f\n", input);
        free(input);
    }
    return 0;
}
