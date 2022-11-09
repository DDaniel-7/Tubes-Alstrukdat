#include <stdio.h>
#include "queue.h"
#include "wordmachine.h"
#include "boolean.h"
#include "queuegame.h"
#include "toh.h"
//#include "dinnerdash.h"


void PlayGame(Queue *q)
{
    ElType val;
    if(!isEmptyQueue(*q))    //kalau queue game ada isinya maka,
    {
        printf("Berikut adalah daftar Game-mu\n");  //print q dulu

        int i,index = 1;
        for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++)
        {
            printf("%d. %s\n", index , (*q).buffer[i]);
            index++;
        }

        char *R = "RNG";
        char *DinDash = "DINER DASH";
        char *TOH = "TOH";
        char *RISE = "RISEWOMAN";
        char *DIE = "DINOSAUR IN EARTH";
        char *ET = "EIFFEL TOWER";

        if (IsStrEq(HEAD(*q), R)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            RNG();  // sesuaikan sama game RNG nanti

        }
        else if (IsStrEq(HEAD(*q), DinDash)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            printf("DD BERHASIL\n"); // APUS INI 
            //dinnerdash();  // sesuaikan sama game dinnerdash nanti
        }
        else if (IsStrEq(HEAD(*q), TOH)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            towerofhanoi();  // sesuaikan sama game dinnerdash nanti
        }
        else if (IsStrEq(HEAD(*q), RISE)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*q));
        }

        else if (IsStrEq(HEAD(*q), DIE)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*q));
        }
        else if (IsStrEq(HEAD(*q), ET)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*q));
        }

        else{
            int number = rand() % 10000 + 1;
            printf("%d\n", number);
        }
    }
    else    //kalau q nya masi kosong, maka diminta untuk panggil fungsi queuegame
    {
        printf("Belum ada game di QueueGame. Silahkan mengisi queue game terlebih dahulu\n");
    }
   
}