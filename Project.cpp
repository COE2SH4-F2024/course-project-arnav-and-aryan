#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 100000

// global pointer meant to instantiate a player object on the heap
Player *myPlayer;
GameMechs *myGM;
objPosArrayList *arrayList;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{

    Initialize();
    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs();
    myPlayer = new Player(myGM);
    arrayList = new objPosArrayList();
    myGM->generateFood(myPlayer->getPlayerPos());
    
}

void GetInput(void)
{
   
   myGM->setInput(myGM->getInput());



}

void RunLogic(void)
{


    if(myGM->getInput() == ' '){
        myGM->setExitTrue();
    }
    else{
        myPlayer->updatePlayerDir();
        myPlayer->movePlayer();
    }
    objPos playerhead = myPlayer->getPlayerPos()->getHeadElement();
    myGM->clearInput();
    
    
}

void DrawScreen(void)
{
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();
    //score = playerSize-1;
    objPos foodPos = myGM->getFood();
    MacUILib_clearScreen();
    int i;
    for (i = 0; i<myGM->getBoardSizeX()+2; i++){
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");

    int j = 0;
    for(i = 1;  i< myGM->getBoardSizeY()+1; i++){
        MacUILib_printf("#");
        for(j = 1;  j< myGM->getBoardSizeX()+1; j++){
            int k = 0,test = 0;
            for (k = 0; k<playerSize; k++){
                objPos body = playerPos->getElement(k);
                if(i ==  body.pos->y && j == body.pos->x){
                  MacUILib_printf("%c",body.symbol);
                  test++;
                  break;
            }
            }
            if(i == foodPos.pos->y && j == foodPos.pos->x){
                MacUILib_printf("%c",foodPos.symbol);
            }
            else if (test == 0){
                MacUILib_printf(" ");
            }    
    }
    MacUILib_printf("#");
    MacUILib_printf("\n");

}
    for (i = 0; i<myGM->getBoardSizeX()+2; i++){
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
    MacUILib_printf("Score: \t%d\n" , myGM->getScore());
    if(myGM->getLoseFlagStatus()){

        MacUILib_printf("YOU LOSE!!! \n");

    }else if(myGM->getExitFlagStatus()){
        MacUILib_printf("Game Exits");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
        
    delete myPlayer;
    delete myGM;
    delete arrayList;
    MacUILib_uninit();
    
}
