# include <stdio.h>
# include <stdlib.h>
# include "stack.h"
# include "boolean.h"

void tampil(Stack s){
    Stack temp;
    CreateEmpty(&temp);
    infotype x;
    while (!IsEmpty(s))
    {
        Pop(&s,&x);
        Push(&temp,x);
    }
    printf("[");
    if(!IsEmpty(temp)){
        Pop(&temp,&x);
        printf("%d",x);
        while (!IsEmpty(temp)){
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
    while(!IsEmpty(cek) && !IsEmpty(s)){
        if(InfoTop(s) != InfoTop(cek)){
            win = false;
        }
        Pop(&s,&x);
        Pop(&cek,&x);
    }
    if(IsEmpty(s) && IsEmpty(cek)){
        return win;
    }
    else{
        return false;
    }
}

void proses(Stack *s1, Stack *s2){
    if(IsEmpty(*s1)){
        printf("Invalid Command!\n");
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
    printf("Masukkan banyak disk yang ingin dimainkan: ");
    scanf("%d",&disk);
    int i;
    for(i=disk; i>0; i--){
        Push(&L,i);
    }
    char from, to;
    while(!isWin(R,disk)){
        printf("Menara Kiri: ");
        tampil(L);
        printf("Menara Tengah: ");
        tampil(M);
        printf("Menara Kanan: ");
        tampil(R);
        printf("Masukkan menara yang disknya ingin dipindahkan: ");
        scanf(" %c", &from);
        printf("Dipindahkan ke Menara: ");
        scanf(" %c", &to);
        if(from == 'R'){
            if(to == 'R'){
                printf("Invalid Command!\n");
            }
            else if(to == 'M'){
                proses(&R,&M);
            }
            else if(to == 'L'){
                proses(&R,&L);
            }
            else{
                printf("Invalid Command!\n");
            }
        }
        else if(from == 'M'){
            if(to == 'M'){
                printf("Invalid Command!\n");
            }
            else if(to == 'R'){
                proses(&M,&R);
            }
            else if(to == 'L'){
                proses(&M,&L);
            }
            else{
                printf("Invalid Command!\n");
            }
        }
        else if(from == 'L'){
            if(to == 'L'){
                printf("Invalid Command!\n");
            }
            else if(to == 'M'){
                proses(&L,&M);
            }
            else if(to == 'R'){
                proses(&L,&R);
            }
            else{
                printf("Invalid Command!\n");
            }
        }
        else{
            printf("Invalid Command!\n");
        }
        steps++;
    }
    printf("Selamat Anda Menyelesaikan Tower of Hanoi dengan %d Steps\n",steps);
}