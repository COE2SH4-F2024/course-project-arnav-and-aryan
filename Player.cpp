#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    gameDir = STOP;

    // more actions to be included
    playerPos.pos->x = 10;
    playerPos.pos->y = 10;
    playerPos.symbol = '@';

}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructor
    // leave the destructor empty for now
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic    
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
}

// More methods to be added