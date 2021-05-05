#include "barrier.h"

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
Barrier::~Barrier()
{

}

void Barrier::update()
{

}