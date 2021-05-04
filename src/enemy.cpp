#include "enemy.h"

Enemy::Enemy(int type) : Sprite(type)
{
    speed = 5;
    loadShadow();
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    if (direction == RIGHT)
    {
        move(Game::windowScale.x * speed, 0);
        if (isCollision(Game::walls[RIGHT]))
        {
            move(Game::windowScale.x * -speed, 0);
            move(0, Game::windowScale.y * speed);
            direction = LEFT;
        }
    }
    if (direction == LEFT)
    {
        move(Game::windowScale.x * -speed, 0);
        if (isCollision(Game::walls[LEFT]))
        {
            move(Game::windowScale.x * speed, 0);
            move(0, Game::windowScale.y * speed);
            direction = RIGHT;
        }
    }
}