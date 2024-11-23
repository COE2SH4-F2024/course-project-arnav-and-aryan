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
    myGM->generateFood(myPlayer->getPlayerPos()->getHeadElement());
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
    if(myGM->getFood().pos->x == playerhead.pos->x && myGM->getFood().pos->y == playerhead.pos->y){
        myGM->generateFood(playerhead);
        //implement point scoring mechanism
    }
    
}

void DrawScreen(void)
{
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();
    objPos foodPos = myGM->getFood();
    MacUILib_clearScreen();
    MacUILib_printf("##############################\n");
    int i=0;
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
    MacUILib_printf("##############################\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myGM;
    delete arrayList;
    MacUILib_uninit();
}
