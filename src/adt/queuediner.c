# include <stdio.h>
# include <stdlib.h>
# include "queuediner.h"

/* *** Kreator *** */
void CreateQueueDiner(QueueDiner *q){
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDiner(QueueDiner q){
  return((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));

}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullDiner(QueueDiner q){
    return (IDX_HEAD(q) == 0) && ((MAX+IDX_TAIL(q)-IDX_HEAD(q))%MAX == (MAX-1));

}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthDiner(QueueDiner q){
    if (isEmptyDiner(q))
        return 0;
    else
        return (((MAX+IDX_TAIL(q)-IDX_HEAD(q))%MAX)+1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueDiner(QueueDiner *q, int food, int durations, int endurance, int price){
    if (isEmptyDiner(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else {
        IDX_TAIL(*q) = ((IDX_TAIL(*q)+1)%MAX);
    }
    TAIL_food(*q) = food;
    TAIL_durations(*q) = durations;
    TAIL_endurance(*q) = endurance;
    TAIL_price(*q) = price;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueDiner(QueueDiner *q, int *food, int *durations, int *endurance, int *price){
    *food = HEAD_food(*q);
    *durations = HEAD_durations(*q);
    *endurance = HEAD_endurance(*q);
    *price = HEAD_price(*q);
    if (lengthDiner(*q) == 1) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) %MAX;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */