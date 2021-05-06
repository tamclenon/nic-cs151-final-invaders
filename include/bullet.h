#ifndef BULLET_H
#define BULLET_H
#include "spriteRule.h"

#include <vector>

using std::vector;



class Bullet : public Sprite
{
public:
    Bullet();
    Bullet(float spawnX, float spawnY, int from);
    virtual ~Bullet();

    virtual void update(vector<Sprite*> &sDraw);

private:
    int firedFrom;

};






#endif