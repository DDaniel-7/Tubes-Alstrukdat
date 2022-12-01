#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ADT
#include "adt/queue.h"
#include "adt/stack.h"
#include "adt/charmachine.h"
#include "adt/wordmachine.h"
#include "adt/arraydin.h"
#include "adt/queuediner.h"
#include "adt/map.h"  
#include "adt/arrayMap.h"
#include "adt/listdp.h"
#include "adt/set.h"
#include "boolean.h"

//GAME
#include "game/rng.h"
#include "game/toh.h"
#include "game/dinerdash.h"
#include "game/som.h"


/////////////COMMAND/////////////
void start(ArrayDin *arr, TabMap *arrmapsb);

void saveGame(ArrayDin l, FILE *file);

void save(char *namaFile, ArrayDin arr, TabMap arrmapsb);

void CreateGame(ArrayDin *array,TabMap *arrmapsb);

void ListGame(ArrayDin *array);

void DeleteGame(ArrayDin *array, Queue *queue,TabMap *arrmapsb);

void QueueGame(ArrayDin *array, Queue *q);

void PlayGame(Queue *q,TabMap *arrmapsb);

void SkipGame(Queue *q, int n, TabMap *arrmapsb);

void quit(Queue *q);

void help();

void CommandLain();

void Load(ArrayDin *arraygame, char *namafile, TabMap *arrmapsb);

void *my_memset(void *b, int c, int len);

void Donat();

void SAVESCOREBOARD (Map *mapGame, int skor); // ini tapi belum masuk ke file konfigurasi

void PrintScore (Map scoreboard, char *nama);

void SCOREBOARD (TabMap arrscore, ArrayDin listgame);

void RESETSCORE (TabMap *SB, ArrayDin *listgame);


void SAVEFILESB (Map scoreboard, FILE *txt);

void history(Stack s, int banyak);

void RESETHISTORY(Stack* Hist);

#endif
