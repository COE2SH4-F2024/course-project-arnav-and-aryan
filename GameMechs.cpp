#include "GameMechs.h"
#include "MacUILib.h"
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 28;
    boardSizeY = 13;
    
}

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
GameMechs::~GameMechs()
{
   //can stay empty no mem allocated yet 
}

bool GameMechs::getExitFlagStatus() 
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() 
{
    return loseFlag;
}
    

char GameMechs::getInput()
{
    if(MacUILib_hasChar() != 0){
        input = MacUILib_getChar();
    }
    return input;

}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;  //will have to change in bonus
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here