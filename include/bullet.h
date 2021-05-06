/**
 * @file bullet.h
 * @author Toby Mclenon
 * @brief Bullet class declaration file
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef BULLET_H
#define BULLET_H
#include "spriteRule.h"

#include <vector>

using std::vector;

/**
 * @brief Bullet class
 * 
 */
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