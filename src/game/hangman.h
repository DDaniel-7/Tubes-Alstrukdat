#ifndef hangman_H
#define hangman_H
#include "boolean.h"


void gameFunction(char *wordinFunction, char *userWordinFunction, int letterNumber);   

void printUserWord(char * userWordinPrint,int letterNumber);		

void printFigure(int failinFigure);		

void hangman();

#endif
