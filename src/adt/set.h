#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nol 0
#define MaxEl 100

typedef int address;

typedef struct
{
    char* Elements[MaxEl];
    address Count;
} Set;

/* Definisi Set S kosong : S.Count = Nol */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count berNolai Nol */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count berNolai Nol */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count berNolai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, char* Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, char* Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, char* Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif