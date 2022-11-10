#include <stdio.h>
#include "boolean.h"
#include "queue.h"

int main(){
    Queue q;
    CreateQueue(&q);

    if(isEmptyQueue(q)){
        printf("Queue kosong\n");
    }
    char* a = "Daniel";
    char* b = "Suka";
    char* c = "Makan";
    char* d = "Sapi";
    enqueue(&q, a);
    enqueue(&q, b);
    enqueue(&q, c);
    enqueue(&q, d);
    displayQueue(q);
    printf("Panjang queue : %d\n",length(q));
    dequeue(&q, &a);
    dequeue(&q, &b);
    if(!isFull(q)){
        printf("Queue belum penuh\n");
    }
    displayQueue(q);
    printf("Panjang queue : %d\n",length(q));

    return 0;
}