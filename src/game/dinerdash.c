# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "dinerdash.h"
# include "../adt/queuediner.h"
# include "../adt/wordmachine.h"
# include "../console.h"

boolean isIn(QueueDiner q, int food){
/* Mengembalikan true jika food dalam queue */
    if(!isEmptyDiner(q)){
        int i;
        boolean found = false;
        if ((q).idxHead > (q).idxTail){
            i = (q).idxHead;
            while((!(i >= MAX)) && (!found)){
                if(q.buffer[i].food != food){
                    i = (i+1)%MAX;
                }
                else{
                    found = true;
                }
            }
            i = 0;
            while((!(i > (q).idxTail)) && (!found)){
                if(q.buffer[i].food != food){
                    i = (i+1)%MAX;
                }
                else{
                    found = true;
                }
            }
        }
        else {
            i = (q).idxHead;
            while((!(i > (q).idxTail)) && (!found)){
                if(q.buffer[i].food != food){
                    i = (i+1)%MAX;
                }
                else{
                    found = true;
                }
            }
        }
        return found;
    }
    else{
        return false;
    }
}

void removeisIn(QueueDiner *q, int *food, int *durations, int *endurance, int *price)
/*IS : queue sembarang;
       food bisa tidak ad di dlm queue;
  FS : queue dengan makanan yg ad diremove;
*/
{
    if (isIn(*q, *food)){
        int i, index;
        boolean found = false;
        if ((q)->idxHead > (q)->idxTail){
            i = (q)->idxHead;
            while((!(i >= MAX)) && (!found)){
                if((*q).buffer[i].food != *food){
                    i = (i+1)%MAX;
                }
                else{
                    found = true;
                    index = i;
                }
            }
            i = 0;
            while((!(i > (q)->idxTail)) && (!found)){
                if((*q).buffer[i].food != *food){
                    i = (i+1)%MAX;
                }
                else{
                    found = true;
                    index = i;
                }
            }
            *durations = (*q).buffer[index].durations;
            *endurance = (*q).buffer[index].endurance;
            *price = (*q).buffer[index].price;
            if(index > (q)->idxHead){
                i = index;
                while(i < MAX + (q)->idxTail){
                    (*q).buffer[i%MAX].food = (*q).buffer[(i+1)%MAX].food;
                    (*q).buffer[i%MAX].durations = (*q).buffer[(i+1)%MAX].durations;
                    (*q).buffer[i%MAX].endurance = (*q).buffer[(i+1)%MAX].endurance;
                    (*q).buffer[i%MAX].price = (*q).buffer[(i+1)%MAX].price;
                    i++;
                }
            }
            else{
                i = index;
                while(i < (q)->idxTail){
                    (*q).buffer[i%MAX].food = (*q).buffer[(i+1)%MAX].food;
                    (*q).buffer[i%MAX].durations = (*q).buffer[(i+1)%MAX].durations;
                    (*q).buffer[i%MAX].endurance = (*q).buffer[(i+1)%MAX].endurance;
                    (*q).buffer[i%MAX].price = (*q).buffer[(i+1)%MAX].price;
                    i++;
                }
            }
            (q)->idxTail -= 1;
        }
        else {
            index = (q)->idxHead;
            while((!(index > (q)->idxTail)) && (!found)){
                if((*q).buffer[index].food != *food){
                    index = (index+1)%MAX;
                }
                else{
                    found = true;
                }
            }
            *durations = (*q).buffer[index].durations;
            *endurance = (*q).buffer[index].endurance;
            *price = (*q).buffer[index].price;
            if((q)->idxHead != (q)->idxTail){
                while(index < (q)->idxTail){
                    (*q).buffer[index].food = (*q).buffer[index+1].food;
                    (*q).buffer[index].durations = (*q).buffer[index+1].durations;
                    (*q).buffer[index].endurance = (*q).buffer[index+1].endurance;
                    (*q).buffer[index].price = (*q).buffer[index+1].price;
                    index++;
                }
                (q)->idxTail -= 1;
            }
            else{
                CreateQueueDiner(q);
            }
        }
    }
}

void Printqorder(QueueDiner q){
    printf("Daftar Pesanan\n");
    printf("Memasak | Durasi memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    if(!isEmptyDiner(q)){
        if ((q).idxHead > (q).idxTail){
            while ((q).idxHead <= MAX+(q).idxTail){
                printf("M%d      | %d              | %d         | %d\n",q.buffer[(q).idxHead%MAX].food, q.buffer[(q).idxHead%MAX].durations, q.buffer[(q).idxHead%MAX].endurance, q.buffer[(q).idxHead%MAX].price);
                (q).idxHead++;
            }
        }
        else {
            while ((q).idxHead <= (q).idxTail){
                printf("M%d      | %d              | %d         | %d\n",q.buffer[(q).idxHead].food, q.buffer[(q).idxHead].durations, q.buffer[(q).idxHead].endurance, q.buffer[(q).idxHead].price);
                (q).idxHead++;
            }
        }
    }
}


void Printqcooking(QueueDiner q){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Memasak | Sisa durasi memasak \n");
    printf("------------------------------\n");
    if(!isEmptyDiner(q)){
        if ((q).idxHead > (q).idxTail){
            while((q).idxHead <= MAX+(q).idxTail){
                if(q.buffer[(q).idxHead%MAX].durations != 0){
                    printf("M%d     | %d                \n",q.buffer[(q).idxHead%MAX].food, q.buffer[(q).idxHead%MAX].durations);
                }
                (q).idxHead++;
            }
        }
        else {
            while((q).idxHead <= (q).idxTail){
                if(q.buffer[(q).idxHead].durations != 0){
                    printf("M%d     | %d                \n",q.buffer[(q).idxHead].food, q.buffer[(q).idxHead].durations);
                }
                (q).idxHead++;
            }
        }
    }
    else{
        printf("        |                \n");
    }
}

void Printqserving(QueueDiner q){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Memasak | Sisa ketahanan memasak \n");
    printf("------------------------------\n");
    if(!isEmptyDiner(q)){
        if ((q).idxHead > (q).idxTail){
            while((q).idxHead <= MAX+(q.idxTail)){
                if(q.buffer[(q).idxHead%MAX].durations == 0){
                    printf("M%d     | %d                \n",q.buffer[(q).idxHead%MAX].food, q.buffer[(q).idxHead%MAX].endurance);
                }
                (q).idxHead++;
            }
        }
        else {
            while((q).idxHead <= (q).idxTail){
                if(q.buffer[(q).idxHead].durations == 0){
                    printf("M%d     | %d                \n",q.buffer[(q).idxHead].food, q.buffer[(q).idxHead].endurance);
                }
                (q).idxHead++;
            }
        }
    }
    else{
        printf("        |                \n");
    } 
}

void printall(QueueDiner qorder, QueueDiner qcook, int balance){
    printf("SALDO: %d\n\n",balance);
    Printqorder(qorder);
    printf("\n");
    Printqcooking(qcook);
    printf("\n");
    Printqserving(qcook);
    printf("\n");
}

void cook(QueueDiner qorder, QueueDiner *qcook, int food){
    if(!isIn(qorder,food)){
        printf("Makanan tidak tersedia!\n");
    }
    else{
        if(!isIn(*qcook,food)){
            if(!IsAvail(*qcook)){
                printf("Sudah tidak bisa memasak!\n");
            }
            else{
                printf("Berhasil memasak M%d\n",food);
                turn(qcook);
                int durations, endurance, price;
                removeisIn(&qorder, &food, &durations, &endurance, &price);
                enqueueDiner(qcook,food,durations,endurance,price);
            }
        }
        else{
            printf("Makanan masih dalam proses!\n");
        }
    }
}

void serve(QueueDiner *qorder, QueueDiner *qcook, int food, int *serving, int *balance, int *n){
    if(isIn(*qcook,food)){
        boolean found = false;
        if ((qcook)->idxHead > (qcook)->idxTail){
            while(((qcook)->idxHead < MAX) && (!found)){
                if((*qcook).buffer[(qcook)->idxHead].food != food){
                    (qcook)->idxHead = ((qcook)->idxHead+1)%MAX;
                }
                else{
                    found = true;
                }
            }
            (qcook)->idxHead = 0;
            while(((qcook)->idxHead <= (qcook)->idxTail) && (!found)){
                if((*qcook).buffer[(qcook)->idxHead].food != food){
                    (qcook)->idxHead = ((qcook)->idxHead+1)%MAX;
                }
                else{
                    found = true;
                }
            }
        }
        else {
            while(((qcook)->idxHead <= (qcook)->idxTail) && (!found)){
                if((*qcook).buffer[(qcook)->idxHead].food != food){
                    (qcook)->idxHead = ((qcook)->idxHead+1)%MAX;
                }
                else{
                    found = true;
                }
            }
        }
        if((*qcook).buffer[(qcook)->idxHead].durations != 0){
            printf("masih dimasak!\n");
        }
        else{
            if((qorder)->buffer[(qorder)->idxHead].food != food){
                printf("M%d belum dapat disajikan karena M%d belum selesai\n",food,(qorder)->buffer[(qorder)->idxHead].food);
            }
            else{
                printf("M%d berhasil diantar\n",food);
                int durations, endurance, price;
                dequeueDiner(qorder,&food,&durations,&endurance,&price);
                *balance += price;
                removeisIn(qcook,&food,&durations,&endurance,&price);
                *serving++;
                turn(qcook);
                durations = rand()%5 + 1;
                endurance = rand()%5 + 1;
                price = (rand()%41 + 10)*1000;
                enqueueDiner(qorder,*n,durations,endurance,price);
                *n += 1;
            }
        }
    }
}

void turn(QueueDiner *q){
    if ((q)->idxTail < (q)->idxHead){
        int idx = (q)->idxHead;
        while(idx <= MAX+(q)->idxTail){
            if((*q).buffer[idx%MAX].durations != 0){
                (*q).buffer[idx%MAX].durations--;
                if((*q).buffer[idx%MAX].durations == 0){
                    printf("Masakan M%d telah selesai dimasak\n",(*q).buffer[idx%MAX].food);
                }
            }
            else{
                (*q).buffer[idx%MAX].endurance--;
                if((*q).buffer[idx%MAX].endurance == 0){
                    printf("Makanan M%d telah hangus!\n", (*q).buffer[idx%MAX].food);
                    int food, durations, endurance, price;
                    food = (*q).buffer[idx%MAX].food;
                    removeisIn(q,&food,&durations,&endurance,&price);
                }
            }
            idx++;
        }
    }
    else {
        int idx = (q)->idxHead;
        while(idx <= (q)->idxTail){
            if((*q).buffer[idx].durations != 0){
                (*q).buffer[idx].durations--;
                if((*q).buffer[idx].durations == 0){
                    printf("Masakan M%d telah selesai dimasak\n",(*q).buffer[idx].food);
                }
            }
            else{
                (*q).buffer[idx].endurance--;
                if((*q).buffer[idx].endurance == 0){
                    printf("Makanan M%d telah hangus!\n",(*q).buffer[idx].food);
                    int food, durations, endurance, price;
                    food = (*q).buffer[idx].food;
                    removeisIn(q,&food,&durations,&endurance,&price);
                }
            }
            idx++;
        }
    }
}

boolean IsEndGame(QueueDiner q, int serving){
    return ((lengthDiner(q) > 7) || serving == 15);
}

boolean IsAvail(QueueDiner q){
    int ctr, res;
    ctr = 0;
    res = !(ctr > 5);
    if ((q).idxTail < (q).idxHead){
        while ((q).idxHead <= MAX+(q).idxTail){
            if((q).buffer[((q).idxHead)%MAX].durations == 0){
                ctr++;
            }
            (q).idxHead++;
        }
    }
    else {
        while((q).idxHead <= (q).idxTail){
            if((q).buffer[(q).idxHead].durations == 0){
                ctr++;
            }
            (q).idxHead++;
        }
    }
    return res;
}

void dinerdash(TabMap *arrmapsb){
    QueueDiner qorder, qcook;
    CreateQueueDiner(&qorder); 
    CreateQueueDiner(&qcook);
    int food, durations, endurance, price, serving, balance;
    char *command;
    srand(time(NULL));
    food=0;
    while(food < 3){
        durations = rand()%5 + 1;
        endurance = rand()%5 + 1;
        price = (rand()%41+10)*1000;
        enqueueDiner(&qorder, food, durations, endurance, price);
        food++;
    }
    printf("Selamat Datang di Diner Dash!\n\n");
    serving = 0;
    balance = 0;
    while(!IsEndGame(qorder,serving)){
        printall(qorder, qcook, balance);
        int x = 0;
        printf("MASUKKAN COMMAND: ");
        STARTWORDDin();
        command = scanword(currentWord);
        ADVWORDDin();
        boolean check = false;
        if(!endWord){
            int n = 1;
            while(n<currentWord.length){
                if(currentWord.contents[n] >= '0' && currentWord.contents[n] <= '9'){
                    x *= 10;
                    x += (int)(currentWord.contents[n]-48);
                }
                else{
                    check = true;
                }
                n++;
            }
            ADVWORDDin();
        }
        if(endWord && (!check)){
            if((command[0] == 'C') && (command[1] == 'O') && (command[2] == 'O') && (command[3] == 'K')){
                if(!isIn(qorder,x)){
                    printf("Makanan tidak tersedia\n");
                }
                if((isIn(qorder,x)) && (!isIn(qcook,x)) && (IsAvail(qcook))){
                    cook(qorder,&qcook,x);
                    durations = rand()%5 + 1;
                    endurance = rand()%5 + 1;
                    price = (rand()%41+10)*1000;
                    enqueueDiner(&qorder, food, durations, endurance, price);
                    food++;
                }
            }
            else if((command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E')){
                serve(&qorder, &qcook, x, &serving, &balance, &food);
            }
            else if((command[0] == 'S') && (command[1] == 'K') && (command[2] == 'I') && (command[3] == 'P')){
                printf("SKIP TURN\n");
                turn(&qcook);
                durations = rand()%5 + 1;
                endurance = rand()%5 + 1;
                price = (rand()%41+10)*1000;
                enqueueDiner(&qorder, food, durations, endurance, price);
                food++;
            }
            else{
                printf("WRONG COMMAND!\n");
            }
        }
        else{
            printf("WRONG COMMAND!\n");
        }
        printf("==========================================================\n\n");
    }
    printf("Game Over!\n");
    balance = (balance+1)/1000;
    balance = balance*1000;
    printf("SCORE: %d\n",balance);
    SAVESCOREBOARD(&arrmapsb->TIMap[1],balance);
}

/*
int main(){
    dinerdash();
    return 0;
}
*/
