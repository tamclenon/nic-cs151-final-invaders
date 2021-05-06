/**
 * @file barrier.cpp
 * @author Shaun martin
 * @brief Barrier class definition file
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "barrier.h"

/**
 * @brief Construct a new Barrier:: Barrier object
 * 
 * @param row The row to place the barrier
 * @param col The column to place to barrier
 * @param pos Vector2f containing the position to place barrier
 */
Barrier::Barrier(int row, int col, Vector2f &pos) : Sprite()
{
    int type = BARRIER;
    spriteType = type;
    image = SPRITE_IMAGES[type];
    image.sPosX += 10 * col;
    image.sPosY += 10 * row;
    loadTexture(textureFile);
    setPosition(pos);
    health = 1;
}
/**
 * @brief Destroy the Barrier:: Barrier object
 * 
 */
Barrier::~Barrier()
{

}


void Barrier::update()
{

}