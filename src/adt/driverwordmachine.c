#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

int main(){
    boolean endWord;
    Word currentWord;
    static FILE *pita;
    char *cek;
    char *kataPertama;
    char*kataKedua;
    char *kataSatu;
    char *kataDua;
    char *kataTiga;
    char *kataEmpat;
    char *masukan;
    int panjang;
    char *cekPanjang;

    cek = "kataPertama kataKedua";
    kataPertama = firstword(cek);
    kataKedua = secondword(cek);
    printf("%s\n", kataPertama);
    printf("%s\n", kataKedua);

    kataSatu = "sama";
    kataDua = "sama";
    kataTiga = "beda";
    kataEmpat = "bedadong";

    if(IsStrEq(kataSatu, kataDua)){
        // kata satu dan kata dua sama
        printf("kata satu dan kata dua sama\n");
    }
    if(!IsStrEq(kataDua, kataTiga)){
        // kata dua dan kata tiga beda
        printf("kata dua dan kata tiga beda\n");
    }
    
    printf("Masukkan input kata : ");
    masukan = scaninput();
    printf("Kata adalah : %s\n",masukan);
    panjang = LengthStr(masukan);
    printf("Panjang kata adalah : %d\n", panjang);

    char* concat = "pleasebemine";
    concatstringbaru(concat);





    return 0;
}
