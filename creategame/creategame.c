#include <stdio.h>
#include <stdlib.h>
#include "creategame.h"

void CreateGame(){
    FILE * fpointer;
    char singleLine[100];
    fpointer = fopen("listgame.txt","a");

    printf("Masukkan game yang ingin ditambahkan : ");
    fgets(singleLine, 100, stdin);
    fputs(singleLine,fpointer);
    printf("Game berhasil ditambahkan");
    fclose(fpointer);
}
