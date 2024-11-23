#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    PlayerPoslist = new objPosArrayList();
    gameDir = STOP;
    objPos headPos(mainGameMechsRef -> getBoardSizeX()/2+1, mainGameMechsRef -> getBoardSizeY()/2+1, '@');
    // more actions to be included
    
    PlayerPoslist->insertHead(headPos);
}


Player::~Player()
{
    // delete any heap members here
    delete PlayerPoslist;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return PlayerPoslist;
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
    objPos tempPos (PlayerPoslist->getHeadElement().getObjPos().pos->x, PlayerPoslist->getHeadElement().getObjPos().pos->y, '@');
    if(gameDir == RIGHT){
            tempPos.pos->x++;
        }

    if(gameDir == LEFT){
            tempPos.pos->x--;
    }
    
    if(gameDir == UP){
            tempPos.pos->y--;
    }

    if(gameDir == DOWN){
            tempPos.pos->y++;
    }

    if (tempPos.pos->x>28){
        tempPos.pos->x = 1;
    }
    else if (tempPos.pos->x<1){
        tempPos.pos->x= 28;
    }
    else if (tempPos.pos->y<1){
        tempPos.pos->y = 13;
    }
    else if (tempPos.pos->y>13){
        tempPos.pos->y = 1;
    }

    PlayerPoslist->insertHead(tempPos);
    




    //3b
    //Insert what happens if food is eaten
    //do not remove snake tail if food eaten

    if(PlayerPoslist->getHeadElement().getObjPos().pos->x == mainGameMechsRef->getFood().getObjPos().pos->x && PlayerPoslist->getHeadElement().getObjPos().pos->y == mainGameMechsRef->getFood().getObjPos().pos->y){
        mainGameMechsRef->generateFood(PlayerPoslist->getHeadElement());

        //implement point scoring mechanism

    }else{
        PlayerPoslist->removeTail();
    }




}

// More methods to be added