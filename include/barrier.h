/**
 * @file barrier.h
 * @author Shaun Martin
 * @brief Barrier class declaration file
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef BARRIER_H
#define BARRIER_H

#include "spriteRule.h"

#include <vector>

using std::vector;

/**
 * @brief Edge of screen barrier class
 * 
 */
class Barrier : public Sprite
{
public:
    Barrier(int row, int col, Vector2f &pos);
    ~Barrier();

    virtual void update();

protected:

private:

};

#endif