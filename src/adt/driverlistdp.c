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


    return 0;
}