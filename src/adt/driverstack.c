#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main(){
    Stack S;
    CreateEmpty(&S);
    if(IsEmptyStack(S)){
        printf("Stack kosong brow\n");
    }
    int a = 1 ;
    int b = 3 ;
    int c = 5 ;
    int d = 7 ;

    Push(&S,a);
    Push(&S,b);
    Push(&S,c);
    Push(&S,d);
    Pop(&S,&d);
    Pop(&S,&c); 

    if(!IsFull(S)){
        printf("Stack belum penuh\n");
    }

    printf("Nilai top : %d\n",InfoTop(S));


    return 0;
}