#include "spriteRule.h"
using namespace std;

Sprite::Sprite(int type)
{
    cout << type << endl;
    spriteType = SPRITE_TYPES[type];
    cout << spriteType << endl;
    image = SPRITE_IMAGES[type];
}
Sprite::~Sprite()
{

}
void Sprite::loadTexture(string file)
{
    texture.loadFromFile(file, IntRect(image.sPosX, image.sPosY, image.sExtX, image.sExtY));
    setTexture(texture);
}