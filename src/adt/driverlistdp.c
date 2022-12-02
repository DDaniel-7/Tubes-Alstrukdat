#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List L;
    CreateEmptyLDP(&L);

    if(IsEmptyLDP(L)){
        printf("masih kosong\n");
    }

    addressLDP P = AlokasiLDPEkor(72);


    if(SearchLDP(L,72)){
        printf("ADa\n");
    }

    InsVFirstLDP(&L,73);
    InsVLastLDP(&L,74);
    DelLastLDP(&L,&P);

    PrintForwardLDP(L);
    PrintBackwardLDP(L);

    return 0;
}