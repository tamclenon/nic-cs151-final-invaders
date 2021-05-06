#include "bullet.h"
#include "game.h"

Bullet::Bullet()
{

}

Bullet::Bullet(float spawnX, float spawnY, int from) : Sprite(BULLET)
{
    health = 1;
    firedFrom = from;
    speed = 5;
    setPosition(spawnX, spawnY);
}

Bullet::~Bullet()
{

}

void Bullet::update(vector<Sprite*> &sDraw)
{
    if (firedFrom == PLAYER)
    {
        move({0,Game::windowScale.x * -speed});
        if (isCollision(Game::walls[TOP]))
            health = 0;
    }
    else if (firedFrom == ENEMY)
    {
        move({0,Game::windowScale.x * speed});
        if (isCollision(Game::walls[BOTTOM]))
            health = 0;
    }
    for (Sprite* sprite : sDraw)
    {
        if (this != sprite && isCollision(sprite) && sprite->getHealth() > 0 && sprite->getType() != firedFrom)
        {
            if (sprite->getType() == ENEMY)
                Game::info->addToScore(sprite->getPoints());
            sprite->decHealth();
            decHealth();
        }
    }
}