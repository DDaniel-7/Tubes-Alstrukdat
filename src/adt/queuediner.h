/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEDINER_H
#define QUEUEDINER_H

#include "boolean.h"

#define IDX_UNDEF -1
#define MAX 100

/* Definisi elemen dan address */

typedef struct {
    int food;
    int durations;
    int endurance;
    int price;
}ElTypeDiner;

typedef struct {
	ElTypeDiner buffer[MAX]; 
	int idxHead;
	int idxTail;
} QueueDiner;



/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD_food(q) (q).buffer[(q).idxHead].food
#define     TAIL_food(q) (q).buffer[(q).idxTail].food
#define     HEAD_durations(q) (q).buffer[(q).idxHead].durations
#define     TAIL_durations(q) (q).buffer[(q).idxTail].durations
#define     HEAD_endurance(q) (q).buffer[(q).idxHead].endurance
#define     TAIL_endurance(q) (q).buffer[(q).idxTail].endurance
#define     HEAD_price(q) (q).buffer[(q).idxHead].price
#define     TAIL_price(q) (q).buffer[(q).idxTail].price

/* *** Kreator *** */
void CreateQueueDiner(QueueDiner *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDiner(QueueDiner q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullDiner(QueueDiner q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthDiner(QueueDiner q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueDiner(QueueDiner *q, int food, int durations, int endurance, int price);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueDiner(QueueDiner *q, int *food, int *durations, int *endurance, int *price);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */


# endif