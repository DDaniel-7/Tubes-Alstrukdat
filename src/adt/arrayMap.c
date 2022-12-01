#include <stdio.h>
#include "arrayMap.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */


void InsertLastGame (TabMap *arrmapgame){
    Map m;
    CreateEmptyMap(&m);
    SetElArrMap(arrmapgame , arrmapgame->NeffArrayMap , m);
    }

void CreateEmptyArrMap(TabMap *T)
{
    T->NeffArrayMap = 0;
    InsertLastGame(T);
    InsertLastGame(T);
    InsertLastGame(T);
    InsertLastGame(T);
    InsertLastGame(T);

}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxArrayMap-IdxMinArrayMap+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(TabMap T)
{
    return (T.NeffArrayMap);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArrMap(TabMap T)
{
    return (IdxMaxArrayMap - IdxMinArrayMap + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxTypeArrayMap GetFirstIdxArrMap(TabMap T)
{
    return IdxMinArrayMap;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxTypeArrayMap GetLastIdxArrMap(TabMap T)
{
    return (NbElmtArrMap(T) - 1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayMap GetElmtArrMap(TabMap T, IdxTypeArrayMap i)
{
    return (T.TIMap[i]);
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArrMap(TabMap Tin, TabMap *Tout)
{
    (*Tout).NeffArrayMap = Tin.NeffArrayMap;
    int i;
    for (i = IdxMinArrayMap; i <= IdxMaxArrayMap; i++)
    {
        (*Tout).TIMap[i] = Tin.TIMap[i];
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElArrMap(TabMap *T, IdxTypeArrayMap i, ElTypeArrayMap v)
{
    (*T).TIMap[i] = v;
    if (i == GetLastIdxArrMap(*T) + 1)
    {
        (*T).NeffArrayMap++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArrMap(TabMap *T, IdxTypeArrayMap N)
{
    (*T).NeffArrayMap = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrMap(TabMap T, IdxTypeArrayMap i)
{
    return ((i >= IdxMinArrayMap) && (i <= IdxMaxArrayMap));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEffArrMap(TabMap T, IdxTypeArrayMap i)
{
    return ((i >= GetFirstIdxArrMap(T)) && (i <= GetLastIdxArrMap(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap(TabMap T)
{
    return (NbElmtArrMap(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArrMap(TabMap T)
{
    return (NbElmtArrMap(T) == MaxNbElArrMap(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertFirstArrMap(TabMap *T, ElTypeArrayMap v)
{
    int i;
    for (i = NbElmtArrMap(*T); i > 0; i--)
    {
        (*T).TIMap[i] = (*T).TIMap[i - 1];
    }
    (*T).TIMap[0] = v;
    (*T).NeffArrayMap++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtArrMap(TabMap *T, ElTypeArrayMap v, IdxTypeArrayMap i)
{
    int j;
    for (j = NbElmtArrMap(*T); j > i; j--)
    {
        (*T).TIMap[j] = (*T).TIMap[j - 1];
    }
    (*T).TIMap[i] = v;
    (*T).NeffArrayMap++;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastArrMap(TabMap *T, ElTypeArrayMap v)
{
    (*T).TIMap[NbElmtArrMap(*T)] = v;
    (*T).NeffArrayMap++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstArrMap(TabMap *T)
{
    int i;
    for (i = 0; i < NbElmtArrMap(*T); i++)
    {
        (*T).TIMap[i] = (*T).TIMap[i + 1];
    }
    (*T).NeffArrayMap--;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void JustDeleteAtArrMap(TabMap *T, IdxTypeArrayMap i)
{
    int j;
    int k;
    Map temp1;
    Map temp2;
    CreateEmptyMap(&temp1);
    for (j = 0; j < NbElmtArrMap(*T); j++){
        if (j == i){
            (*T).TIMap[j] = temp1;
        }
    }
}
void DeleteAtArrMap(TabMap *T, IdxTypeArrayMap i)
{
    int j;
    for (j = i; j < NbElmtArrMap(*T); j++)
    {
        (*T).TIMap[j] = (*T).TIMap[j + 1];
    }
    (*T).NeffArrayMap--;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastArrMap(TabMap *T)
{
    (*T).NeffArrayMap--;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
