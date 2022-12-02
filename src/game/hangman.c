#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wordmachine.h"
#include "charmachine.h"
# include "hangman.h"

void gameFunction(char *wordinFunction, char *userWordinFunction, int letterNumber) {     
	int totalTrue= 0;			
	int totalFail= 0;			
	char scannedChar;
	
	while(totalFail< 10)
	{
		printFigure(totalFail);		
		printf("\n\n\n");
		printUserWord(userWordinFunction, letterNumber);    
		printf("\nMASUKAN TEBAKAN: ");
		scannedChar = *scaninput();
		scannedChar= toupper(scannedChar);
	
		int letterAlreadyUsed= 1;			
		while(letterAlreadyUsed== 1)
		{
			for(int i=  0; i< letterNumber; i++)
			{
				if(userWordinFunction[i]!= scannedChar)
				{
					letterAlreadyUsed= 0;	
				}
				else
				{
					letterAlreadyUsed= 1;
					printFigure(totalFail);
					printf("\n\n\n");
					printUserWord(userWordinFunction, letterNumber);
					printf("\nSUDAH ADA!\nMASUKAN TEBAKAN LAIN!");
					scannedChar = *scaninput();
					scannedChar= toupper(scannedChar);
					break;
				}
			}
		
		}
	
		int letterTrueCheck= 0;                       
		for(int i= 0; i< letterNumber; i++)			   
		{
			if(scannedChar== wordinFunction[i])		 
			{
				userWordinFunction[i]= wordinFunction[i];
				letterTrueCheck++;
				totalTrue++;				
			}
		}
		
		if(letterTrueCheck== 0)					
		{
			totalFail++;
		}
		
		if(totalTrue == letterNumber)             
		{
			printFigure(totalFail);
			printf("\n\n\n");
			printUserWord(userWordinFunction, letterNumber);
			printf("\n\nBerhasil menebak kata %s! Kamu mendapatkan %d poin!",wordinFunction, totalTrue);
			return;
		}
	}
	
	printFigure(totalFail);	                        
	printf("\n\n\n");
	for(int i= 0; i< letterNumber; i++)
	{
		printf("%c ", wordinFunction[i]);
	}
	printf("\n\nKATANYA ADALAH %s ", wordinFunction);	
    printf("\n SKOREMU : %d", totalTrue);	
	return;
	
}

void printUserWord(char *userWordinPrint,int letterNumber)   
{
	for(int i= 0; i< letterNumber; i++)
	{
		printf("%c ", userWordinPrint[i]);
	}
}

void printFigure(int failinFigure)    
{	
	switch(failinFigure)
	{
        case 0:
            printf("\n\n\n\n\n        \n        \n        \n     __ __");
			break;
		case 1:
			printf("\n\n\n\n\n        \n        \n       |\n     __|__");
			break;
		case 2:
			printf("\n\n\n\n\n       |\n       |\n       |\n     __|__");
			break;
		case 3:
			printf("  _ _ _\n       |\n       |\n       |\n       |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 4: 
			printf("  _ _ _  \n |     | \n |     | \n       |\n       |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 5:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n       |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 6:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/      |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 7:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/ \\    |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 8:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n       |\n     __|__ ");
			break;
		case 9:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n/      |\n     __|__ ");
			break;
		case 10:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n/ \\    |\n     __|__ ");
			break;
	}
}


void hangman()
{
	FILE *fpointer;     
	fpointer = fopen("hangmanwords.txt", "r");
	if(fpointer== NULL)
	{
		printf("hangmanwords.txt not found");
		return 0;
	}
	char readFromFile[300];
	while(!feof(fpointer))
	{
		fgets(readFromFile, 300, fpointer);
	}
	fclose(fpointer);
	srand(time(NULL));  
    printf("Main Menu:\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("PILIH (1/2): ");
    STARTWORD();
    while (IsWordStr(currentWord, "2")){
        break;
    }
    if (IsWordStr(currentWord, "1")) {
        int restartGame = 1; 
        while(restartGame==1)
        {
            int gameType;   
            printf(" WELCOME TO HANGMAN!\n\nChoose a game\n1. Six Letters Game\n2. Seven Letters Game\n3. Random Game\n");
            printf("ENTER CHOICE: ");
            ADVWORD();
            gameType = ScanNum(currentWord);
            while(gameType != 1 && gameType != 2 && gameType != 3)
            {
                printf("WELCOME TO HANGMAN!\n\nChoose a game\n1. Six Letters Game\n2. Seven Letters Game\n3. Random Game\n");
                printf("ENTER CHOICE: ");
                ADVWORD();
                gameType = ScanNum(currentWord);
            }
            if(gameType == 3)
            {
                gameType = rand() % 2 + 1;
            }
        
            int categoryType;
            printf("\n\nChoose a category\n1. Fruits and Vegetables\n2. Sports\n3. Technological Devices\n4. Countries\n5. Random Category\n");
            printf("PICK CATEGORY: ");
            ADVWORD();
            categoryType = ScanNum(currentWord);
        
            while(categoryType != 1 && categoryType != 2 && categoryType != 3 && categoryType != 4 && categoryType != 5)
            {

                printf("\n\nChoose a category\n1. Fruits and Vegetables\n2. Sports\n3. Technological Devices\n4. Countries\n5. Random Category\n");	
                printf("PICK CATEGORY: ");	
                ADVWORD();
                categoryType = ScanNum(currentWord);
            }
            if(categoryType== 5)
            {
                categoryType= rand() % 4 + 1;
            }
        
            char askedWord[8];								
            char userWord[8]= {'_','_','_','_','_','_','_'};   
            
            int randomer = rand()% 5;                          
            
            if(categoryType == 1)      
            {	
                if(gameType== 1)
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 0)+ (randomer * 7)+ i];
                    }	
                }
                else
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 1)+ (randomer * 7)+ i];
                    }
                    
                }
            }
            else if(categoryType == 2) 
            {		
                if(gameType==1)
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 2)+ (randomer * 7)+ i];
                    }
                    
                }
                
                else
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 3)+ (randomer * 7)+ i];
                    }
                    
                }
            }
            else if(categoryType == 3) 
            {
                if(gameType==1)
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 4)+ (randomer * 7)+ i];
                    }
                    
                }
                
                else
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 5)+ (randomer * 7)+ i];
                    }
                    
                }
            }
            else			        
            {
                if(gameType==1)
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 6)+ (randomer * 7)+ i];
                    }
                    
                }
                
                else
                {
                    for(int i= 0; i< 7; i++)
                    {
                        askedWord[i]= readFromFile[(35* 7)+ (randomer * 7)+ i];
                    }
                    
                }
            }
            
            gameFunction(askedWord, userWord, (gameType+ 5));    
            printf("\n\nDO YOU WANT TO CONTINUE? (1.YES/2.NO) : ");    
            ADVWORD();
            restartGame = ScanNum(currentWord);
        }
    }
}
