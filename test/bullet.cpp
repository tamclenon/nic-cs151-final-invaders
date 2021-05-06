/**
 * @file bullet.cpp
 * @author Shaun Martin
 * @brief Bullet class definition file
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "bullet.h"
#include "game.h"

/**
 * @brief Construct a new Bullet:: Bullet object
 * 
 */
Bullet::Bullet()
{

}

/**
 * @brief Construct a new Bullet:: Bullet object
 * 
 * @param spawnX Set the x position for the bullet to spawn at
 * @param spawnY Set the y position for the bullet to spawn at
 * @param from Sprite type that fired bullet
 */
Bullet::Bullet(float spawnX, float spawnY, int from) : Sprite(BULLET)
{
    health = 1;
    firedFrom = from;
    speed = 5;
    setPosition(spawnX, spawnY);
}
/**
 * @brief Destroy the Bullet:: Bullet object
 * 
 */
Bullet::~Bullet()
{

}
/**
 * @brief Updates bullet
 * 
 * @param sDraw The vector containing the sprites to draw
 */
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