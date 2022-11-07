#include <stdio.h>
#include "listgame.h"
#include "wordmachine.h"
#include "deletegame.h"
#include "arraydin.h"
#include "boolean.h"
#include "stdlib.h"
#include "queue.h"

void DeleteGame(ArrayDin *array, Queue *queue){
    char* nomor;
    int intnomor,i;
    printf("Masukkan nomor game yang akan dihapus: ");
    nomor = scaninput();
    intnomor = atoi(nomor);
    if(intnomor == 1 || intnomor == 2 || intnomor == 3 || intnomor == 4 || intnomor == 5){
        printf("Game gagal dihapus!\n");
    }
    /// ELSE IF KALO ADA DI QUEUE
    else{
        i = 0;
        while((i+1) != intnomor){
            i++;
        }
        if(!isEmptyQueue(*queue)){
            int z = IDX_HEAD(*queue);
            boolean sama = false;
            while(z <= IDX_TAIL(*queue)){
                if(IsStrEq(array->A[i],(*queue).buffer[z])){
                    sama = true;
                }
                z++;
            }

            if (sama == true){
                printf("Game gagal dihapus!\n");
            }
            else{
                DeleteAt(array, i);
                printf("Game berhasil dihapus\n");
            }

        }
        else{
            DeleteAt(array, i);
            printf("Game berhasil dihapus\n");
        }
    }
}

