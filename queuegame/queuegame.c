// 1. Output daftar antrian game pertama kosong(?) jd bikin dulu queue kosong
// 2. tampilin daftar game dari listgame (caranya gimana??)
#include "queue.h"
#include "arraydin.h"
#include "wordmachine.h"
#include <stdio.h>
void QueueGame(ArrayDin *array, Queue q){
	// Createqueue(&q);
	int i;
    Word num;
	for(i=0;i<(Length(*array));i++){
		printf("%d. %s\n", (i+1), (&(*array).A[i]));
	}
	printf("Nomor game yang mau ditambahkan ke antrian : ");
	// ScanNum(num);
	if (ScanNum(num) >= 1 && ScanNum(num) <= (Length(*array)-1)){
		enqueue(&q, (*array).A[ScanNum(num)]);
		printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
	}
	else {
		printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list\n");
    }