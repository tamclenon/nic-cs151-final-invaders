#ifndef ENEMY_H
#define ENEMY_H
#include "spriteRule.h"
#include "bullet.h"

#include <vector>

using std::vector;

class Enemy : public Sprite
{
public:
    Enemy(int row, int col);
    virtual ~Enemy();

    virtual void update(vector<Sprite*>& vec);
    bool testCollision();
    void swapTests(vector<Enemy*> &enemies);
    bool isShoot();
    void fire(vector<Sprite*>& vec);

protected:
    Sprite* bullet;

private:
    int column;
    static int direction;
    static bool collision;
    static int shots;
    bool bulletExists;
};

#endif