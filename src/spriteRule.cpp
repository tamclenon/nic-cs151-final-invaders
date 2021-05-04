#include "spriteRule.h"
using namespace std;

Sprite::Sprite()
{

}
Sprite::Sprite(int type)
{
    cout << type << endl;
    spriteType = type;
    cout << SPRITE_TYPES[type] << endl;
    image = SPRITE_IMAGES[type];
    loadTexture(textureFile);
}
Sprite::~Sprite()
{

}

void Sprite::loadTexture(string file)
{
    texture.loadFromFile(file, IntRect(image.sPosX, image.sPosY, image.sExtX, image.sExtY));
    setTexture(texture);
}
bool Sprite::isCollision(Sprite* spr)
{
    return getGlobalBounds().intersects(spr->getGlobalBounds());
}
bool Sprite::isCollision(RectangleShape* rec)
{
    return getGlobalBounds().intersects(rec->getGlobalBounds());
}
int Sprite::getType()
{
    return spriteType;
}
void Sprite::setHealth(int h)
{
    health = h;
}
int Sprite::getHealth()
{
    return health;
}

void Sprite::scale(float factorX, float factorY)
{
    scale({factorX, factorY});
}
void Sprite::scale(const Vector2f &factor)
{
    sf::Sprite::scale(factor);
    Vector2f setPos = {getPosition().x * factor.x, getPosition().y * factor.y};
    setPosition(setPos);
}