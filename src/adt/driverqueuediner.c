# include <stdio.h>
# include <stdlib.h>
# include "queuediner.h"

int main(){
    QueueDiner q;
    CreateQueueDiner(&q);

    int food = 69;
    int durations = 100;
    int endurance = 2;
    int price = 20000;

    if(isEmptyDiner(q)){
        printf("Queue masi kosong\n");
    }
    else if(!isFullDiner(q)){
        printf("Queue belum penuh\n");
    }

    enqueueDiner(&q, food , durations, endurance, price);
    enqueueDiner(&q, 70 , 456, 1, 1000);
    enqueueDiner(&q, 71 , 422, 3, 3000);
    enqueueDiner(&q, 72 , 344, 4, 5000);
    printf("Panjang queue skrg : %d\n",lengthDiner(q));
    dequeueDiner(&q, &food , &durations, &endurance, &price);
    printf("Panjang queue skrg : %d\n",lengthDiner(q));





}