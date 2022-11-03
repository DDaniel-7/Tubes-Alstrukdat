#include <stdio.h>
#include <stdlib.h>
#include "listgame.h"

void ListGame() {
    //TAMBAHIN KALO FPOINTER == NULL GMN?
    FILE * fpointer;
    fpointer = fopen("listgame.txt","r");
    char singleLine[100];

    printf("Berikut adalah daftar game yang tersedia\n");
    int i = 1;
    while(fgets(singleLine,100,fpointer)!=NULL){
        printf("%d. ",i);
        i = i+1;
        fputs(singleLine,stdout);
    }   

    fclose(fpointer);
}
