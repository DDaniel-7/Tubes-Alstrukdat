#include <stdio.h>
#include "boolean.h"
#include "queue.h"


void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q)= IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return IDX_HEAD(q)== IDX_UNDEF && IDX_TAIL(q)== IDX_UNDEF;
}
boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return IDX_HEAD(q)== 0 && IDX_TAIL(q)== (CAPACITYQUEUE -1);
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmptyQueue(q)) {
        return 0;
    } else {
        if (IDX_TAIL(q) < IDX_HEAD(q)) {
            return (CAPACITYQUEUE - (IDX_HEAD(q) - IDX_TAIL(q) - 1));
        } else {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    if(isEmptyQueue(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        if(IDX_TAIL(*q) == CAPACITYQUEUE-1){
            IDX_TAIL(*q) = 0;
        }
        else{
            IDX_TAIL(*q)+=1;
        }
    }
    TAIL(*q) = val;
}
void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    *val = HEAD(*q);
    if(IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else if (IDX_HEAD(*q)== CAPACITYQUEUE -1){
        IDX_HEAD(*q)=0;
    }
    else{
        IDX_HEAD(*q)++;
    }
}
/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    printf("[");
    if (!(isEmptyQueue(q))) {
        if (IDX_HEAD(q) <= IDX_TAIL(q)) {
            for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
                printf("%s", q.buffer[i]);
                if (i < IDX_TAIL(q)) {
                    printf(",");
                }
            }
        } else {
            for (int i = IDX_HEAD(q); i < CAPACITYQUEUE; i++) {
                printf("%s,", q.buffer[i]);
            }
            for (int i = 0; i <= IDX_TAIL(q); i++){
                printf("%s", q.buffer[i]);
                if (i < IDX_TAIL(q)) {
                    printf(",");
                }
            }            
        }
    }
    printf("]\n");
}