#include "enemyLogic.h"

Enemy::Enemy(int type) : Sprite(type)
{
    loadShadow();
}

Enemy::~Enemy()
{

}