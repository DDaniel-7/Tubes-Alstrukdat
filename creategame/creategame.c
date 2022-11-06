#include <stdio.h>
#include "creategame.h"
#include "wordmachine.h"
#include "boolean.h"
#include "arraydin.h"

void CreateGame(ArrayDin *array){
    char* gamestring;
    int i;
    printf("Masukkan game yang ingin ditambahkan : ");
    gamestring = scaninput();
    InsertLast(array,gamestring);
    printf("Game berhasil ditambahkan.\n");
}

