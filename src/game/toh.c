# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "stack.h"
# include "boolean.h"
# include "charmachine.h"
# include "wordmachine.h"

void tampilkarakter(char c , int n){
    int i = 0;
    for (i ; i < n ; i++){
        printf("%c", c);
    }
}

void tampil(Stackt a, Stackt b, Stackt c, int n){
    infotypes x;
    int temp, spasi;
    temp = n;
    while(!(IsEmptyStacktoh(a)) || !(IsEmptyStacktoh(b)) || !(IsEmptyStacktoh(c))){
        if (ctr(a) != temp) {
            spasi = ((2*n-1) - 1)/2;
            tampilkarakter(' ', spasi);
            printf("|");
            tampilkarakter(' ', spasi);
            printf(" ");
        }
        else{
            Poptoh(&a, &x);
            spasi = ((2*n-1) - x)/2;
            tampilkarakter(' ', spasi);
            tampilkarakter('*',x);
            tampilkarakter(' ', spasi);
            printf(" ");
        }
        if (ctr(b) != temp) {
            spasi = ((2*n-1) - 1)/2;
            tampilkarakter(' ', spasi);
            printf("|");
            tampilkarakter(' ', spasi);
            printf(" ");
        }
        else{
            Poptoh(&b, &x);
            spasi = ((2*n-1) - x)/2;
            tampilkarakter(' ', spasi);
            tampilkarakter('*',x);
            tampilkarakter(' ', spasi);
            printf(" ");
        }
        if (ctr(c) != temp) {
            spasi = ((2*n-1) - 1)/2;
            tampilkarakter(' ', spasi);
            printf("|");
            tampilkarakter(' ', spasi);
            printf("\n");
        }
        else{
            Poptoh(&c, &x);
            spasi = ((2*n-1) - x)/2;
            tampilkarakter(' ', spasi);
            tampilkarakter('*',x);
            tampilkarakter(' ', spasi);
            printf("\n");
        }
        temp--;
    }
    tampilkarakter('-',(2*n-1));
    printf(" ");
    tampilkarakter('-',(2*n-1));
    printf(" ");
    tampilkarakter('-',(2*n-1));
    printf("\n");
    tampilkarakter(' ',((2*n-1)/2));
    printf("L");
    tampilkarakter(' ',((2*n-1)/2));
    printf(" ");
    tampilkarakter(' ',((2*n-1)/2));
    printf("M");
    tampilkarakter(' ',((2*n-1)/2));
    printf(" ");
    tampilkarakter(' ',((2*n-1)/2));
    printf("R");
    tampilkarakter(' ',((2*n-1)/2));
    printf("\n");

}


void proses(Stackt *s1, Stackt *s2, int steps){
    if(IsEmptyStacktoh(*s1)){
        printf("Invalid Command!\n");
        steps--;
    }
    else{
        infotypes x;
        if(IsEmptyStacktoh(*s2)){
            Poptoh(s1,&x);
            Pushtoh(s2,x);
        }
        else{
            if(InfoTop(*s1) > InfoTop(*s2)){
                printf("Invalid Command!\n");
                steps--;
            }    
            else{
                Poptoh(s1,&x);
                Pushtoh(s2,x);
            }
        }
    }
}

int skor(int steps, int disk){
    int op  = pow(2, disk)-1;
    int score = 100 - steps + op;
    return score;
}

void towerofhanoi()
{
    Stackt R,M,L;
    int steps = 0;
    CreateEmptytoh(&R);
    CreateEmptytoh(&M);
    CreateEmptytoh(&L);
    int disk;
    printf("SELAMAT DATANG DI TOWER OF HANOI\n");
    printf("Main Menu:\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("ENTER CHOICE : ");
    STARTWORD();
    while (IsWordStr(currentWord, "2")){
        break;
    }
    while (IsWordStr(currentWord, "1")){ 
        printf("Masukkan banyak disk yang ingin dimainkan: ");
        ADVWORD();
        disk = ScanNum(currentWord);
        int i;
        for(i=disk; i>0; i--){
            Pushtoh(&L,(2*i-1));
        }
        tampil(L, M, R, disk);
        while(R.ctr != disk){
            printf("TIANG AWAL: ");
            ADVWORD();
            if (IsWordStr(currentWord,"R")){
                printf("TIANG AKHIR: ");
                ADVWORD();
                if (IsWordStr(currentWord,"R")){
                    printf("Invalid Command!\n");
                    steps--;
                }
                else if (IsWordStr(currentWord,"M")){
                    proses(&R,&M,steps++);
                }
                else if (IsWordStr(currentWord,"L")){
                    proses(&R,&L,steps++);
                }
                else{
                    printf("Invalid Command!\n");
                    steps--;
                }
            }
            else if (IsWordStr(currentWord,"M")){
                printf("TIANG AKHIR: ");
                ADVWORD();
                if (IsWordStr(currentWord,"M")){
                    printf("Invalid Command!\n");
                    steps--;
                }
                else if (IsWordStr(currentWord,"R")){
                    proses(&M,&R,steps++);
                }
                else if (IsWordStr(currentWord,"L")){
                    proses(&M,&L,steps++);
                }
                else{
                    printf("Invalid Command!\n");
                    steps--;
                }
            }
            else if (IsWordStr(currentWord,"L")){
                printf("TIANG AKHIR: ");
                ADVWORD();
                if (IsWordStr(currentWord,"L")){
                    printf("Invalid Command!\n");
                    steps--;
                }
                else if (IsWordStr(currentWord,"R")){
                    proses(&L,&R,steps++);
                }
                else if (IsWordStr(currentWord,"M")){
                    proses(&L,&M,steps++);
                }
                else{
                    printf("Invalid Command!\n");
                    steps--;
                }
            }
            tampil(L, M, R, disk);
        }
        printf("Selamat Anda Menyelesaikan Tower of Hanoi dengan %d Steps\n",steps);
        int score = skor(steps, disk);
        printf("SCORE : %d\n",score);
        break;
    }
}
