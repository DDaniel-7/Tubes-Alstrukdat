/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "boolean.h"
#include "mesinkarakter.h"

#define CAPACITY 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
extern boolean endWord;
extern Word currentWord;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void startWord();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = NEWLINE; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

/* -------------------------------------------------------------------------- */

void ignoreBlankF();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void startWordFile(char fileloc[]);
/* I.S. : currentWord sembarang 
   F.S. : currentWord terisi dengan kata pertama dari file */

void advWordFile();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWordFile();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

Word takeWord(Word word);
// Mengeluarkan Word dengan konten terakhir
boolean isWordString(Word word, char string[]);
// Mengeluarkan true bila string pada word sama dengan string yang dibandingkan
int takeNum(Word word);
// Mengeluarkan integer dari sebuah Word
void takeString(Word word, char string[]);
// Mengeluarkan string dengan konten dari Word
void stringCat(char string1[], char string2[]);
// Menggabungkan string 1 dengan string 2
int stringLen(char string[]);
// Menghitung lenght string

#endif