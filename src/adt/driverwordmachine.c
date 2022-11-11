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
    char *angka;
    int nomor;
    int panjang;
    char *cekPanjang;

    STARTWORD();
    // menuliskan kata yang berada dalam currentWord
    printf("%s", currentWord.contents);
    if(!endWord){
        // masih ada kata berikutnya
        // kata yang ditampilkan adalah kata selanjutnya
        printf("%s", currentWord.contents);
    }

    cek = "kataPertama kataKedua";
    kataPertama = firstword(cek);
    kataKedua = secondWord(cek);
    printf("%s", kataPertama);
    printf("%s", kataKedua);

    kataSatu = "sama";
    kataDua = "sama";
    kataTiga = "beda";
    kataEmpat = "bedadong";

    if(isStrEq(kataSatu, kataDua)){
        // kata satu dan kata dua sama
        printf("kata satu dan kata dua sama\n");
    }
    if(!isStrEq(kataDua, kataTiga)){
        // kata dua dan kata tiga beda
        printf("kata dua dan kata tiga beda\n");
    }
    // scan input dari dari pita menjadi sebuah masukan
    masukan = scaninput();
    angka = "1";
    // mengkonversi sebuah string menjadi integer;
    nomor = ScanNum(currentWord);
    cekPanjang = "panjangKata";
    panjang = LengthStr(cekPanjang);
    printf("Panjang kata adalah : %d\n", panjang);

    return 0;
}
