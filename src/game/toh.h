# include "../adt/stack.h"
# include "boolean.h"
# include "../adt/arrayMap.h"

# ifndef TOH_H
# define TOH_H

void tampilkarakter(char c, int n);

void tampil(Stack a, Stack b, Stack c, int n);

void proses(Stack *s1, Stack *s2, int steps);

int skor(int steps, int disk);

void towerofhanoi(TabMap *arrmapsb);

#endif
