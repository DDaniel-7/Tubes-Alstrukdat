#include <stdio.h>
#include "prioqueue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return((Head(Q) == Nil) && (Tail(Q)==Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
    return (NBElmt(Q)==MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q){
    if (IsEmpty(Q))
    {
        return 0;
    }
    else
    {
        return (Tail(Q) - Head(Q) + 1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
    if ((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }else // Alokasi gagal
    {
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
if (IsEmpty(*Q)){
        Head(*Q)=1;
    }
    Tail(*Q)=(Tail(*Q) % MaxEl(*Q)) + 1;

    Elmt(*Q,Tail(*Q))=X;
    address i=Tail(*Q);
    address before=Tail(*Q);
    boolean check=true;
    infotype temp;

    while (check && i!=Head(*Q)){
        if (before-1==0){
            before=MaxEl(*Q);
        } else {
            before--;
        }
        if (Prio(Elmt(*Q,before))<Prio(Elmt(*Q,i))){
            temp=Elmt(*Q,i);
            Elmt(*Q,i)=Elmt(*Q,before);
            Elmt(*Q,before)=temp;
        } else {
            check=false;
        }
        i=before;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void Del (Queue * Q, infotype * X){
    *X=InfoHead(*Q);
    if (NBElmt(*Q)==1) { // Kasus khusus 1 elemen
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    } else {
        if (Head(*Q)==MaxEl(*Q)){
            Head(*Q)=1;
        } else {
            Head(*Q)++;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintQueue (Queue Q){
    infotype X;
    while (!(IsEmpty(Q)))
    {
        printf ("%d %d\n", Prio(InfoHead(Q)), Info(InfoHead(Q)));
        Del(&Q,&X);
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/