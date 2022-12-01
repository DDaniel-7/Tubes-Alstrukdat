// NIM : 18221092
// Nama : Dwicakra Danielle
// Tanggal : 22 Oktober 2022
// Topik Praktikum : pra praktikum
// Deskripsi : implementasi stack.h

#include <stdio.h>
#include "boolean.h"
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptytoh (Stackt *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
    S->ctr = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStacktoh (Stackt S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==Nil);
}

boolean IsFulltoh (Stackt S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)==MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Pushtoh (Stackt * S, infotypes X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    InfoTop(*S) = X;
    S->ctr++;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Poptoh (Stackt * S, infotypes* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
    S->ctr--;
}
