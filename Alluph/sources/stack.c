#include <stdio.h>
#include <stdlib.h>

#include "../includes/auxiliar.h"
#include "../includes/stack.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

Stack* createStack() {

    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = NULL;
    newStack->size = 0;
    
    return newStack; 
}

GenericToken* createGenericToken(Boolean isTerminal, int catNum) {

    GenericToken* newGenericToken = malloc(sizeof(GenericToken));

    newGenericToken->terminal = isTerminal;
    newGenericToken->catNum = catNum;
 
    newGenericToken->next = NULL;

    return newGenericToken;
}

Boolean isEmpty(Stack* stack) {

    return stack->size == 0 ? True : False;
}

GenericToken* peek(Stack* stack) {

    if (stack != NULL) {

        return stack->top;
    } else {
        printf("Peeking null stack\n");
        return NULL;
    }
}

Boolean push(Stack* stack, GenericToken* gerToken) {

    if (stack != NULL) {

        gerToken->next = stack->top;
        stack->top = gerToken;
        ++stack->size;

        return True;
    } else {

        return False;
    }
}

GenericToken* pop(Stack* stack) {

    if (stack->size > 0 && stack != NULL) {

        GenericToken* popped = stack->top;
        stack->top = stack->top->next;

        --stack->size;

        return popped;
    } else {

        return NULL;
    }
}

int clearStack(Stack* stack) {

    int popped_count = 0;

    GenericToken* aux;

    while ((aux = pop(stack)) != NULL) {
        free(aux);
        ++popped_count;
    }

    return popped_count;
}
