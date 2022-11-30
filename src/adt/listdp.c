#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyLDP (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L) == Nil && Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLDP (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L)=Nil;
    Last(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiLDP (char X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P = (address) malloc(1*sizeof(address));
	if (P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
		return P;
	}
	else
	{
		return 0;
	}
}
void DealokasiLDP (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchLDP (List L, char X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	boolean found;
	found = false;
	P = First(L);
	while (P != Nil && Info(P) != X)
	{
		P = Next(P);		
	}
	return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLDP (List *L, char X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */ 
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;
	P = AlokasiLDP(X);
	if (P != Nil) 
	{
		InsertFirstLDP(L,P);
	}
}
void InsVLastLDP (List *L, char X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P;
	P = AlokasiLDP(X);
	if (P != Nil)
	{
		InsertLastLDP(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLDP (List *L, char *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirstLDP(L,&P);
	*X = Info(P);
	DealokasiLDP(P);
}

void DelVLastLDP (List *L, char *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	DelLastLDP(L,&P);
	*X = Info(P);
	DealokasiLDP(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLDP (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (IsEmptyLDP(*L))
	{
		First(*L) = P;
		Last(*L) = P;
		Next(P) = Nil;
		Prev(P) = Nil;
	}
	else
	{
		InsertBeforeLDP(L,P,First(*L));
	}
}
void InsertLastLDP (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyLDP(*L))
	{
		First(*L) = P;
		Last(*L) = P;
		Next(P) = Nil;
		Prev(P) = Nil;
	}
	else
	{
		InsertAfterLDP(L,P,Last(*L));
	}
}
void InsertAfterLDP (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	if (Next(Prec) != Nil)
	{
		Prev(Next(Prec)) = P; 
	}
	else
	{
		Last(*L) = P;
	}
	Next(Prec) = P;
	Prev(P) = Prec;
}
void InsertBeforeLDP (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
{
	Prev(P) = Prev(Succ);
	if (Prev(Succ) != Nil)
	{
		Next(Prev(Succ)) = P;
	}
	else
	{
		First(*L) = P;
	}
	Next(P) = Succ;
	Prev(Succ) = P;
}
void DelFirstLDP (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	if (First(*L) == Nil)
	{
		CreateEmptyLDP(L);
	}
	else
	{
		Prev(First(*L)) = Nil;
	}
}
void DelLastLDP (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = Last(*L);
	Last(*L) = Prev(Last(*L));
	if (Last(*L) == Nil)
	{
		CreateEmptyLDP(L);
	}
	else
	{
		Next(Last(*L)) = Nil; 
	}
}
void DelPLDP (List *L, char X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = SearchLDP(*L,X);
    address Q = Last(*L);
    if (P==First(*L)){
        DelFirstLDP(L,&P);
    }else if(P==Last(*L)){
        DelLastLDP(L,&P);
    }else{
        while (Q!=P){
            Q->coor.x=Prev(Q)->coor.x;
            Q->coor.y=Prev(Q)->coor.y;
        }
        Next(Prev(P))=Next(P);
        Prev(Next(P))=Prev(P);
    }
    DealokasiLDP(P);
}
void DelAfterLDP (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	if (Next(Prec) != Nil)
	{
		Prev(Next(*Pdel)) = Prec;
	}
	else
	{
		Last(*L) = Prec;
	}
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}
void DelBeforeLDP (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Prev(Succ);
	Prev(Succ) = Prev(*Pdel);
	if (Prev(Succ) == Nil)
	{
		First(*L) = Succ;
	}
	else
	{
		Next(Prev(*Pdel)) = Succ; 
	}
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardLDP (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyLDP(L)){
        address P=First(L);
        printf("%c",Info(P));
        P=Next(P);
        while ((P)!=Nil){
            printf(",%c",Info(P));
            P=Next(P);
        }
    }
    printf("]");
}	
void PrintBackwardLDP (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyLDP(L)){
        address P=Last(L);
        printf("%d",Info(P));
        P=Prev(P);
        while ((P)!=Nil){
            printf(",%d",Info(P));
            P=Prev(P);
        }
    }
    printf("]");
}	


