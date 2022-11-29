# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "../adt/stack.h"
# include "boolean.h"
# include "../adt/charmachine.h"
# include "../adt/wordmachine.h"

void tampilkarakter(char c , int n){
    int i = 0;
    for (i ; i < n ; i++){
        printf("%c", c);
    }
}

void tampil(Stack a, Stack b, Stack c, int n){
    infotype x;
    int temp, spasi;
    temp = n;
    while(!(IsEmpty(a)) || !(IsEmpty(b)) || !(IsEmpty(c))){
        if (ctr(a) != temp) {
            spasi = ((2*n-1) - 1)/2;
            tampilkarakter(' ', spasi);
            printf("|");
            tampilkarakter(' ', spasi);
            printf(" ");
        }
        else{
            Pop(&a, &x);
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
            Pop(&b, &x);
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
            Pop(&c, &x);
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


void proses(Stack *s1, Stack *s2, int steps){
    if(IsEmpty(*s1)){
        printf("Invalid Command!\n");
        steps--;
    }
    else{
        infotype x;
        if(IsEmpty(*s2)){
            Pop(s1,&x);
            Push(s2,x);
        }
        else{
            if(InfoTop(*s1) > InfoTop(*s2)){
                printf("Invalid Command!\n");
                steps--;
            }    
            else{
                Pop(s1,&x);
                Push(s2,x);
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
    Stack R,M,L;
    int steps = 0;
    CreateEmpty(&R);
    CreateEmpty(&M);
    CreateEmpty(&L);
    int disk;
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
            Push(&L,(2*i-1));
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
        printf("masukan nama: ");
        ADVWORD();
        char *nama = scanword(currentWord);
        break;
    }
}
