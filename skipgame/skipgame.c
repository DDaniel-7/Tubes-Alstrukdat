#include <stdio.h>
#include <stdlib.h>
#include "skipgame.h"
#include "queue.h"
#include "playgame.h"

void skipgame(int n, Queue *q){
    // I.S. queue game terdefinisi dan mungkin kosong
    // F.S. melakukan dequeue n element q pertama dan menjalankan game ke n+1
    //      jika n lebih besar dari jumlah game dalam queue game, maka akan memberikan pesan kesalahan

    // KAMUS LOKAL
    ElType game;
    int panjang, i;

    // ALGORITMA
    panjang = length(*q);
    if(!IsEmpty(*q)){
        // kasus queue game tidak kosong
        if(n < panjang){
            // kasus menjalankan game ke n+1
            for(i = 1 ; i <= n; 1++){
                dequeue(q, &game)
            }
            // nama game disini adalah nama game yang akan dimainkan
            PLAYGAME(q);
        }
        else if(n == panjang){
            // kasus game tidak dimainkan karena semua game dalam queue game tepat sudah didequeue
            for(i = 1 ; i <= n ; i++){
                dequeue(q, &game);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n")
        }
        else{
            for(i = 1 ; i <= panjang ; i++){
                dequeue(q, &game);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n")
        }
    }
    else{
        // kasus queue game kosong
        printf("queue masih kosong, silahkan QUEUE GAME untuk menambahkan game ke dalam antrian");
    }
}
