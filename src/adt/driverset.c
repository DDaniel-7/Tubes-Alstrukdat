#include <stdio.h>
#include "set.h"
#include "wordmachine.h"
#include "charmachine.h"

int main(){
    Set S;

    char* text1 = "halo";
    char* text2 = "nama";
    char* text3 = "saya";
    char* text4 = "luigi";
    char* sametext1 = "halo";

    int i;

    CreateEmptySet(&S);


    if(IsEmptySet(S)){
        printf("Set masih kosong.\n");
    }

    if(!IsFullSet(S)){
        printf("Set belum penuh.\n");
    }
    InsertSet(&S,text1);
    printf("hai1\n");
    InsertSet(&S,text2);
    printf("hai2\n");
    InsertSet(&S,text3);
    printf("hai3\n");
    InsertSet(&S,text4);
    printf("hai4\n");

    for(i = 0 ; i < 4 ; i++){
        printf("%s\n",S.Elements[i]);
    }

    if(IsMemberSet(S,sametext1)){
        printf("YA\n");
    }
    
    DeleteSet(&S,text1);

    for(i = 0 ; i < 4 ; i++){
        printf("%s\n",S.Elements[i]);
    }

    return 0;
}