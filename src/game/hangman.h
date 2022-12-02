# include "boolean.h"

# ifndef HANGMAN_H
# define HANGMAN_H

long long mystrlen(char *str);

int irand(int i);

char* decrypt(char* code);

void tampilhangman(int wrong, char* body);

void tampilkata(char* guess, int len);

void *mymemset(void *b, int c, int len);

void hangman();

#endif