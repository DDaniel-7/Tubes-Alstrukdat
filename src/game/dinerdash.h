# include "boolean.h"
# include "../adt/queuediner.h"

# ifndef dinerdash_H
# define dinerdash_H

boolean isIn(QueueDiner q, int food);
/* Mengembalikan true jika food dalam queue */

void removeisIn(QueueDiner *q, int *food, int *durations, int *endurance, int *price);
/*IS : queue sembarang;
       food bisa tidak ad di dlm queue;
  FS : queue dengan makanan yg ad diremove;
*/

void Printqorder(QueueDiner q);
/*IS : queue bisa kosong
  FS : menampilkan daftar pesanan */

void Printqcooking(QueueDiner q);
/*IS : queue bisa kosong
  FS : menampilkan daftar masakan yang dimasak*/

void Printqserving(QueueDiner q);
/*IS : queue bisa kosong
  FS : menampilkan daftar masakan yang selesai dimasak*/

void printall(QueueDiner qorder, QueueDiner qcook, int balance);

void cook(QueueDiner qorder, QueueDiner *qcook, int food);
/*IS : */

void serve(QueueDiner *qorder, QueueDiner *qcook, int food, int *serve, int *balance, int *n);

void turn(QueueDiner *q);

boolean IsEndGame(QueueDiner q, int serving);

boolean IsAvail(QueueDiner q);

void dinerdash();

#endif


