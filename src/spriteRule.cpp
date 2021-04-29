#include "spriteRule.h"

Sprite::Sprite()
{

}
Sprite::~Sprite()
{

}
void Sprite::loadTexture(string file)
{
    texture.loadFromFile(file, IntRect(image[0].spriteX, image[0].spriteY, image[1].spriteX, image[1].spriteY));
    setTexture(texture);
}