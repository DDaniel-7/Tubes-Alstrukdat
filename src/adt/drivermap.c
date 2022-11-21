#include "map.h"
#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

int main()
{
    Map M;
    int i;

    keytype k1 = "UPIN";
    keytype k2 = "IPIN";
    keytype k3 = "APIN";
    keytype k4 = "ROS";

    valuetype v1 = 69;
    valuetype v2 = 78;
    valuetype v3 = 45;
    valuetype v4 = 100;

    CreateEmptyMap(&M);

    if(IsEmptyMap(M)){
        printf("msh kosong\n");
    }
    if(!IsFullMap(M)){
        printf("blm penuh\n");
    }

    InsertMap(&M,k1,v1);
    printf("tes1\n");

    valuetype testingvalue1 = ValueMap(M,k1);
    printf("Value : %d\n",testingvalue1);

    if(IsMemberMap(M,k1)){
        printf("Adaa broo\n");
    }

    InsertMap(&M,k2,v2);
    InsertMap(&M,k3,v3);
    InsertMap(&M,k4,v4);

    for(i = 0 ; i <4 ; i++){
        printf("%s , %d \n", M.Elements[i].Key,M.Elements[i].Value);
    }

    printf("Deleting...\n");
    DeleteMap(&M,k2);

    for(i = 0 ; i < 3 ; i++){
        printf("%s , %d \n", M.Elements[i].Key,M.Elements[i].Value);
    }    


    return 0;
}