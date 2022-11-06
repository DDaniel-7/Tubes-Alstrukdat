#include "wordmachine.h"
#include <stdio.h>
#include<stdlib.h>

boolean endWord;
Word currentWord;
static FILE * pita;

void IgnoreBlanks(){
	while (currentChar == BLANK || currentChar == NEWLINE)
   {
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */

/* PITA STDIN */

void STARTWORD(){
	START();
	IgnoreBlanks();
	CopyWord();
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
   CopyWord();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void CopyWord(){
	IgnoreBlanks();
	currentWord.length = 0;
	while((currentChar != BLANK) && (currentChar != NEWLINE)){
      if (currentWord.length < CAPACITY){
		currentWord.contents[currentWord.length++] = currentChar;
		ADV();
      }
      else{
         break;
      }
		
	}
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

/* TAPE FILE */

void IgnoreBlanksF(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */
	while (currentChar == BLANK || currentChar == NEWLINE){
		ADVFILE();
	}
}

void STARTWORDFILE(char fileloc[]){
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	STARTFILE(fileloc);
	IgnoreBlanksF();
	CopyWordFile();
}

void ADVWORDFILE(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
   CopyWordFile();
}

void CopyWordFile(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	IgnoreBlanksF();
	currentWord.length = 0;
	while((currentChar != BLANK) && (currentChar != NEWLINE)){
      if (currentWord.length < CAPACITY){
		currentWord.contents[currentWord.length++] = currentChar;
		ADVFILE();
      }
      else{
         break;
      }
		
	}
}

Word ScanWord(Word word){
   // Mengeluarkan kata dengan isi yang terakhir
	int i = 0;
   Word result;
   while (i < word.length){
      result.contents[i] = word.contents[i];
      i++;
   }
   result.contents[i] = '\0';
   result.length = i;
   return result;
}

int ScanNum(Word word){
   // Menghasilkan integer dari sebuah kata
   int result = 0;
   int i = 0;
   while( i < word.length){
      result *= 10;
      result += (int) (word.contents[i] - '0');
      i++;
   }
   return result;
}

void ScanStr(Word word, char string[]){
   // Menghasilkan string dengan isi dari kata
   int i = 0;
   while (i < word.length){
      string[i] = word.contents[i];
      i++;
   }
   string[i] = '\0';
}

boolean IsWordStr(Word word, char string[]){
   // Menghasilkan true jika string pada kata sama dengan string yang dibandingkan
   int i = 0;
   if(word.length == LengthStr(string)){
      while(i < word.length){
         if(word.contents[i] != string[i]){
            return false;
         }
      i++;
      }
      return true;
   }
   return false;
}

int LengthStr(char string[]){
   // Menghitung panjang dari suatu string
   int i = 0;
   while (string[i] != '\0'){
      i++;
   }
   return i;
}

void ConcatStr(char string1[], char string2[]){
   // Menggabungkan string 1 dengan string 2
   int i = 0;
   int len1 = LengthStr(string1);
   int len2 = LengthStr(string2);
   while (i < len2){
      string1[i+len1] = string2[i];
      i++;
   }
   string1[i+len1] = '\0';
}

char* scaninput(){
   pita = stdin;
   char* string;
   int a;
   int i = 0;
   string = (char*) malloc(101 * sizeof(char));

   while (a = fgetc(pita))
   {
      if (a == '\n')
      {
         break;
      }
      *(string + i) = (char)a;
      i++;
   }
   *(string + i) = '\0';
   return string;
}
