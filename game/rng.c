# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "rng.h"
# include "charmachine.h"
# include "wordmachine.h"

void RNG(){
    srand(time(NULL));
    int number = (rand() % 100)+1;
    int guess = 0;
    int ctr = 0;
    char jawab;
    int score = 0;
    printf("Main Menu:\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("ENTER CHOICE : ");
    STARTWORD();
    while (IsWordStr(currentWord, "2")){
        break;
    }
    if (IsWordStr(currentWord, "1")) {
        printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X(0-100).\n");
        while (1){
            printf("Tebakan : ");
            ADVWORD();
            guess = PickNum(currentWord);
            ctr +=1;
            if (guess > 100 || guess < 0){
                printf("tebakan invalid \n");
                ctr -= 1;
            }
            else if (guess == number){
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
                printf("mau lanjut main? (1.yes/2.no) : ");
                ADVWORD();
                if (IsWordStr(currentWord, "1")){
                    number = (rand() % 100)+1;
                    ctr = 0;
                    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X(0-100).\n"); 
                }
                else if (IsWordStr(currentWord, "2")){
                    printf("score : %d\n", score);
                    break;
                }
            }
            else if (guess < number){
                printf("Lebih besar\n");
            }
            else if (guess >  number){
                printf("Lebih Kecil\n");
            }
            if (ctr == 10){
                printf("tebakan habis\n");
                number = (rand() % 100)+1;
                printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X(0-100).\n");
            }
        }
    } 

}

