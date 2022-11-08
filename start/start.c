#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "arraydin.h"


void start(ArrayDin *arr){
    // memasukkan 5 permainan utama ke dalam list game
    //KAMUS LOKAL
    char *game1;
    char *game2;
    char *game3;
    char *game4;
    char *game5;


    // ALGORITMA
    game1 = "RNG";
    game2 = "DINER DASH";
    game3 = "DINOSAUR IN EARTH";
    game4 = "RISEWOMAN";
    game5 = "EIFFEL TOWER";
    InsertLast(arr, game1);
    InsertLast(arr, game2);
    InsertLast(arr, game3);
    InsertLast(arr, game4);
    InsertLast(arr, game5);

    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}
