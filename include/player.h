#ifndef PLAYER_H
#define PLAYER_H

#include "spriteRule.h"
#include "bullet.h"

#include <vector>
using std::vector;

class Player : public Sprite
{

public:
    Player();
    virtual ~Player();

    virtual void update();
    Bullet* fire();
    bool bulletExists();

protected:
    Bullet* bullet;

private:
    



};







#endif