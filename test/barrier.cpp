#include "barrier.h"
#include <iostream>
using namespace std;

Barrier::Barrier(int row, int col, Vector2f &pos) : Sprite()
{
    int type = BARRIER;
    cout << type << endl;
    spriteType = type;
    cout << SPRITE_TYPES[type] << endl;
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