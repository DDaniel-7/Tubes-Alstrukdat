/* File: wordmachine.c */

#include "mesinkata.h"
#include <stdio.h>
#include<stdlib.h>
boolean endWord;
Word currentWord;

void ignoreBlank(){
	while (currentChar == BLANK || currentChar == NEWLINE){
		adv();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */

/* TAPE STDIN */

void startWord(){
	start();
	ignoreBlank();
	copyWord();
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord(){
	copyWord();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord(){
	ignoreBlank();
	currentWord.length = 0;
	while((currentChar != BLANK) && (currentWord.length < CAPACITY) && (currentChar != NEWLINE)){
		currentWord.contents[currentWord.length] = currentChar;
		adv();
		currentWord.length++;
	}
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

/* TAPE FILE */

void ignoreBlankF(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */
	while (currentChar == BLANK || currentChar == NEWLINE){
		advfile();
	}
}

void startWordFile(char fileloc[]){
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	startfile(fileloc);
	ignoreBlankF();
	copyWordFile();
}

void advWordFile(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	copyWordFile();
}

void copyWordFile(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	ignoreBlankF();
	currentWord.length = 0;
	while((currentChar != BLANK) && (currentWord.length < CAPACITY) && (currentChar != NEWLINE)){
		currentWord.contents[currentWord.length] = currentChar;
		advfile();
		currentWord.length++;
	}
}

Word takeWord(Word word){
	int i;
   Word output;
   for ( i = 0; i < word.length; i++){
      output.contents[i] = word.contents[i];
   }
   output.contents[i] = '\0';
   output.length = i;
   return output;
}

boolean isWordString(Word word, char string[]){
   int i;
   if(word.length == stringLen(string)){
      
      for ( i = 0; i < word.length; i++){
         if(word.contents[i] != string[i]){
            return false;
         }
      }
      return true;
   }
   return false;
}

int takeNum(Word word){
   int result = 0;int i;
   for ( i = 0; i < word.length; i++){
      result *= 10;
      result += (int) (word.contents[i] - '0');
   }
   return result;
}
void takeString(Word word, char string[]){
   int i;
   for ( i = 0; i < word.length; i++){
      string[i] = word.contents[i];
   }
   string[i] = '\0';
}
void stringCat(char string1[], char string2[]){
   int i;
   int len1 = stringLen(string1);
   int len2 = stringLen(string2);
   for ( i = 0; i < len2; i++){
      string1[i+len1] = string2[i];
   }
   string1[i+len1] = '\0';
}

int stringLen(char string[]){
   int i=0;
   while (string[i] != '\0'){
      i++;
   }
   return i;
}