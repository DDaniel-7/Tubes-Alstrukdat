#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

boolean endWord;
Word currentWord;
static FILE * pita;
static int retval;

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

void IgnoreBlanksDin()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORDDin()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanksDin();
    if (currentChar == NEWLINE)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWordDin();
    }
}

void ADVWORDDin()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanksDin();
    if (currentChar == NEWLINE)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWordDin();
        IgnoreBlanksDin();
    }
}

void CopyWordDin()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.length = 0;
    while (currentChar != BLANK && currentChar != NEWLINE)
    {
        if (currentWord.length < CAPACITY)
        {
            currentWord.contents[currentWord.length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}
void STARTLOAD(char *filename){
   pita = fopen(filename,"r");
   ADVLOAD();
}

void ADVLOAD(){
   retval = fscanf(pita,"%c",&currentChar);
   EOP = (retval<0);
   if (EOP){
      fclose(pita);
   }
}

void ADVWORDLOAD(){
   IgnoreNewLine();
   if (retval < 0){
      endWord = true;
   }
   else{
      CopyWordLoad();
   }
}

void CopyWordLoad(){
   int i = 0;
   while ((currentChar != NEWLINE) && i < CAPACITY && !EOP){
      currentWord.contents[i] = currentChar;
      ADVLOAD();
      i++;
   }
   currentWord.length = i;
}

void IgnoreNewLine(){
   while (currentChar == NEWLINE){
      ADVLOAD();
   }
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

char* firstword(char* input){
   int i =0;
   char* output;
   output = (char*) malloc(101 * sizeof(char));

   while(input[i] != BLANK && input[i] != '\0'){
      output[i] = input[i];
      i++;
   }
   output[i] = '\0';

   return(output);
}

char* secondword(char* input){
   char* output2;
   output2 = (char*) malloc(101 * sizeof(char));

   int k = 0;
   while(input[k] != BLANK){
      k++;
   }

   int idx = k+1;

   int idxout = 0;
   while(input[idx] != BLANK && input[idx] != '\0'){
      output2[idxout] = input[idx];
      idx++;
      idxout++;
   }
   output2[idxout] = '\0';

   return(output2);
}

boolean IsStrEq(char string1[], char string2[]){
   // Menghasilkan true jika string1 sama dengan string2 yang dibandingkan
   int i = 0;
   if(LengthStr(string1) == LengthStr(string2)){
      while(i < LengthStr(string1)){
         if(string1[i] != string2[i]){
            return false;
         }
      i++;
      }
      return true;
   }
   return false;
}

char *scanword(Word Word)
{
    char *str;
    str = malloc(Word.length * sizeof(char));
    int i = 0;
    while (i < Word.length)
    {
        *(str + i) = Word.contents[i];
        i++;
    }
    str[i] = '\0';
    return str;
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

char* concatstringbaru(char* namafilenya){
   char* str1 = (char*) malloc(101 * sizeof(char));
   char* str2= (char*) malloc(101 * sizeof(char));
   str1= "../data/";
   str2= namafilenya;
   char* str3 = (char*) malloc(101 * sizeof(char));
   int i = 0, j = 0;
   while (str1[i] != '\0') {
      str3[j] = str1[i];
      i++;
      j++;
   }
   i = 0;
   while (str2[i] != '\0') {
      str3[j] = str2[i];
      i++;
      j++;
   }
   str3[j] = '\0';
   return str3;       
}
