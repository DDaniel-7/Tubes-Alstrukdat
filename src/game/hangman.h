#ifndef hangman_H
#define hangman_H
#include "boolean.h"
#include "../adt/arrayMap.h"
#include "../console.h"

void gameFunction(char *wordinFunction, char *userWordinFunction, int letterNumber, TabMap *arrmapsb);   

void printUserWord(char * userWordinPrint,int letterNumber);		

void printFigure(int failinFigure);		

void hangman(TabMap *arrmapsb);

#endif
