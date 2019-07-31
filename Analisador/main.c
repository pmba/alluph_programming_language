#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/auxiliar.h"
#include "./libs/stack.h"
#include "./libs/file.h"
#include "./libs/syntactic.h"
#include "./libs/lexical.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

int main(int argc, char const *argv[]) {

    if (argc <= 1) {

        printf("[Error] File path expected as first argument.\n");
        exit(EXIT_FAILURE);
    }

    Boolean file_opened = openFile(argv[1]);

    if (!file_opened) exit(EXIT_FAILURE); 

    readLine();
    readLine();
    readLine();
    readLine();
    readLine();

    // Stack* stack = createStack();

    // printf("%d\n", catFunction);


    // clearStack(stack);
    // free(stack);

    closeFile();

    return 0;
}