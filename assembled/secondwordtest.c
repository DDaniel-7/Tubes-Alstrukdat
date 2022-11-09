#include <stdio.h>
#include "wordmachine.h"
#include <stdlib.h>
#include "arraydin.h"

int main(){
    char* input;


    printf("Masukkan kata : ");
    input = scaninput();
    //SECONDWORD
    char* katakedua = secondword(input);
    
    printf("Kata keduamu adalah : %s\n",katakedua);

    return 0;
}