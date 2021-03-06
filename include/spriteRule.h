/**
 * @file spriteRule.h
 * @author Shaun Martin
 * @brief Sprite class declaration file
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SPRITERULE_H
#define SPRITERULE_H

#include <SFML/Graphics.hpp>

#include <string>

using std::string;

using sf::Texture;
using sf::IntRect;
using sf::Vector2f;
using sf::RectangleShape;

/**
 * @brief Struct for the dimensions of the sprite
 * 
 */
struct spriteDemention
{
    int sPosX;
    int sPosY;
    int sExtX;
    int sExtY;

    spriteDemention(int pX = 0, int pY = 0, int eX = 1, int eY = 1)
    {
        pX >= 0 ? sPosX = pX : sPosX = 0;
        pY >= 0 ? sPosY = pY : sPosY = 0;
        eX > 0 ? sExtX = eX : sExtX = 1;
        eY > 0 ? sExtY = eY : sExtY = 1;
    }
};

enum TYPE {PLAYER, ENEMY, SAUCER, BULLET, BARRIER, PLACE, PLACE2, PLACE3, PLACE4};
const string textureFile = "data/Sprite_Texture_Sheet_150x150.png";
const int NUM_TYPES = 5;
const string SPRITE_TYPES[] = {"player", "enemy", "saucer", "bullet", "barrier", "place", "place", "place", "place"};
const spriteDemention SPRITE_IMAGES[] = {spriteDemention(0,0,50,50), spriteDemention(50,0,50,50), spriteDemention(100,0,50,50), 
                                         spriteDemention(0,50,10,35), spriteDemention(20,50,10,10), spriteDemention(100,50,50,50),
                                         spriteDemention(0,100,50,50), spriteDemention(50,100,1,1), spriteDemention(100,100,50,50)};
/**
 * @brief Sprite class
 * 
 */
class Sprite : public sf::Sprite
{
public:
    // Constructors and Destructors
    Sprite();
    Sprite(int type);
    virtual ~Sprite();
    // Functions
    void loadTexture(string file);
    bool isCollision(Sprite* spr);
    bool isCollision(RectangleShape* rec);
    int getType();
    void setHealth(int h);
    void decHealth();
    void incHealth();
    int getHealth();
    int getPoints();
    // Overloaded Functions
    void scale(float factorX, float factorY);
    void scale(const Vector2f &factor);

    // void fire();

    // Public Variables
    
protected:
    int points;
    int spriteType;
    int health;
    int speed;
    spriteDemention hitBox;
    spriteDemention image;
    Texture texture;
    

private:

};
#endif