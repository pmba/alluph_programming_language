#include <stdio.h>

#include "../includes/auxiliar.h"
#include "../includes/syntactic.h"

/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

int preditive_table[NonTerminalQuant][TerminalsQuant]= {

    {1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1},
    {2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,3},
    {-2,-2,-2,4,5,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-1,-1,6,7,8,9,10,-2,-1,-2,-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-1,-1,11,11,11,11,11,12,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,14,14,14,14,14,14,14,-2,13,-2,14,14,14,14,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,14,-2,-2,14,-2,-2,-2,-2,14,14,14,14,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,-1,-2,-1,-1,-1,-1,-1,-2,-2,-1,15,-1,-1,-1,-2,-2,-2,-1,-1,-2,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2},
    {-2,-2,-2,16,-2,16,16,16,16,16,-2,-2,-2,16,18,17,16,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,16,-2,-2,16,-2,-2,-2,-2,16,16,16,16,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,20,-2,19,19,19,19,19,-2,-2,-2,20,-1,-2,20,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,20,-2,-2,20,-2,-2,-2,-2,20,20,20,20,-2,-2,-2,-2,-2,-2},
    {-2,-2,-1,21,-2,21,21,21,21,21,-2,-2,-2,-2,-2,-2,21,21,21,21,-2,-2,-2,-2,-2,21,21,21,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,23,22,-2,22,22,22,22,22,-2,-2,-2,-2,-2,-2,22,22,22,22,-2,-2,-2,-2,-2,22,22,22,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-1,31,-2,27,27,27,27,27,-2,-2,-2,-2,-2,-2,28,24,25,26,-2,-2,-2,-2,-2,29,30,32,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,34,34,-2,34,34,34,34,34,-2,-2,-2,-2,-2,-2,34,34,34,34,-2,-2,33,-2,-2,34,34,34,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,36,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,35,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-2,-2,37,37,37,37,37,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,-1,-2,-1,-1,-1,-1,-1,-2,-2,-1,-1,-1,-1,38,-2,-2,-2,-1,-1,-2,-1,-1,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2},
    {-2,40,-2,40,-2,40,40,40,40,40,-2,39,40,40,40,40,40,-2,-2,-2,40,40,-2,40,40,-2,-2,-2,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,-2},
    {-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,41,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-2,42,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-2,-2,43,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,44,-2,-1,-1,-1,-1,-1,-2,-2,-1,-1,-1,-1,-1,-2,-2,-2,-1,-1,-2,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2},
    {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-2,-2,-2,45,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,46,-2,-2,-2,-2,-2,-2,-2,-2,-2,46,-2,-2,46,-2,-2,-2,-2,47,-2,-2,-2,-2,-2,-2,-2,-2,-2,46,-2,-2,46,-2,-2,-2,-2,46,46,46,46,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,48,-2,-1,-1,-1,-1,-1,-2,-2,-1,48,-1,-1,48,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,48,-2,-2,48,-2,-2,-2,-2,48,48,48,48,-2,-2,-2,-2,-2,-2},
    {-2,50,-2,50,-2,50,50,50,50,50,-2,-2,50,50,50,50,50,-2,-2,-2,50,50,-2,-2,-2,-2,-2,-2,49,-2,-2,50,-2,-2,50,-2,-2,-2,-2,50,50,50,50,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,51,-2,-1,-1,-1,-1,-1,-2,-2,-1,51,-1,-1,51,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-1,-2,-2,51,-2,-2,51,-2,-2,-2,-2,51,51,51,51,-2,-2,-2,-2,-2,-2},
    {-2,53,-2,53,-2,53,53,53,53,53,-2,-2,53,53,53,53,53,-2,-2,-2,53,53,-2,-2,-2,-2,-2,-2,53,52,-2,53,-2,-2,53,-2,-2,-2,-2,53,53,53,53,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,54,-2,-1,-1,-1,-1,-1,-2,-2,-1,54,-1,-1,54,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-1,-1,-2,54,-2,-2,54,-2,-2,-2,-2,54,54,54,54,-2,-2,-2,-2,-2,-2},
    {-2,56,-2,56,-2,56,56,56,56,56,-2,-2,56,56,56,56,56,-2,-2,-2,56,56,-2,-2,-2,-2,-2,-2,56,56,55,56,-2,-2,56,-2,-2,-2,-2,56,56,56,56,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,58,-2,-1,-1,-1,-1,-1,-2,-2,-1,58,-1,-1,58,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-1,-1,-1,57,-2,-2,58,-2,-2,-2,-2,58,58,58,58,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,59,-2,-1,-1,-1,-1,-1,-2,-2,-1,59,-1,-1,59,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-2,-2,59,-2,-2,-2,-2,59,59,59,59,-2,-2,-2,-2,-2,-2},
    {-2,61,-2,61,-2,61,61,61,61,61,-2,-2,61,61,61,61,61,-2,-2,-2,61,61,-2,-2,-2,-2,-2,-2,61,61,61,61,60,60,61,-2,-2,-2,-2,61,61,61,61,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,62,63,-1,-2,-2,-2,-2,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,65,-2,-1,-1,-1,-1,-1,-2,-2,-1,65,-1,-1,65,-2,-2,-2,-1,-1,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,64,-1,-1,-1,-1,65,65,65,65,-2,-2,-2,-2,-2,-2},
    {-2,67,-2,67,-2,67,67,67,67,67,-2,-2,67,67,67,67,67,-2,-2,-2,67,67,-2,-2,-2,-2,-2,-2,67,67,67,67,67,67,67,66,66,66,66,67,67,67,67,-2,-2,-2,-2,-2,-2},
    {-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,68,69,70,71,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2},
    {-2,-1,-2,72,-2,-1,-1,-1,-1,-1,-2,-2,-1,72,-1,-1,72,-2,-2,-2,-1,-1,-2,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,72,72,72,72,-2,-2,-2,-2,-2,-2},
    {-2,74,-2,74,-2,74,74,74,74,74,-2,-2,74,74,74,74,74,-2,-2,-2,74,74,-2,-2,-2,-2,-2,-2,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,73,73,-2,-2,-2,-2},
    {-2,-1,-2,75,-2,-1,-1,-1,-1,-1,-2,-2,-1,75,-1,-1,75,-2,-2,-2,-1,-1,-2,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,75,75,75,75,-1,-1,-2,-2,-2,-2},
    {-2,77,-2,77,-2,77,77,77,77,77,-2,-2,77,77,77,77,77,-2,-2,-2,77,77,-2,77,-2,-2,-2,-2,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,76,76,76,-2},
    {-2,-1,-2,80,-2,-1,-1,-1,-1,-1,-2,-2,-1,78,-1,-1,79,-2,-2,-2,-1,-1,-2,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,81,82,83,84,-1,-1,-1,-1,-1,-2},
    {-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,85,86,-2,-2,-2,-2},
    {-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-2,-2,87,88,89,-2}

};