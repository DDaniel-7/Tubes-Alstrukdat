#include <stdio.h>
#include "listgame.h"
#include "arraydin.h"
#include "wordmachine.h"
#include "boolean.h"

void ListGame(ArrayDin *array){
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArrayDin(*array);
}

//int i;
//    for(i = 0 ; i <= (Length(*array)-1) ; i++ ){
//        printf("%d. %s\n",(i+1),((*array).((*A)[i])));
//    }