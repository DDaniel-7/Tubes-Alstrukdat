#include <stdio.h>
#include "wordmachine.h"
#include <stdlib.h>
#include "arraydin.h"

int main(){
    char* input;


    printf("Masukkan kata : ");
    input = scaninput();

    char* katapertama = firstword(input);

    printf("Kata pertama adalah : %s\n",katapertama);
    return 0;
} 
/*
    //SECONDWORD
    char* output2;
    output2 = (char*) malloc(101 * sizeof(char));

    int k = 0;
    while(input[k] != BLANK){
        k++;
    }

    int idx = k+1;

    while(input[idx] != BLANK && input[idx] != '\0'){
        output2[idx] = input[idx];
        idx++;
    }
    
    printf("Kata keduamu adalah : %s\n",output2);

    return 0;
}
*/