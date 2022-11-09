#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

int main(){
    ArrayDin arraygame;
    Queue queue;
    arraygame = MakeArrayDin(&arraygame);
    CreateQueue(&queue);
    

    //OUTPUT
    printf("Selamat datang di BNMO UwU\n");


    //VARIABEL
    char* input;
    boolean repeat = true;

    //FILE
    //char* namaFile = "listgame.txt";

    //UNTUK DICOCOKAN
    char* startinput = "START";
    char* loadinput = "LOAD";
    char* saveinput = "SAVE";
    char* creategameinput = "CREATE GAME";
    char* listgameinput = "LIST GAME";
    char* deletegameinput = "DELETE GAME";
    char* queuegameinput = "QUEUE GAME";
    char* playgameinput = "PLAY GAME";
    char* skipgameinput = "SKIPGAME";
    char* quitinput = "QUIT";
    char* helpinput = "HELP";


    printf("====MAIN MENU====\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. QUIT\n");
    printf("ENTER COMMAND : ");
    input = scaninput();

    while(repeat){
        if(IsStrEq(startinput,input)){
            repeat = false;
            start(&arraygame);
            while(!IsStrEq(quitinput,input)){
                printf("ENTER COMMAND : ");
                input = scaninput();

                if(IsStrEq(saveinput,firstword(input))){
                    char* namaFile;
                    namaFile = secondword(input);
                    save(namaFile,arraygame);
                    //save(namaFile,&arraygame);
                }
                else if(IsStrEq(creategameinput,input)){
                    CreateGame(&arraygame);
                }
                else if(IsStrEq(listgameinput,input)){
                    ListGame(&arraygame);
                }
                else if(IsStrEq(deletegameinput,input)){
                    DeleteGame(&arraygame,&queue);
                }
                else if(IsStrEq(queuegameinput,input)){
                    QueueGame(&arraygame,&queue);
                }
                else if(IsStrEq(playgameinput,input)){
                    PlayGame(&queue);
                }
                else if(IsStrEq(helpinput,input)){
                    help();
                }
                else if(IsStrEq(skipgameinput,firstword(input))){
                    int manyskip;
                    manyskip = atoi(secondword(input));
                    SkipGame(&queue,manyskip);
                }
                else if(IsStrEq(quitinput,input)){
                    printf("====SEE YOU AGAIN====\n");
                }
                else{
                    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                }

            }

        }
        else if(IsStrEq(loadinput,input)){
            repeat = false;
            //load();
            while(!IsStrEq(quitinput,input)){
                printf("ENTER COMMAND : ");
                input = scaninput();
                if(IsStrEq(saveinput,firstword(input))){
                    char* namaFile;
                    namaFile = secondword(input);
                    save(namaFile,arraygame);
                }
                else if(IsStrEq(creategameinput,input)){
                    CreateGame(&arraygame);
                }
                else if(IsStrEq(listgameinput,input)){
                    ListGame(&arraygame);
                }
                else if(IsStrEq(deletegameinput,input)){
                    DeleteGame(&arraygame,&queue);
                }
                else if(IsStrEq(queuegameinput,input)){
                    QueueGame(&arraygame,&queue);
                }
                else if(IsStrEq(playgameinput,input)){
                    PlayGame(&queue);
                }
                else if(IsStrEq(helpinput,input)){
                    help();
                }
                else if(IsStrEq(skipgameinput,firstword(input))){
                    int manyskip;
                    manyskip = atoi(secondword(input));
                    SkipGame(&queue,manyskip);
                }
                else if(IsStrEq(quitinput,input)){
                    printf("====SEE YOU AGAIN====\n");
                }
                else{
                    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }
        else if(IsStrEq(quitinput,input)){
            repeat = false;
            printf("====SEE YOU AGAIN====\n");
        }
        else{
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("\n");
            printf("====MAIN MENU====\n");
            printf("1. START\n");
            printf("2. LOAD\n");
            printf("3. QUIT\n");
            printf("ENTER COMMAND : ");
            input = scaninput();
        }
    }

    return 0;
}