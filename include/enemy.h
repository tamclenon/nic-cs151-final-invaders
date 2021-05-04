#ifndef ENEMY_H
#define ENEMY_H

#include "spriteRule.h"

#include <vector>

using std::vector;

class Enemy : public Sprite
{
public:
    Enemy(int row, int col);
    ~Enemy();

    virtual void update();
    bool testCollision();
    void swapTests(vector<Enemy*> &enemies);
    bool isShoot();

protected:

private:
    int column;
    static int direction;
    static bool collision;
    static int shots;
};

#endif