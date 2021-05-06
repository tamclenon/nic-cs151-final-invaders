/**
 * @file enemy.cpp
 * @author Shaun Martin
 * @brief Enemy class definition file
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "enemy.h"
#include "game.h"
#include <iostream>
using std::cout;

/**
 * @brief Construct a new Enemy:: Enemy object
 * 
 * @param row The row of the enemy grid in which this instance will be placed
 * @param col The column of the enemy grid in which this instance will be placed
 */
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

/**
 * @brief Destroy the Enemy:: Enemy object
 * 
 */
Enemy::~Enemy()
{

}

/**
 * @brief Update the enemy state
 * 
 */
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

/**
 * @brief Test collision for enemy instances
 * 
 * @return true There is a collision
 * @return false There is not a collision
 */
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

/**
 * @brief 
 * 
 * @param enemies Vector of enemy instances
 */
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
/**
 * @brief Function to meter enemies ability to shoot
 * 
 * @return true enemy can shoot
 * @return false enemy cannot shoot
 */
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
/**
 * @brief Resets the enemies shots
 * 
 * @param s The value to set shots to
 */
void Enemy::resetShots(int s)
{
    int add = rand() % 100;
    if (add < 30)
        shots = s;
}

/**
 * @brief Make enemy instance fire a bulle
 * 
 * @return Bullet* Pointer to member variable of type Bullet
 */
Bullet* Enemy::fire()
{
    bullet = new Bullet(getPosition().x + 20, getPosition().y + 50, ENEMY);
    bullet->setRotation(180);
    return bullet;
}
/**
 * @brief Check whether an enemy bullet is on screen
 * 
 * @return true There is a bullet on screen
 * @return false There is not a bullet on screen
 */
bool Enemy::bulletExists()
{
    return bullet != nullptr;
}
/**
 * @brief Count the number of enemies defeated
 * 
 */
void Enemy::deathCount()
{
    ++dead;
}
/**
 * @brief Checks if all enemies are dead
 * 
 * @return true All enemies are dead (level is over)
 * @return false All enemies are not dead (level is not over)
 */
bool Enemy::levelOver()
{
    if (dead == 55)
    {
        dead = 0;
        return true;
    }
    return false;
}
/**
 * @brief Sets the column of the enemy
 * 
 * @param col The column to place the enemy
 */
void Enemy::setColumn(int col)
{
    column = col;
}
/**
 * @brief Sets the direction of enemy movement
 * 
 * @param d The number representing the direction
 */
void Enemy::setDirection(int d)
{
    direction = d;
}