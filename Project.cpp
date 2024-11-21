#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 100000

// global pointer meant to instantiate a player object on the heap
Player *myPlayer;
GameMechs *myGM;


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
    

}

void GetInput(void)
{
   
   myGM->setInput(MacUILib_getChar());


}

void RunLogic(void)
{
    
    if(myGM->getInput() != 0){
        myPlayer->updatePlayerDir();
    }

    myPlayer->movePlayer();

}

void DrawScreen(void)
{
    objPos playerPos = myPlayer->getPlayerPos();
    //MacUILib_printf("Player [x, y, symbol] = [%d, %d, %c] \n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    MacUILib_clearScreen();
    MacUILib_printf("##############################\n");
    int i=0;
    int j = 0;
    for(i = 1;  i< myGM->getBoardSizeY()+1; i++){
        MacUILib_printf("#");
        for(j = 1;  j< myGM->getBoardSizeX()+1; j++){
            if(i == playerPos.pos->y && j == playerPos.pos->x){
                MacUILib_printf("%c",playerPos.symbol);
            }
            else{
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

    MacUILib_uninit();
}
