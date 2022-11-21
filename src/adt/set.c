#include <stdio.h>
#include "set.h"
#include "wordmachine.h"
#include "charmachine.h"

void CreateEmptySet(Set *S){
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    return((S).Count == Nil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S){
    return((S).Count == MaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, char* Elmt){

	if (IsEmptySet(*S))
	{
		(*S).Count++;
		(*S).Elements[0] = Elmt;
	}
	else
	{
		if (!IsMemberSet((*S),Elmt))
		{
			(*S).Count++;
			(*S).Elements[(*S).Count-1] = Elmt;
		}
	}

}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, char* Elmt)
{

	int idx;
	idx = 0;
	if (IsMemberSet((*S),Elmt))
	{
		while ((*S).Elements[idx] != Elmt)
		{
			idx++;
		}
		for (idx;idx<=(*S).Count-1;idx++)
		{
			(*S).Elements[idx] = (*S).Elements[idx+1];
		}
		(*S).Elements[(*S).Count-1] = '\0';
		(*S).Count--;
	}

}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, char* Elmt){
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < S.Count && ada == false)
	{
		if (IsStrEq(S.Elements[i],Elmt))
		{
			ada = true;
		}
		i++;
	}
	return ada;
}
/* Mengembalikan true jika Elmt adalah member dari S */