#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "arraydin.h"

void saveGame(ArrayDin l, FILE *file){
    // Prosedur menulis list dari game, baik history ataupun keseluruhan permainan kedalam suatu file txt

    // KAMUS LOKAL
    int ctr, i;
    char *judulGame;

    // ALGOROTMA
    ctr = 1;
    i = 0;
    fprintf(file, "%d\n", l.Neff); // jumalah gamenya
    while(ctr <= l.Neff){
        judulGame = l.A[i];
        fprintf(file, "%s\n", judulGame);
        ctr++;
        i++;
    }
}


void save(char *namaFile, ArrayDin arr){
    //fungsi melakukan save terhadap state dari permainan yang terkandung dalam array
    // dan menyimpannya dalam sebuah file konfigurasi txt
    // jika file sudah ada, maka akan ditanya konfirmasi untuk menimpa file yang sudah ada


    // KAMUS LOKAL
     FILE *fileOutput;

    // ALGORITMA
    fileOutput = fopen(("%s", namaFile), "w");
    saveGame(arr, fileOutput);
    fclose(fileOutput);
}
