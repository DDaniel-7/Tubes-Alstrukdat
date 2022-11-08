#include <stdio.h>
#include "queue.h"
#include "wordmachine.h"
#include "boolean.h"
#include "queuegame.h"
//#include "dinnerdash.h"


void PlayGame(Queue *q)
{
    ElType val;
    if(!isEmptyQueue(*q))    //kalau queue game ada isinya maka,
    {
        printf("Berikut adalah daftar Game-mu\n");  //print q dulu
        int i;
        for (i = 0; i < length(*q); i++)
        {
            printf("%d. %s\n", i+1, (*q).buffer[i]);
        }

        char *R = "RNG";
        char *DinDash = "DINNER DASH";
        char *TOH = "TOH";
        if (IsStrEq(HEAD(*q), R)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            printf("RNG BERHASIL\n"); // APUS INI 
            //RNG();  // sesuaikan sama game RNG nanti

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
            printf("TOH BERHASIL\n"); // APUS INI 
            //TOH();  // sesuaikan sama game dinnerdash nanti
        }
        else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*q));
        }
    }
    else    //kalau q nya masi kosong, maka panggil fungsi queuegame
    {
        printf("Belum ada game di QueueGame. Silahkan mengisi queue game terlebih dahulu\n");
    }
   
}