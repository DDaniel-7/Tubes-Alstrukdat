# include "boolean.h"
# include "queuediner.h"

# ifndef dinerdash_H
# define dinerdash_H

boolean isIn(Queue q, int food);
/* Mengembalikan true jika food dalam queue */

void removeisIn(Queue *q, int *food, int *durations, int *endurance, int *price);
/*IS : queue sembarang;
       food bisa tidak ad di dlm queue;
  FS : queue dengan makanan yg ad diremove;
*/

void Printqorder(Queue q);
/*IS : queue bisa kosong
  FS : menampilkan daftar pesanan */

void Printqcooking(Queue q);
/*IS : queue bisa kosong
  FS : menampilkan daftar masakan yang dimasak*/

void Printqserving(Queue q);
/*IS : queue bisa kosong
  FS : menampilkan daftar masakan yang selesai dimasak*/

void printall(Queue qorder, Queue qcook, int balance);

void cook(Queue qorder, Queue *qcook, int food);
/*IS : */

void serve(Queue *qorder, Queue *qcook, int food, int *serve, int *balance, int *n);

void turn(Queue *q);

boolean IsEndGame(Queue q, int serving);

boolean IsAvail(Queue q);

void dinerdash();

#endif


