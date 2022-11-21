#include <stdio.h>
#include "map.h"
#include "wordmachine.h"
#include "charmachine.h"

void CreateEmptyMap(Map *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
    return(M.Count == Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M){
    return(M.Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k){
    if(IsMemberMap(M,k)){
        int i = 0;
        while(!IsStrEq(M.Elements[i].Key,k)){
            i++;
        }
        return(M.Elements[i].Value);
    }
    else{
        return(Undefined);
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v){
    if(IsEmptyMap(*M)){
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
        (*M).Count = 1;
    }
    else{
        if(!IsMemberMap((*M),k)){
            int i = 0;
            while(i != ((*M).Count)){
                i++;
            }
            (*M).Elements[i].Key = k;
            (*M).Elements[i].Value = v;
            (*M).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k){
    if(IsMemberMap((*M),k)){
        int i = 0;
        while(i != ((*M).Count-1) && (*M).Elements[i].Key != k){
            i++;
        }
        int idxtemp;
        idxtemp = i;
        for(idxtemp ; idxtemp <= (*M).Count-1 ; idxtemp++){
            (*M).Elements[idxtemp] = (*M).Elements[idxtemp+1];
        }
        (*M).Elements[(*M).Count-1].Key = '\0';
        (*M).Elements[(*M).Count-1].Value = Undefined;
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k){
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < M.Count && ada == false)
	{
		if (IsStrEq(M.Elements[i].Key,k))
		{
			ada = true;
		}
		i++;
	}
	return ada;
}
/* Mengembalikan true jika k adalah member dari M */