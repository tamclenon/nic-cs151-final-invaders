#ifndef ENEMY_H
#define ENEMY_H

#include "spriteRule.h"
#include "game.h"

class Enemy : public Sprite
{
public:
    Enemy(int type);
    ~Enemy();

    virtual void update();

protected:

private:
    static int direction;
};

#endif