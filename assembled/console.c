#include "console.h"


void start(ArrayDin *arr){
    // memasukkan 5 permainan utama ke dalam list game
    //KAMUS LOKAL
    char* game1;
    char* game2;
    char* game3;
    char* game4;
    char* game5;


    // ALGORITMA
    game1 = "RNG";
    game2 = "DINER DASH";
    game3 = "DINOSAUR IN EARTH";
    game4 = "RISEWOMAN";
    game5 = "EIFFEL TOWER";
    InsertLast(arr, game1);
    InsertLast(arr, game2);
    InsertLast(arr, game3);
    InsertLast(arr, game4);
    InsertLast(arr, game5);

    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

////LOAD

void saveGame(ArrayDin l, FILE *file){
    // Prosedur menulis list dari game, baik history ataupun keseluruhan permainan kedalam suatu file txt

    // KAMUS LOKAL
    int ctr, i;
    char *judulGame;

    // ALGOROTMA
    ctr = 1;
    i = 0;
    fprintf(file, "%d\n", l.Neff); // jumalah gamenya
    while(ctr <= l.Neff){
        judulGame = l.A[i];
        fprintf(file, "%s\n", judulGame);
        ctr++;
        i++;
    }
}

void save(char *namaFile, ArrayDin arr){
    //fungsi melakukan save terhadap state dari permainan yang terkandung dalam array
    // dan menyimpannya dalam sebuah file konfigurasi txt
    // jika file sudah ada, maka akan ditanya konfirmasi untuk menimpa file yang sudah ada
    // KAMUS LOKAL
    FILE *fileOutput;

    // ALGORITMA
    fileOutput = fopen(("%s", namaFile), "w");
    saveGame(arr, fileOutput);
    fclose(fileOutput);
    printf("Save file berhasil disimpan\n");
}

void CreateGame(ArrayDin *array){
    char* gamestring;
    int i = 0;
    boolean found = false;
    printf("Masukkan game yang ingin ditambahkan : ");  
    gamestring = scaninput();
    while(found == false && i < (*array).Neff){
        if(IsStrEq(gamestring, array->A[i])){
            found = true;
        }
        i++;
    }
    if (found == true){
        printf("Game sudah ada di sistem\n");
    }
    else{
        InsertLast(array,gamestring);
        printf("Game berhasil ditambahkan.\n");
    }
}

void ListGame(ArrayDin *array){
    printf("Berikut adalah daftar game yang tersedia\n");
    int i;
    for(i = 0 ; i <= (Length(*array)-1) ; i++ ){
        printf("%d. %s\n",(i+1),array->A[i]);
    }

}

void DeleteGame(ArrayDin *array, Queue *queue){
    char* nomor;
    int intnomor,i;
    printf("Masukkan nomor game yang akan dihapus: ");
    nomor = scaninput();
    intnomor = atoi(nomor);
    if(intnomor == 1 || intnomor == 2 || intnomor == 3 || intnomor == 4 || intnomor == 5){
        printf("Game gagal dihapus!\n");
    }
    /// ELSE IF KALO ADA DI QUEUE
    else{
        i = 0;
        while((i+1) != intnomor){
            i++;
        }
        if(!isEmptyQueue(*queue)){
            int z = IDX_HEAD(*queue);
            boolean sama = false;
            while(z <= IDX_TAIL(*queue)){
                if(IsStrEq(array->A[i],(*queue).buffer[z])){
                    sama = true;
                }
                z++;
            }

            if (sama == true){
                printf("Game gagal dihapus!\n");
            }
            else{
                DeleteAt(array, i);
                printf("Game berhasil dihapus\n");
            }

        }
        else{
            DeleteAt(array, i);
            printf("Game berhasil dihapus\n");
        }
    }
}

void QueueGame(ArrayDin *array, Queue *q){
	int i, nomorint; 
	char* nomorgame;
    Word num;
	ListGame(array);
	printf("Nomor game yang mau ditambahkan ke antrian : ");
	nomorgame = scaninput();
	nomorint = atoi(nomorgame);
	if (nomorint >= 1 && nomorint <= (Length(*array))){
		enqueue(q, (*array).A[nomorint-1]);
		printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
	}
	else {
		printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list\n");
    }

}


void PlayGame(Queue *q)
{
    ElType val;
    if(!isEmptyQueue(*q))    //kalau queue game ada isinya maka,
    {
        printf("Berikut adalah daftar Game-mu\n");  //print q dulu

        int i,index = 1;
        for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++)
        {
            printf("%d. %s\n", index , (*q).buffer[i]);
            index++;
        }

        char *R = "RNG";
        char *DinDash = "DINER DASH";
        char *TOH = "TOH";
        if (IsStrEq(HEAD(*q), R)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            RNG();  // sesuaikan sama game RNG nanti

        }
        else if (IsStrEq(HEAD(*q), DinDash)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            printf("DD BERHASIL\n"); // APUS INI 
            //dinnerdash();  // sesuaikan sama game dinnerdash nanti
        }
        else if (IsStrEq(HEAD(*q), TOH)){
            printf("Loading %s ...\n", HEAD(*q));
            dequeue(q,&val);
            towerofhanoi();  // sesuaikan sama game dinnerdash nanti
        }
        else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", HEAD(*q));
            dequeue(q,&val);
        }
    }
    else    //kalau q nya masi kosong, maka panggil fungsi queuegame
    {
        printf("Belum ada game di QueueGame. Silahkan mengisi queue game terlebih dahulu\n");
    }
   
}


void SkipGame(Queue *q, int n){
    // I.S. queue game terdefinisi dan mungkin kosong
    // F.S. melakukan dequeue n element q pertama dan menjalankan game ke n+1
    //      jika n lebih besar dari jumlah game dalam queue game, maka akan memberikan pesan kesalahan

    // KAMUS LOKAL
    ElType game;
    int panjang, i;

    // ALGORITMA
    panjang = length(*q);
    if(!isEmptyQueue(*q)){
        // kasus queue game tidak kosong
        if(n < panjang){
            // kasus menjalankan game ke n+1
            for(i = 1 ; i <= n; i++){
                dequeue(q, &game);
            }
            // nama game disini adalah nama game yang akan dimainkan
            PlayGame(q);
        }
        else if(n == panjang){
            // kasus game tidak dimainkan karena semua game dalam queue game tepat sudah didequeue
            for(i = 1 ; i <= n ; i++){
                dequeue(q, &game);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        }
        else{
            for(i = 1 ; i <= panjang ; i++){
                dequeue(q, &game);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        }
    }
    else{
        // kasus queue game kosong
        printf("Queue masih kosong, silahkan QUEUE GAME untuk menambahkan game ke dalam antrian\n");
    }
}


void quit(Queue *q){
    printf("Anda keluar dari game BNMO\n");
    printf("Bye bye ...\n");
    CreateQueue(q);
}


void help()
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

