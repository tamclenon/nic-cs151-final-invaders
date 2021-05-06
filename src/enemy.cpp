#include "enemy.h"
#include "game.h"
#include <iostream>
using std::cout;

Enemy::Enemy(int row, int col) : Sprite(ENEMY)
{
    direction = RIGHT;
    speed = 2;
    column = col;
    health = 1;
    shots = 0;
    setPosition({col * 60.0f, row * 60.0f});
    bullet = nullptr;
    points = rand() % 100 + 100;
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    if (collision)
        move(0, Game::windowScale.y * speed * 2);
    else if (direction == RIGHT)
    {
        move(Game::windowScale.x * speed * (((dead / 100) * Game::info->getLevel()) + 1), 0);
    }
    else if (direction == LEFT)
    {
        move(Game::windowScale.x * -speed * (((dead / 100) * Game::info->getLevel()) + 1), 0);
    }
    if (bullet != nullptr && bullet->getHealth() == 0)
    {
        delete bullet;
        bullet = nullptr;
    }
}
bool Enemy::testCollision()
{
    collision = false;
    if (direction == RIGHT)
    {
        move(Game::windowScale.x * speed, 0);
        if (isCollision(Game::walls[RIGHT]))
        {
            direction = LEFT;
            collision = true;
        }
        move(Game::windowScale.x * -speed, 0);
    }
    if (direction == LEFT)
    {
        move(Game::windowScale.x * -speed, 0);
        if (isCollision(Game::walls[LEFT]))
        {
            direction = RIGHT;
            collision = true;
        }
        move(Game::windowScale.x * speed, 0);
    }
    if (collision)
        resetShots((Game::info->getLevel() * 3) + 1);
    return collision;
}
void Enemy::swapTests(vector<Enemy*> &enemies)
{
    int current = enemies[0]->column, next = 0, size = enemies.size();
    for (int i = 0; i < size; ++i)
    {
        if (current < enemies[i]->column && enemies[next]->column < enemies[i]->column && enemies[i]->getHealth() > 0)
            next = i;
        else if (current > enemies[i]->column && enemies[next]->column > enemies[i]->column && enemies[i]->getHealth() > 0)
            next = i;
    }
    if (next == 0)
        return;
    Enemy* temp = enemies[0];
    enemies[0] = enemies[next];
    enemies[next] = temp;
}
bool Enemy::isShoot()
{
    if (health == 0)
        return false;
    int shoot = rand() % 100;
    if (shots > 0)
    {
        if (shoot < 30)
        {
            --shots;
            return true;
        }
    }
    return false;
}
void Enemy::resetShots(int s)
{
    int add = rand() % 100;
    if (add < 30)
        shots = s;
}

Bullet* Enemy::fire()
{
    bullet = new Bullet(getPosition().x + 20, getPosition().y + 50, ENEMY);
    bullet->setRotation(180);
    return bullet;
}
bool Enemy::bulletExists()
{
    return bullet != nullptr;
}
void Enemy::deathCount()
{
    ++dead;
}
bool Enemy::levelOver()
{
    if (dead == 55)
    {
        dead = 0;
        return true;
    }
    return false;
}
void Enemy::setColumn(int col)
{
    column = col;
}
void Enemy::setDirection(int d)
{
    direction = d;
}