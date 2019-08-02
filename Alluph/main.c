#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include "./libs/auxiliar.h"
#include "./libs/list.h"
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
    if (!initializeLexicalAnalyzer()) exit(EXIT_FAILURE);

    printf("\n          [Row ,  Col] (Cat , %20s) {%s}\n\n", "Category", "Lexeme");

/*     List* myList = newList();
    Token* tk;
    
    char* line_read = readLine();

    while (line_read != NULL) {

        myList = analyseLine(line_read, myList);

        while((tk = popToken(myList)) != NULL) {
            printToken(tk);
        }       
       
       line_read = readLine();
    }

    myList = pushList(myList, newToken("EOF", catEOF, current_line, _column+1));
    printToken(popToken(myList));
 */


    List* listTest = newList();
    listTest = pushList(listTest, newToken("Teste1", catId, 0, 0));
    listTest = pushList(listTest, newToken("Teste2", catId, 0, 0));
    listTest = pushList(listTest, newToken("Teste3", catId, 0, 0));
    listTest = pushList(listTest, newToken("Teste4", catId, 0, 0));
    printList(listTest);
    printf("\n\n");
    printToken(popToken(listTest));
    printToken(popToken(listTest));
    printToken(popToken(listTest));
    printToken(popToken(listTest));
    printToken(popToken(listTest));
    closeFile();

    return 0;
}