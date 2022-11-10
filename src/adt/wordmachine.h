#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

# include "boolean.h"
# include "charmachine.h"
 
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

/* -------------------------------------------------------------------------- */

void IgnoreBlanksF();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void STARTWORDFILE(char fileloc[]);
/* I.S. : currentWord sembarang 
   F.S. : currentWord terisi dengan kata pertama dari file */

void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void CopyWordFile();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

Word ScanWord(Word word);
// Mengeluarkan kata dengan isi yang terakhir

int ScanNum(Word word);
// Menghasilkan integer dari sebuah kata

boolean IsWordStr(Word word, char string[]);
// Menghasilkan true jika string pada kata sama dengan string yang dibandingkan

void ScanStr(Word word, char string[]);
// Menghasilkan string dengan isi dari kata

int LengthStr(char string[]);
// Menghitung panjang dari suatu string

void ConcatStr(char string1[], char string2[]);
// Menggabungkan string 1 dengan string 2

char* scaninput();

char* firstword(char* input);

char* secondword(char* input);

boolean IsStrEq(char string1[], char string2[]);

int CountBlanks();

void STARTLOAD(char *filename);

void ADVLOAD();

#endif