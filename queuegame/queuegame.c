// 1. Output daftar antrian game pertama kosong(?) jd bikin dulu queue kosong
// 2. tampilin daftar game dari listgame (caranya gimana??)
#include "queue.h"
#include "arraydin.h"
#include "wordmachine.h"
#include "listgame.h"
#include <stdio.h>
#include "stdlib.h"


void QueueGame(ArrayDin *array, Queue *q){
	int i, nomorint; 
	char* nomorgame;
    Word num;
	ListGame(array);
	printf("Nomor game yang mau ditambahkan ke antrian : ");
	nomorgame = scaninput();
	nomorint = atoi(nomorgame);
	if (nomorint >= 1 && nomorint <= (Length(*array))){
		enqueue(q, (*array).A[nomorint-1]);
		printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
	}
	else {
		printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list\n");
    }
}