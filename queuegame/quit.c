#include <stdio.h>
#include "quit.h"
#include "queue.h"

void quit(Queue *q){
    printf("Anda keluar dari game BNMO\n");
    printf("Bye bye ...\n");
    CreateQueue(q);
}