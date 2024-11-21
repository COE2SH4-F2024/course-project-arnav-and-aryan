#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    gameDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    playerPos.symbol = '@';

}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructor
    // leave the destructor empty FOR NOW will have to change later
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
        char input = mainGameMechsRef->getInput(); 
        switch(input){
            case 'W':
            case 'w':
            if(gameDir != UP && gameDir != DOWN){
                gameDir = UP;
            }
            break;
            case 'S':
            case 's':
            if(gameDir != UP && gameDir != DOWN){
                gameDir = DOWN;
            }
            break;
            case 'A':
            case 'a':
            if(gameDir != LEFT && gameDir != RIGHT){
                gameDir = LEFT;
            }
            break;
            case 'D':
            case 'd':
            if(gameDir != LEFT && gameDir != RIGHT){
                gameDir = RIGHT;
            }
            break;
            default:
                break;

        }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    // change later switch or else if
    // could mess up debug later

    if(gameDir == RIGHT){
            playerPos.pos->x++;
        }

    if(gameDir == LEFT){
            playerPos.pos->x--;
    }
    
    if(gameDir == UP){
            playerPos.pos->y--;
    }

    if(gameDir == DOWN){
            playerPos.pos->y++;
    }

    if (playerPos.pos->x>28){
        playerPos.pos->x = 1;
    }
    else if (playerPos.pos->x<1){
        playerPos.pos->x= 28;
    }
    else if (playerPos.pos->y<1){
        playerPos.pos->y = 13;
    }
    else if (playerPos.pos->y>13){
        playerPos.pos->y = 1;
    }

}

// More methods to be added