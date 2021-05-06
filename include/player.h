/**
 * @file player.h
 * @author Toby Mclenon
 * @brief Player class declaration file
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "spriteRule.h"
#include "bullet.h"

#include <vector>
using std::vector;

/**
 * @brief Player class
 * 
 */
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