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
#include "boolean.h"

//GAME
#include "game/rng.h"
#include "game/toh.h"
#include "game/dinerdash.h"


/////////////COMMAND/////////////
void start(ArrayDin *arr);

void saveGame(ArrayDin l, FILE *file);

void save(char *namaFile, ArrayDin arr, Map mapTOH, Map mapDinner, Map mapSnake, Map mapRNG, Map mapHangman, Map mapTambahan);

void CreateGame(ArrayDin *array);

void ListGame(ArrayDin *array);

void DeleteGame(ArrayDin *array, Queue *queue);

void QueueGame(ArrayDin *array, Queue *q);

void PlayGame(Queue *q);

void SkipGame(Queue *q, int n);

void quit(Queue *q);

void help();

void CommandLain();

void Load(ArrayDin *arraygame, char *namafile);

void *my_memset(void *b, int c, int len);

void Donat();

void SAVESCOREBOARD (Map *mapGame, int skor); // ini tapi belum masuk ke file konfigurasi

void SCOREBOARD (Map *mapTOH, Map *mapDinner, Map *mapSnake, Map *mapRNG, Map *mapHangman, Map *mapTambahan);

void RESETSCORE (Map *mapTOH, Map *mapDinner, Map *mapSnake, Map *mapRNG, Map *mapHangman, ArrayDin *array);

void SAVESCORE(Map mapGame,FILE * txt);

void RESETHISTORY(Stack* Hist);

#endif
