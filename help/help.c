#include <stdio.h>


void HELP()
{
    printf("---------- HELP ----------\n");
    printf("Berikut Pilihan Command yang Tersedia \n");
    printf("1. START : Membaca file konfigurasi sistem agar BNMO dapat berjalan\n");
    printf("2. LOAD : Membaca save file <filename> yang berisi list game yang dapat dimainkan, histori dan scoreboard game\n");
    printf("3. SAVE : menyimpan state game pemain saat ini ke dalam suatu file\n");
    printf("4. CREATEGAME : menambahkan game baru pada daftar game\n");
    printf("5. LISTGAME : menampilkan daftar game yang disediakan oleh sistem\n");
    printf("6. DELETEGAME : menghapus sebuah game dari daftar game\n");
    printf("7. QUEUEGAME : mendaftarkan permainan kedalam list\n");
    printf("8. PLAYGAME : memainkan sebuah permainan yang berada pada urutan paling atas\n");
    printf("9. SKIPGAME : melewatkan permainan sebanyak n\n");
    printf("10. QUIT : Keluar dari Program\n");
    printf("11. HELP : Bantuan command-command pada BNMO\n");
}

/*int main()
{
    HELP();
    return 0;
}*/
