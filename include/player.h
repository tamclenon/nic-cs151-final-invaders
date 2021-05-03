#ifndef PLAYER_H
#define PLAYER_H

#include "spriteRule.h"
#include "game.h"

class Player : public Sprite
{

public:
    Player(int type, const Game& game);
    virtual ~Player();

    void playerInput();
    virtual void playerUpdate(Vector2u vec);



private:




};







#endif