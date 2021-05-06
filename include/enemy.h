/**
 * @file enemy.h
 * @author Shaun Martin
 * @brief Enemy class declaration file
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ENEMY_H
#define ENEMY_H
#include "spriteRule.h"
#include "bullet.h"

#include <vector>
#include <stdlib.h>

using std::vector;
using std::rand;

/**
 * @brief Enemy class
 * 
 */
class Enemy : public Sprite
{
public:
    Enemy(int row, int col);
    virtual ~Enemy();

    virtual void update();
    bool testCollision();
    void swapTests(vector<Enemy*> &enemies);
    bool isShoot();
    void resetShots(int s);
    Bullet* fire();
    bool bulletExists();
    void deathCount();
    bool levelOver();
    void setColumn(int col);
    void setDirection(int d);

protected:
    Bullet* bullet;

private:
    int column;
    static int direction;
    static bool collision;
    static int shots;
    static int dead;
};

#endif