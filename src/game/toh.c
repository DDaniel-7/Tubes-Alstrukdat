# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "../adt/stack.h"
# include "boolean.h"
# include "../adt/charmachine.h"
# include "../adt/wordmachine.h"

void tampil(Stack s){
    Stack temp;
    CreateEmpty(&temp);
    infotype x;
    while (!IsEmptyStack(s))
    {
        Pop(&s,&x);
        Push(&temp,x);
    }
    printf("[");
    if(!IsEmptyStack(temp)){
        Pop(&temp,&x);
        printf("%d",x);
        while (!IsEmptyStack(temp)){
            Pop(&temp,&x);
            printf(",%d",x);
        }
    }
    printf("]\n");
}

boolean isWin(Stack s, int disk){
    int i;
    Stack cek;
    CreateEmpty(&cek);
    for(i=disk; i>0; i--){
        Push(&cek,i);
    }
    boolean win = true;
    infotype x;
    while(!IsEmptyStack(cek) && !IsEmptyStack(s)){
        if(InfoTop(s) != InfoTop(cek)){
            win = false;
        }
        Pop(&s,&x);
        Pop(&cek,&x);
    }
    if(IsEmptyStack(s) && IsEmptyStack(cek)){
        return win;
    }
    else{
        return false;
    }
}

void proses(Stack *s1, Stack *s2){
    if(IsEmptyStack(*s1)){
        printf("Invalid Command!\n");
    }
    else{
        infotype x;
        if(IsEmptyStack(*s2)){
            Pop(s1,&x);
            Push(s2,x);
        }
        else{
            if(InfoTop(*s1) > InfoTop(*s2)){
                printf("Invalid Command!\n");
            }    
            else{
                Pop(s1,&x);
                Push(s2,x);
            }
        }
    }
}
// dari s1 ke s2

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
            Push(&L,i);
        }
        while(!isWin(R,disk)){
            printf("Menara Kiri: ");
            tampil(L);
            printf("Menara Tengah: ");
            tampil(M);
            printf("Menara Kanan: ");
            tampil(R);
            printf("Masukkan menara yang disknya ingin dipindahkan: ");
            ADVWORD();
            if (IsWordStr(currentWord,"R")){
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord,"R")){
                    printf("Invalid Command!\n");
                }
                else if (IsWordStr(currentWord,"M")){
                    proses(&R,&M);
                }
                else if (IsWordStr(currentWord,"L")){
                    proses(&R,&L);
                }
                else{
                    printf("Invalid Command!\n");
                }
            }
            else if (IsWordStr(currentWord,"M")){
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord,"M")){
                    printf("Invalid Command!\n");
                }
                else if (IsWordStr(currentWord,"R")){
                    proses(&M,&R);
                }
                else if (IsWordStr(currentWord,"L")){
                    proses(&M,&L);
                }
                else{
                    printf("Invalid Command!\n");
                }
            }
            else if (IsWordStr(currentWord,"L")){
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord,"L")){
                    printf("Invalid Command!\n");
                }
                else if (IsWordStr(currentWord,"R")){
                    proses(&L,&R);
                }
                else if (IsWordStr(currentWord,"M")){
                    proses(&L,&M);
                }
                else{
                    printf("Invalid Command!\n");
                }
            }
            steps++;
        }
        printf("Selamat Anda Menyelesaikan Tower of Hanoi dengan %d Steps\n",steps);
        break;
    }
}
