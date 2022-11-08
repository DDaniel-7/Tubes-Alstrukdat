#include <stdio.h>
#include "creategame.h"
#include "wordmachine.h"
#include "boolean.h"
#include "arraydin.h"

void CreateGame(ArrayDin *array){
    char* gamestring;
    int i = 0;
    boolean found = false;
    printf("Masukkan game yang ingin ditambahkan : ");  
    gamestring = scaninput();
    while(found == false && i < (*array).Neff){
        if(IsStrEq(gamestring, array->A[i])){
            found = true;
        }
        i++;
    }
    if (found == true){
        printf("Game sudah ada di sistem\n");
    }
    else{
        InsertLast(array,gamestring);
        printf("Game berhasil ditambahkan.\n");
    }
}


