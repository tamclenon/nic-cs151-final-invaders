#ifndef SPRITERULE_H
#define SPRITERULE_H

#include <SFML/Graphics.hpp>

#include <string>
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

enum TYPE {player, enemy1, enemy2, enemy3, saucer, bullet, barrier, blank, shadow};
const string textureFile = "data/Sprite_Texture_Sheet_150x150.png";
const int NUM_TYPES = 5;
const string SPRITE_TYPES[] = {"player", "saucer", "enemy1", "enemy2", "enemy3"};
const spriteDemention SPRITE_IMAGES[] = {spriteDemention(0,0,50,50), spriteDemention(50,0,50,50), spriteDemention(100,0,50,50), 
                                         spriteDemention(0,50,50,50), spriteDemention(50,50,50,50), spriteDemention(100,50,50,50),
                                         spriteDemention(0,100,50,50), spriteDemention(50,100,50,50), spriteDemention(100,100,50,50)};

class Sprite : public sf::Sprite
{
public:
    Sprite();
    Sprite(int type);
    ~Sprite();
    void loadTexture(string file);
    // Overloaded Functions
    void move(float offsetX, float offsetY);
    void move(const Vector2f &offset);
    void scale(float factorX, float factorY);
    void scale(const Vector2f &factor);

    // Public Variables
    Sprite *shadowSprite;

protected:
    string spriteType;
    int health;
    spriteDemention hitBox;
    spriteDemention image;
    Texture texture;

private:

};
#endif