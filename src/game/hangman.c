#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include <math.h>
#include <time.h>
#include "charmachine.h"
#include "wordmachine.h"

#define WORDS 10
#define WORDLEN 40
#define CHANCE 10

long long mystrlen(char *str) 
{
    int count = 0;
    while(*str !='\0')
    {
        count++;
        str++;
    }
    return count;
}

int irand(int i) {
	boolean srandc = false;
    if (!srandc) {
        srand(time(NULL));
        srandc = true;
    }
    return rand() % i;
}

char* decrypt(char* code) {
	int hash = ((mystrlen(code) - 3) / 3) + 2;
	char* decrypt = malloc(hash);
	char* toFree = decrypt;
	char* word = code;
	for (int ch = *code; ch != '\0'; ch = *(++code))
	{
		if((code - word + 2) % 3  == 1){
			*(decrypt++) = ch - (word - code + 1) - hash;
		}
	}
	*decrypt = '\0';
	return toFree;
}

void tampilhangman(int wrong, char* body) {
	printf("\tMistakes :%d\n", wrong);
	switch(wrong) {
        case 10: body[10] = '\\'; break;
        case 9: body[9] = '/'; break;
        case 8: body[8] ='\\'; break;
        case 7: body[7] = '|'; break;
		case 6: body[6] = '/'; break;
		case 5: body[5] = ')', body[4] = '('; break;
		case 4: body[3] = '|'; break;
		case 3: body[2] = '_'; break;
		case 2: body[1] = '_'; break;
		case 1: body[0] = '_'; break;
		default: break;

	}
	printf("\t _______%c%c%c\n"
	       "\t|         %c\n"
	       "\t|        %c %c\n"
	       "\t|        %c%c%c\n"
	       "\t|        %c %c\n"
	       "\t|             \n"
	       "\t|             ", body[0], body[1], body[2],
	       body[3], body[4], body[5], body[6],body[7],body[8],body[9],body[10]);
}

void tampilkata(char* guess, int len) {
	printf("\tKATA : ");
	for (int i = 0; i < len; ++i)
	{
		printf(" %c ", guess[i]);
	}
	printf("\n");
}

void *mymemset(void *b, int c, int len)
{
  int i;
  char *p = b;
  i = 0;
  while(len > 0)
    {
      *p = c;
      p++;
      len--;
    }
  return(b);
}

char *mystrchr(char *s,char c)
{
   while(*s != c && *s != '\0') {
      s++;
   }
   if(*s == c) {
      return s;
   }else {
      return NULL;
   }
}

void hangman() {
	printf("\tSELAMAT DATANG DI HANGMAN\n\n");
	char values[WORDS][WORDLEN] = {"N~mqOlJ^tZletXodeYgs","gCnDIfFQe^CdP^^B{hZpeLA^hv","7urtrtwQv{dt`>^}FaR]i]XUug^GI"
								    ,"cruD=idduvUdr=gmcauCmg]","BQt`zncypFVjvIaTl]u=_?Aa}F",
									"iLvkKdT`yu~mWj[^gcO|","jSiLyzJ=vPmnv^`N]^>ViAC^z_","xo|RqqhO|nNstjmzfiuoiFfhwtdh~",
									"OHkttvxdp|[nnW]Drgaomdq"};
	char *body = malloc(CHANCE+1);
	int id = irand(WORDS);
	char *word = decrypt(values[id]);
	int len = mystrlen(word);
	char *guessed = malloc(len);
	char falseWord[CHANCE];

	mymemset(body, ' ', CHANCE+1);
	mymemset(guessed, '_', len);
	char guess;
	boolean found;
	char* win;

	int mistakes = 0;
	setvbuf(stdin, NULL, _IONBF, 0);
	while(mistakes < CHANCE && win != NULL) {
		found = false;
		printf("\n");
		tampilhangman(mistakes, body);
		printf("\n");
		printf("\tKARAKTER YANG SALAH : ");
		for (int i = 0; i < mistakes; ++i){
			printf("%c", falseWord[i]);
		}
		printf("\n");
		tampilkata(guessed, len);
		printf("\tMASUKAN TEBAKAN : ");
		do {guess = *scaninput();} while ( getchar() != '\n' );
		for (int i = 0; i < len; ++i)
		{
			if(word[i] == guess) {
				found = true;
				guessed[i] = guess;
			}
		}
		if(!found) {
			falseWord[mistakes] = guess;
			mistakes += 1;
		}
		win = mystrchr(guessed, '_');
	}

	if(win == NULL){
        printf("\n");
        printf("\tBerhasil menebak kata %s! Kamu mendapatkan %d poin!", word, len);
    }
    else {
        printf("\n");
        tampilhangman(mistakes, body);
        printf("\n\tKamu kurang beruntung. katanya adalah %s\n", word);
    }
    free(body);
	free(word);
	free(guessed);
}

