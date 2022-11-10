#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

# include "boolean.h"
# include "charmachine.h"
 
#define CAPACITY 100
#define BLANK ' '

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void STARTWORD();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = NEWLINE; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */


void IgnoreBlanksDin();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void STARTWORDDin();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = NEWLINE; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDDin();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void CopyWordDin();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void STARTLOAD(char *filename);

void ADVLOAD();

void ADVWORDLOAD();

void CopyWordLoad();

void IgnoreNewLine();

char* scaninput();

char* firstword(char* input);

char* secondword(char* input);

boolean IsStrEq(char string1[], char string2[]);

char *scanword(Word Word);

int ScanNum(Word word);
// Menghasilkan integer dari sebuah kata

boolean IsWordStr(Word word, char string[]);
// Menghasilkan true jika string pada kata sama dengan string yang dibandingkan

int LengthStr(char string[]);
// Menghitung panjang dari suatu string

char* concatstringbaru(char* namafilenya);

#endif
