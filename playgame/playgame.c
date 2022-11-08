#include <stdio.h>
#include "queue.h"
#include "wordmachine.h"
#include "boolean.h"
//#include "queuegame.h"
//#include "dinnerdash.h"


void PLAYGAME(Queue *gamequeue)
{
    ElType val;
    if(!isEmptyQueue(*gamequeue))    //kalau queue game ada isinya maka,
    {
        printf("Berikut adalah daftar Game-mu\n");  //print gamequeue dulu
        int i;
        for (i = (*gamequeue).idxHead; i < length(*gamequeue); i++)
        {
            printf("%d. %s\n", i+1, (*gamequeue).buffer[i]);
        }
        char *R = "RNG";
        char *DinDash = "Dinner Dash";
        if (IsStrEq(HEAD(*gamequeue), R)){
            printf("Loading %s ...\n", HEAD(*gamequeue));
            dequeue(gamequeue,&val);
            RNG();  // sesuaikan sama game RNG nanti

        }
        else if (IsStrEq(HEAD(*gamequeue), DinDash)){
            printf("Loading %s ...\n", HEAD(*gamequeue));
            dequeue(gamequeue,&val);
            dinnerdash();  // sesuaikan sama game dinnerdash nanti
        }
        else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*gamequeue));
        }
    }
    else    //kalau gamequeue nya masi kosong, maka panggil fungsi queuegame
    {
        QUEUEGAME();
    }
   
}

/*
int main(){
    Queue listgame;
    CreateQueue(&listgame);

    PLAYGAME(&listgame);
    return 0;
}*/
