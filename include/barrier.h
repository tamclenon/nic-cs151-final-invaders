#ifndef BARRIER_H
#define BARRIER_H

#include "spriteRule.h"

#include <vector>

using std::vector;

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