# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(){
    printf("Selamat Datang di Diner Dash!\n");
    int saldo = 0;
    char command;
    int i ;
    printf("SALDO : %d",saldo);
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga \n");
    printf("---------------------------------------------\n");
    printf("M0      | 2              | 3         | 15000 \n");
    printf("M1      | 3              | 1         | 15000 \n");
    printf("M2      | 1              | 4         | 15000 \n");
    printf("\n");
    printf("Daftar Makanan yang sedang dimasak");
    printf("Makanan | Sisa durasi memasak \n");
    printf("--------------------------------\n");
    printf("        |                       \n");
    printf("\n");
    printf("Daftar Makanan yang dapat disajikan \n");
    printf("Makanan | Sisa ketahanan makanan \n");
    printf("-------------------------------- \n");
    printf("        |                       \n");
    printf("MASUKKAN COMMAND: ");
    scanf(" %c", &command);
    
    return 0;
}
