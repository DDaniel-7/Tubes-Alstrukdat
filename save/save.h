#ifndef _SAVE_H_
#define _SAVE_H_
#include "arraydin.h"



void saveGame(ArrayDin l, FILE *file);
// prosedur untuk menyimpan list game ke dalam suatu file txt
// I.S. : array of game (ListGame) terdefinisi dan mungkin kosong sebagai variabel global, file konfigurasi txt bisa jadi sudah ada dalam direktori
// F.S. : array of game tertulis atau ditulis dalam txt dengan nama tertentu
//        kalau nama sama, akan menimpa file yang sudah ada
//        kalau file berbeda, akan membentuk file baru

void save(char *namaFile, ArrayDin arr);
// prosedur untuk menyimpan state dari program ke dalam suatu file konfigurasi txt
// I.S. : state dari program terdefinisi sebagai variabel global, file konfigurasi txt bisa jadi sudah ada dalam direktori
// F.S. : state program ditulis dalam txt dengan nama tertentu
//        kalau nama sama, akan menimpa file yang sudah ada
//        kalau file berbeda, akan membentuk file baru




#endif
