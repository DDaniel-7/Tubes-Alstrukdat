# include "../adt/stack.h"
# include "boolean.h"
# include "../adt/arrayMap.h"
# include "../console.h"

# ifndef TOH_H
# define TOH_H

void tampilkarakter(char c, int n);

void tampil(Stackt a, Stackt b, Stackt c, int n);

void proses(Stackt *s1, Stackt *s2, int steps);

int skor(int steps, int disk);

void towerofhanoi(TabMap *arrmapsb);

#endif
