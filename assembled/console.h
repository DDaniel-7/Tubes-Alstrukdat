#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ADT
#include "queue.h"
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "arraydin.h" 
#include "boolean.h"

//GAME
#include "rng.h"
#include "toh.h"
//#include "dinerdash.h"

/////////////COMMAND/////////////
void start(ArrayDin *arr);

//void load();

void saveGame(ArrayDin l, FILE *file);

void save(char *namaFile, ArrayDin arr);

void CreateGame(ArrayDin *array);

void ListGame(ArrayDin *array);

void DeleteGame(ArrayDin *array, Queue *queue);

void QueueGame(ArrayDin *array, Queue *q);

void PlayGame(Queue *q);

void SkipGame(Queue *q, int n);

void quit(Queue *q);

void help();

void CommandLain();

#endif
