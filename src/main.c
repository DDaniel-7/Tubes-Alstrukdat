#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

int main(){
    ArrayDin arraygame;
    Queue queue;
    TabMap arrmapsb;
    Stack history;
    CreateEmpty(&history);
    arraygame = MakeArrayDin(&arraygame);
    CreateQueue(&queue);
    CreateEmptyArrMap(&arrmapsb);
    

    //OUTPUT
    printf("                                 .:^^^^^^^^^^~~~~~~~~^^^:...                  \n");
    printf("                                ~Y7!~~~~~~~!7777777777???JJJJJ?7!.            \n");
    printf("                                ?5JY5JY???P5Y5555555555555YYYYY55P            \n");
    printf("                                75Y5Y5Y5J5GJ5?~~^^^^::::::.....J5P            \n");
    printf("                                75JYYJYYJ5GJG:...::........~?..7PP            \n");
    printf("                                ?5P#GGG5Y5GJG:...J5........~7..7PP            \n");
    printf("                                ?YG&#@B&GYGJG:......^!~~~!:....7P5            \n");
    printf("                                ?5Y##G##5YGJG:.................7P5            \n");
    printf("                                ?5YBB##BYYGJG:................:J55            \n");
    printf("                                ?5Y#&&#GYYGJP!~~!!77??JJYYYYPP5YY5            \n");
    printf("                                ?55#####YYGJJG###########5JYGBPJY5            \n");
    printf("                                ?5JY5#&#YYGJJ5PPPPP5YYYYJJYJJJJJY5            \n");
    printf("                                ?YYBB&&#JYGJJJ55J^?YYJJJYPYYYJYYY5            \n");
    printf("                                JYJPB##GJYBJJYP5?^7YYJJJGP7J5PGYPY            \n");
    printf("                                JYG@B5&&5JBJJJJY5YYJJJJJY5GGPPG5PP:           \n");
    printf("                                J55&G~7B5JBJJJJJJJJJJJJJ5#GPPGYJYG77^.        \n");
    printf("                                .YYYP5?!JYBYJJPGGG5GBBBYYBBGGPYJYY.7J?!.      \n");
    printf("                                  .^!?Y5J?JYYYPP55YYYYYY55PPP555P^ YPPJP:     \n");      
    printf("                                        ::~7?YPPPGGGGPJ?G5P!?J5PP55PP7 .      \n");
    printf("                                            .~J^.^~7JYY555~345PP32DSF..:^:         \n");
    printf("\n");
    printf("\n");
    printf("          ~????????7~:       !?!           !?^     ??7              7??.       .^7?JJJJ?~.        \n");
    printf("          ?GJ......:7PY:     YPP5^         JG!    .PPGJ            ?GPP:     .?PY!:....^?55~      \n");
    printf("          7P7        ~GY     YP77P?.       JP~    .55?P?          7PJ5P.    :55^          ?PJ     \n");
    printf("          7P7        ?P!     YP^ :55^      JP~    .55.7G7        !G?.YP.   .5P:            ?G7    \n");
    printf("          7PY!!!!!7J5?.      YP^   7PJ.    JP~    .55  ?G!      ~PJ  YP.   ^PY             ^PY    \n");
    printf("          7PJ::::::^!YJ^     YP^    :YP~   JP~    .55.  ?P~    ^PY   YP.   ^PY             ^PY    \n"); 
    printf("          7P7         JG!    YP^      !PJ. JP~    .55.   JP^  :PY.   YP.    5P^            JP!    \n");
    printf("          7P7         7G?    YP^       .YP!YP~    .55.   .YP:.55.    YP.    :5P~         .?P?     \n");
    printf("          ?GJ::::::^~JP?.    YG^         ~PPP!    .P5.    .5PP5.     YP:     .!557^:..:~J5Y^      \n");
    printf("          ^777777777~^.      !7.          .!7:     7!      .77:      !7.        :~7?J??7^.        \n");
    printf("\n");
    printf("\n");            
    printf("Selamat datang di BNMO UwU\n");


    //VARIABEL
    char* input;
    boolean repeat = true;
    char* savekah;
    char* ye = "Y";
    char* no = "N" ;


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
    char* scoreboardinput = "SCOREBOARD";
    char* resetscoreboard = "RESET SCOREBOARD";
    char* resethistory = "RESETHISTORY";


    printf("====MAIN MENU====\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. QUIT\n");
    printf("ENTER COMMAND : ");
    input = scaninput();

    while(repeat){
        if(IsStrEq(startinput,input)){
            repeat = false;
            start(&arraygame,&arrmapsb);
            while(!IsStrEq(quitinput,input)){
                printf("ENTER COMMAND : ");
                input = scaninput();

                if(IsStrEq(saveinput,firstword(input))){
                    char* namaFile;
                    namaFile = secondword(input);
                    save(namaFile,arraygame,arrmapsb);
                }
                else if(IsStrEq(creategameinput,input)){
                    CreateGame(&arraygame,&arrmapsb);
                }
                else if(IsStrEq(scoreboardinput,input)){
                    SCOREBOARD(arrmapsb,arraygame);
                }
                else if(IsStrEq(resethistory,input)){
                    RESETHISTORY(&history);
                }
                else if(IsStrEq(resetscoreboard,input)){
                    RESETSCORE(&arrmapsb,&arraygame);
                }
                else if(IsStrEq(listgameinput,input)){
                    ListGame(&arraygame);
                }
                else if(IsStrEq(deletegameinput,input)){
                    DeleteGame(&arraygame,&queue,&arrmapsb);
                }
                else if(IsStrEq(queuegameinput,input)){
                    QueueGame(&arraygame,&queue);
                }
                else if(IsStrEq(playgameinput,input)){
                    PlayGame(&queue,&arrmapsb,arraygame);
                }
                else if(IsStrEq(helpinput,input)){
                    help();
                }
                else if(IsStrEq(skipgameinput,firstword(input))){
                    int manyskip;
                    manyskip = atoi(secondword(input));
                    SkipGame(&queue,manyskip,&arrmapsb,arraygame);
                }
                else if(IsStrEq(quitinput,input)){
                    printf("Apakah Anda akan melakukan save? (Y/N) \n");
                    savekah = scaninput();
                    if(IsStrEq(savekah,ye)){
                        char* namefile = "savedfile.txt";
                        save(namefile,arraygame,arrmapsb);
                    }

                    printf("====SEE YOU AGAIN====\n");
                }
                else{
                    CommandLain();
                }

            }

        }
        else if(IsStrEq(loadinput,firstword(input))){
            repeat = false;
            char* namafilebaru = concatstringbaru(secondword(input));
            Load(&arraygame, namafilebaru,&arrmapsb);
            while(!IsStrEq(quitinput,input)){
                printf("ENTER COMMAND : ");
                input = scaninput();
                if(IsStrEq(saveinput,firstword(input))){
                    char* namaFile;
                    namaFile = secondword(input);
                    save(namaFile,arraygame,arrmapsb);
                }
                else if(IsStrEq(creategameinput,input)){
                    CreateGame(&arraygame,&arrmapsb);
                }
                else if(IsStrEq(scoreboardinput,input)){
                    SCOREBOARD(arrmapsb,arraygame);
                }
                else if(IsStrEq(resetscoreboard,input)){
                    RESETSCORE(&arrmapsb,&arraygame);
                }
                else if(IsStrEq(resethistory,input)){
                    RESETHISTORY(&history);
                }
                else if(IsStrEq(listgameinput,input)){
                    ListGame(&arraygame);
                }
                else if(IsStrEq(deletegameinput,input)){
                    DeleteGame(&arraygame,&queue,&arrmapsb);
                }
                else if(IsStrEq(queuegameinput,input)){
                    QueueGame(&arraygame,&queue);
                }
                else if(IsStrEq(playgameinput,input)){
                    PlayGame(&queue,&arrmapsb,arraygame);
                }
                else if(IsStrEq(helpinput,input)){
                    help();
                }
                else if(IsStrEq(skipgameinput,firstword(input))){
                    int manyskip;
                    manyskip = atoi(secondword(input));
                    SkipGame(&queue,manyskip,&arrmapsb,arraygame);
                }
                else if(IsStrEq(quitinput,input)){
                    printf("Apakah Anda akan melakukan save? (Y/N) \n");
                    savekah = scaninput();

                    if(IsStrEq(savekah,ye)){
                        char* namefile = "savedfile.txt";
                        save(namefile,arraygame,arrmapsb);
                    }
                    printf("====SEE YOU AGAIN====\n");
                }          
                else{
                    CommandLain();
                }
            }
        }
        else if(IsStrEq(quitinput,input)){
            repeat = false;
            printf("====SEE YOU AGAIN====\n");
        }
        else{
            CommandLain();
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