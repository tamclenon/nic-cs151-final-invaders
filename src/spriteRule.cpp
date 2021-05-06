/**
 * @file spriteRule.cpp
 * @author Shaun Martin
 * @brief Sprite class definition file
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "spriteRule.h"

/**
 * @brief Construct a new Sprite:: Sprite object
 * 
 */
Sprite::Sprite()
{

}
/**
 * @brief Construct a new Sprite:: Sprite object
 * 
 * @param type Type of sprite to be created (player, enemy, etc.)
 */
Sprite::Sprite(int type)
{
    spriteType = type;
    image = SPRITE_IMAGES[type];
    loadTexture(textureFile);
}
/**
 * @brief Destroy the Sprite:: Sprite object
 * 
 */
Sprite::~Sprite()
{

}
/**
 * @brief Loads the sprite texture file
 * 
 * @param file The texture file to be loaded
 */
void Sprite::loadTexture(string file)
{
    texture.loadFromFile(file, IntRect(image.sPosX, image.sPosY, image.sExtX, image.sExtY));
    setTexture(texture);
}
/**
 * @brief Checks for collision
 * 
 * @param spr The sprite to check
 * @return true There is a collision
 * @return false There is not a collision
 */
bool Sprite::isCollision(Sprite* spr)
{
    return getGlobalBounds().intersects(spr->getGlobalBounds());
}/**
 * @brief Checks collision on barriers
 * 
 * @param rec The shape to be tested
 * @return true There is a collision
 * @return false There is not a collision
 */
bool Sprite::isCollision(RectangleShape* rec)
{
    return getGlobalBounds().intersects(rec->getGlobalBounds());
}
/**
 * @brief Gets the type of sprite
 * 
 * @return int The sprite type of this instance
 */
int Sprite::getType()
{
    return spriteType;
}
/**
 * @brief Sets the health of the sprite
 * 
 * @param h 
 */
void Sprite::setHealth(int h)
{
    health = h;
}
/**
 * @brief Decrements sprite instance's health
 * 
 */
void Sprite::decHealth()
{
    if (health > 0)
        --health;
}
/**
 * @brief Increments sprite instance's health
 * 
 */
void Sprite::incHealth()
{
    ++health;
}
/**
 * @brief Gets health of sprite instance
 * 
 * @return int 
 */
int Sprite::getHealth()
{
    return health;
}
/**
 * @brief Gets the current points
 * 
 * @return int Number of points
 */
int Sprite::getPoints()
{
    return points;
}

/**
 * @brief Scales the sprite size
 * 
 * @param factorX The percentage to scale the sprite's x value
 * @param factorY The percentage to scale the sprite's y value
 */
void Sprite::scale(float factorX, float factorY)
{
    scale({factorX, factorY});
}

/**
 * @brief Scales the sprite position
 * 
 * @param factor The amount to scale the x and y position of the sprite
 */
void Sprite::scale(const Vector2f &factor)
{
    sf::Sprite::scale(factor);
    Vector2f setPos = {getPosition().x * factor.x, getPosition().y * factor.y};
    setPosition(setPos);
}