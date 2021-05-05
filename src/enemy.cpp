#include "enemy.h"
#include "game.h"

Enemy::Enemy(int row, int col) : Sprite(ENEMY)
{
    direction = RIGHT;
    speed = 2;
    column = col;
    health = 1;
    setPosition({col * 60.0f, row * 60.0f});
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
        move(Game::windowScale.x * speed, 0);
    }
    else if (direction == LEFT)
    {
        move(Game::windowScale.x * -speed, 0);
    }
    if (isShoot())
    {
        
    }
}
bool Enemy::testCollision()
{
    collision = false;
    move(Game::windowScale.x * speed, 0);
    if (isCollision(Game::walls[RIGHT]))
    {
        direction = LEFT;
        collision = true;
    }
    move(Game::windowScale.x * -speed * 2, 0);
    if (isCollision(Game::walls[LEFT]))
    {
        direction = RIGHT;
        collision = true;
    }
    move(Game::windowScale.x * speed, 0);
    return collision;
}
void Enemy::swapTests(vector<Enemy*> &enemies)
{
    int current = enemies[0]->column, next = 0, size = enemies.size();
    for (int i = 1; i < size; ++i)
    {
        if (current < enemies[i]->column && enemies[next]->column < enemies[i]->column)
            next = i;
        else if (current > enemies[i]->column && enemies[next]->column > enemies[i]->column)
            next = i;
    }
    Enemy* temp = enemies[0];
    enemies[0] = enemies[next];
    enemies[next] = temp;
}
bool Enemy::isShoot()
{
    return false;
    int shoot = rand() % 10;
    if (shots)
    {
        if (shoot < 3)
        {
            --shots;
            return true;
        }
    }
    if (shoot == 9)
    {
        ++shots;
    }
    return false;
}