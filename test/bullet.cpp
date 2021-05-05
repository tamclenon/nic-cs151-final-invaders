
#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(int type, float spawnX, float spawnY) : Sprite(BULLET)
{
    speed = 5;
    this->setPosition(spawnX, spawnY);
}

Bullet::~Bullet()
{

}