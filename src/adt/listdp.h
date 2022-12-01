/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan addressLDP adalah pointer */
/* char adalah integer */

#ifndef listdp_H
#define listdp_H

#include "boolean.h"

#define NilLDP NULL
#define UndefLDP 99999

/* Definisi Type Data */
typedef struct tElmtlist *addressLDP;

typedef struct{
	int x;
	int y;
} POINT;

typedef struct tElmtlist { 
	int info;
	addressLDP next;
	addressLDP prev;
	POINT coor;
} ElmtList;


typedef struct {
	addressLDP First;
	addressLDP Last;
} List;


/* Definisi list : */
/* List kosong : First(L) = NilLDP dan Last(L) = NilLDP */
/* Setiap elemen dengan addressLDP P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define Absis(P) (P)->coor.x
#define Ordinat(P) (P)->coor.y

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLDP (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLDP (List *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressLDP AlokasiLDP (char X);
addressLDP AlokasiLDPEkor (char X);
/* Mengirimkan addressLDP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLDP tidak NilLDP. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilLDP, Prev(P)=NilLDP */
/* Jika alokasi gagal, mengirimkan NilLDP. */
void DealokasiLDP (addressLDP P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLDP P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLDP SearchLDP (List L, char X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressLDP elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLDP */

/****************** PRIMITIF BERDASARKAN NilLDPAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLDP (List *L, char X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilLDPai X jika alokasi berhasil */
void InsVLastLDP (List *L, char X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLDPai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLDP (List *L, char *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilLDPai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastLDP (List *L, char *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilLDPai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLDP (List *L, addressLDP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLDP P sebagai elemen pertama */
void InsertLastLDP (List *L, addressLDP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterLDP (List *L, addressLDP P, addressLDP Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeLDP (List *L, addressLDP P, addressLDP Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLDP (List *L, addressLDP *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastLDP (List *L, addressLDP *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPLDP (List *L, char X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLDP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfterLDP (List *L, addressLDP *Pdel, addressLDP Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeLDP (List *L, addressLDP *Pdel, addressLDP Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardLDP (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilLDPai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardLDP (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berNilLDPai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif