#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "boolean.h"

#define NEWLINE '\n'
/* Char Engine State */
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

#endif
