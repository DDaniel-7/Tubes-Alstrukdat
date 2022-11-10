#include <stdio.h>
#include "arraydin.h"
#include "wordmachine.h"

int main(){
    ArrayDin arr;
    arr = MakeArrayDin(&arr);
    if (IsEmpty(arr)){
        printf("Array baru masih kosong\n");
    }
    printf("Panjang array: %d\n",Length(arr));
    printf("Kapasitas array: %d\n",GetCapacity(arr));
    char *nama;
    for (int i=0;i<arr.Capacity;i++){
        nama = scaninput(); // Diisi nama game1,game2, sampai game 10
        InsertAt(&arr,nama,i);
    }
    PrintArrayDin(arr);
    printf("Panjang array sekarang: %d\n",Length(arr));
    printf("Kapasitas array sekarang: %d\n",GetCapacity(arr));
    printf("arr setelah di reverse dan dimasukan ke temp:\n ");
    ReverseArrayDin(&arr);
    ArrayDin temp;
    temp = MakeArrayDin(&temp);
    temp = CopyArrayDin(arr);
    PrintArrayDin(temp);
    for (int i=0;i<arr.Capacity;i++){
        DeleteAt(&arr,i);
    }
    printf("arr setelah didelete:\n ");
    PrintArrayDin(arr);
    printf("Panjang array setelah delete: %d\n",Length(arr));
    printf("Kapasitas array setelah delete: %d\n",GetCapacity(arr));
    printf("Nilai yang ingin dicari?");
    char *cari;
    cari = scaninput();
    IdxType idx;
    idx = SearchArrayDin(arr,cari);
    printf("indeks nilai yang dicari, (-1) jika tidak ada: %d\n",idx);
    DeallocateArrayDin(&temp);
    printf("isi temp sekarang: \n");
    PrintArrayDin(temp);
    return 0;
}