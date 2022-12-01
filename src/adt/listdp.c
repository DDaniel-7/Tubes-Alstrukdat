#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyLDP (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L) == NilLDP && Last(L) == NilLDP);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLDP (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L)=NilLDP;
    Last(*L)=NilLDP;
}

/****************** Manajemen Memori ******************/
addressLDP AlokasiLDP (char X)
/* Mengirimkan addressLDP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLDP tidak NilLDP. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilLDP, Prev(P)=NilLDP */
/* Jika alokasi gagal, mengirimkan NilLDP. */
{
	addressLDP P = (addressLDP) malloc(1*sizeof(addressLDP));
	while(P == NilLDP){
		
		P = (addressLDP) malloc(1*sizeof(addressLDP));
	}

	if (P != NilLDP)
	{
		Info(P) = X;
		Next(P) = NilLDP;
		Prev(P) = NilLDP;
		return P;
	}

}

addressLDP AlokasiLDPEkor (char X)
/* Mengirimkan addressLDP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLDP tidak NilLDP. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilLDP, Prev(P)=NilLDP */
/* Jika alokasi gagal, mengirimkan NilLDP. */
{
	ElmtList* P=NilLDP;
	P = (ElmtList*) malloc(sizeof(ElmtList));
	if (P != NilLDP)
	{
		Info(P) = X;
		Next(P) = NilLDP;
		Prev(P) = NilLDP;
		return P;
	}
	else{
		return NilLDP;
	}

}
void DealokasiLDP (addressLDP P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLDP P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLDP SearchLDP (List L, char X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressLDP elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLDP */
{
	addressLDP P;
	boolean found;
	found = false;
	P = First(L);
	while (P != NilLDP && Info(P) != X)
	{
		P = Next(P);		
	}
	return P;
}

/****************** PRIMITIF BERDASARKAN NilLDPAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLDP (List *L, char X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */ 
/* menambahkan elemen pertama dengan NilLDPai X jika alokasi berhasil */
{
	addressLDP P;
	P = AlokasiLDP(X);
	if (P != NilLDP) 
	{
		InsertFirstLDP(L,P);
	}
}
void InsVLastLDP (List *L, char X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLDPai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	addressLDP P;
	P = AlokasiLDP(X);
	if (P != NilLDP)
	{
		InsertLastLDP(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLDP (List *L, char *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilLDPai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	addressLDP P;
	DelFirstLDP(L,&P);
	*X = Info(P);
	DealokasiLDP(P);
}

void DelVLastLDP (List *L, char *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilLDPai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	addressLDP P;
	DelLastLDP(L,&P);
	*X = Info(P);
	DealokasiLDP(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLDP (List *L, addressLDP P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLDP P sebagai elemen pertama */
{
	if (IsEmptyLDP(*L))
	{
		First(*L) = P;
		Last(*L) = P;
		Next(P) = NilLDP;
		Prev(P) = NilLDP;
	}
	else
	{
		InsertBeforeLDP(L,P,First(*L));
	}
}
void InsertLastLDP (List *L, addressLDP P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyLDP(*L))
	{
		First(*L) = P;
		Last(*L) = P;
		Next(P) = NilLDP;
		Prev(P) = NilLDP;
	}
	else
	{
		InsertAfterLDP(L,P,Last(*L));
	}
}
void InsertAfterLDP (List *L, addressLDP P, addressLDP Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	if (Next(Prec) != NilLDP)
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
void InsertBeforeLDP (List *L, addressLDP P, addressLDP Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
{
	Prev(P) = Prev(Succ);
	if (Prev(Succ) != NilLDP)
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
void DelFirstLDP (List *L, addressLDP *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	if (First(*L) == NilLDP)
	{
		CreateEmptyLDP(L);
	}
	else
	{
		Prev(First(*L)) = NilLDP;
	}
}
void DelLastLDP (List *L, addressLDP *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = Last(*L);
	Last(*L) = Prev(Last(*L));
	if (Last(*L) == NilLDP)
	{
		CreateEmptyLDP(L);
	}
	else
	{
		Next(Last(*L)) = NilLDP; 
	}
}
void DelPLDP (List *L, char X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLDP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressLDP P = SearchLDP(*L,X);
    addressLDP Q = Last(*L);
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
void DelAfterLDP (List *L, addressLDP *Pdel, addressLDP Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	if (Next(Prec) != NilLDP)
	{
		Prev(Next(*Pdel)) = Prec;
	}
	else
	{
		Last(*L) = Prec;
	}
	Next(*Pdel) = NilLDP;
	Prev(*Pdel) = NilLDP;
}
void DelBeforeLDP (List *L, addressLDP *Pdel, addressLDP Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Prev(Succ);
	Prev(Succ) = Prev(*Pdel);
	if (Prev(Succ) == NilLDP)
	{
		First(*L) = Succ;
	}
	else
	{
		Next(Prev(*Pdel)) = Succ; 
	}
	Next(*Pdel) = NilLDP;
	Prev(*Pdel) = NilLDP;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardLDP (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilLDPai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyLDP(L)){
        addressLDP P=First(L);
        printf("%c",Info(P));
        P=Next(P);
        while ((P)!=NilLDP){
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
/* Contoh : jika ada tiga elemen berNilLDPai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyLDP(L)){
        addressLDP P=Last(L);
        printf("%d",Info(P));
        P=Prev(P);
        while ((P)!=NilLDP){
            printf(",%d",Info(P));
            P=Prev(P);
        }
    }
    printf("]");
}	


