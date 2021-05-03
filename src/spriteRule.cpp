#include "spriteRule.h"
using namespace std;

Sprite::Sprite()
{
    int type = shadow;
    cout << type << endl;
    spriteType = type;
    cout << spriteType << endl;
    image = SPRITE_IMAGES[type];
    loadTexture(textureFile);
    shadowSprite = nullptr;
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
void Sprite::loadShadow()
{
    shadowSprite = new Sprite;
    shadowSprite->setPosition({getPosition().x, getPosition().y});
}
bool Sprite::isCollision(Sprite A, Sprite B)
{
    return A.getGlobalBounds().intersects(B.getGlobalBounds());
}
int Sprite::getType()
{
    return spriteType;
}

void Sprite::move(float offsetX, float offsetY)
{
    move({offsetX, offsetY});
}
void Sprite::move(const Vector2f &offset)
{

    if (shadowSprite != nullptr)
        shadowSprite->sf::Sprite::setPosition(getPosition());
    sf::Sprite::move(offset);
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
    if (shadowSprite != nullptr)
    {
        shadowSprite->sf::Sprite::scale(factor);
        shadowSprite->setPosition(setPos);
    }
}