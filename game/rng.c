# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "rng.h"

void RNG(){
    srand(time(NULL));
    int number = (rand() % 100)+1;
    int guess = 0;
    int ctr = 0;
    char jawab;
    int score = 0;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X(0-100).\n");
    while (1) {
        printf("Tebakan : ");
        scanf("%d", &guess);
        ctr +=1;
        if (guess > 100){
            printf("tebakan invalid \n");
            ctr = 0;
            continue;
        }
        if (guess == number){
            if (ctr > 5){
                score = score + 1;
            }
            else if (ctr <= 5){
                score = score + 2;
            }
            else if (ctr == 1){
                score = score + 3;
            }
            printf("Ya, X adalah %d\n",number);
            ctr = 0;
            printf("mau lanjut main? (y/n) : ");
            scanf("%s", &jawab);
            if (jawab == 'y'){
                number = (rand() % 100)+1;
                printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X(0-100).\n");
                continue;
            }
            else{
                printf("score : %d\n", score);
                break;
            }
        }
        if (guess < number){
            printf("Lebih besar\n");
        }
        if (guess >  number){
            printf("Lebih Kecil\n");
        }
        if (ctr == 10){
            printf("tebakan habis\n");
            number = (rand() % 100)+1;
            printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X(0-100).\n");
        }
    } 

}


