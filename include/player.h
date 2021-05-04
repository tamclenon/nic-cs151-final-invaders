#ifndef PLAYER_H
#define PLAYER_H

#include "spriteRule.h"
#include "game.h"

class Player : public Sprite
{

public:
    Player(int type);
    virtual ~Player();

    virtual void update();



private:



};







#endif