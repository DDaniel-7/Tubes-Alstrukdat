#ifndef __SKIP_GAME__
#define __SKIP_GAME__
void skipgame(int n, Queue *q);
    // I.S. queue game terdefinisi dan mungkin kosong
    // F.S. melakukan dequeue n element q pertama dan menjalankan game ke n+1
    //      jika n lebih besar dari jumlah game dalam queue game, maka akan memberikan pesan kesalahan
#endif