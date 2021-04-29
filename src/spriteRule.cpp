#include "spriteRule.h"
#include <iostream>
using namespace std;

Sprite::Sprite(int type)
{
    cout << type << endl;
    spriteType = SPRITE_TYPES[type];
    cout << spriteType << endl;
    image[0] = SPRITE_IMAGES[type][0];
    image[1] = SPRITE_IMAGES[type][1];
}
Sprite::~Sprite()
{

}
void Sprite::loadTexture(string file)
{
    cout << image[0].spriteX << image[0].spriteY << image[1].spriteX << image[1].spriteY << endl;
    texture.loadFromFile(file, IntRect(image[0].spriteX, image[0].spriteY, image[1].spriteX, image[1].spriteY));
    setTexture(texture);
}