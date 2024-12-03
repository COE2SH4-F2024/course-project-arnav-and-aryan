#include "GameMechs.h"
#include "MacUILib.h"
#include <time.h>
#include "objPosArrayList.h"

// constructor of game mechs
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 28;
    boardSizeY = 13;
}

// copy constructor of game mechs
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
// destructor of game mechs
GameMechs::~GameMechs()
{
   //can stay empty no mem allocated yet 
}

// returns the exit flag status
bool GameMechs::getExitFlagStatus() 
{
    return exitFlag;
}

// returns the lose flag status
bool GameMechs::getLoseFlagStatus() 
{
    return loseFlag;
}
    

// returns the input for game mechs
char GameMechs::getInput()
{
    if(MacUILib_hasChar() != 0){
        input = MacUILib_getChar();
    }
    return input;

}

// returns the score for game mechs
int GameMechs::getScore()
{
    return score;
}

// increases the score by 1
void GameMechs::incrementScore()
{
    score++;  //will have to change in bonus
}

// returns the board size of X
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

// returns the board size of Y 
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

// sets the exit flag to be true
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

// sets the lose flag to be true
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

// sets the input
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

// clears the input
void GameMechs::clearInput()
{
    input = 0;
}

// generates the food for the game
void GameMechs::generateFood(objPosArrayList* blockOff){
    srand(time(NULL));
    bool unique = false;
    int size = blockOff->getSize();
    int x = 0, y = 0;
    while (!unique) {
            unique = true;
            x = rand() % (boardSizeX - 1) + 1;
            y = rand() % (boardSizeY - 1) + 1;

            // Check if the coordinates overlap with the player's position
            int i;
            for(i = 0; i< size; i++){
                objPos body = blockOff->getElement(i);
                if(x ==  body.pos->x && y == body.pos->y){
                    unique =false;  
                }
            }
}
    foodPos.pos->x = x;
    foodPos.pos->y = y;
    foodPos.symbol = '$';
}

// returns the food
objPos GameMechs::getFood() const
{
    // return the reference to the foodPos array list
    return foodPos;
}
// More methods should be added here