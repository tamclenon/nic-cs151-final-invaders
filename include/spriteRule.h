#ifndef SPRITERULE_H
#define SPRITERULE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
using std::string;

using sf::Texture;
using sf::IntRect;
using sf::Vector2f;

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

enum TYPE {PLAYER, ENEMY, PLACE, PLACE2, SAUCER, BULLET, BARRIER, WALL, SHADOW};
const string textureFile = "data/Sprite_Texture_Sheet_150x150.png";
const int NUM_TYPES = 5;
const string SPRITE_TYPES[] = {"player", "enemy1", "enemy2", "enemy3", "saucer", "bullet", "barrier", "wall", "shadow"};
const spriteDemention SPRITE_IMAGES[] = {spriteDemention(0,0,50,50), spriteDemention(50,0,50,50), spriteDemention(100,0,50,50), 
                                         spriteDemention(0,50,50,50), spriteDemention(50,50,50,50), spriteDemention(100,50,50,50),
                                         spriteDemention(0,100,50,50), spriteDemention(50,100,1,1), spriteDemention(100,100,50,50)};

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
    int getType();
    void setHealth(int h);
    int getHealth();
    // Overloaded Functions
    void scale(float factorX, float factorY);
    void scale(const Vector2f &factor);

    // Public Variables

protected:
    int spriteType;
    int health;
    int speed;
    spriteDemention hitBox;
    spriteDemention image;
    Texture texture;

private:

};
#endif