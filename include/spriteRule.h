#ifndef SPRITERULE_H
#define SPRITERULE_H

#include <SFML/Graphics.hpp>

#include <string>
using std::string;

using sf::Texture;
using sf::IntRect;

struct spriteDemention
{
    int spriteX;
    int spriteY;

    spriteDemention(int x = 0, int y = 0)
    {
        x >= 0 ? spriteX = x : spriteX = 0;
        y >= 0 ? spriteY = y : spriteY = 0;
    }
};

enum TYPE {player, saucer, enemy1, enemy2, enemy3};
const int NUM_TYPES = 5;
const string SPRITE_TYPES[] = {"player", "saucer", "enemy1", "enemy2", "enemy3"};
const spriteDemention SPRITE_IMAGES[][2] = {{spriteDemention(0,0), spriteDemention(50,50)}, 
                                      {spriteDemention(50,0), spriteDemention(50,50)}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}};

class Sprite : public sf::Sprite
{
public:
    Sprite(int type);
    ~Sprite();
    void loadTexture(string file);

protected:
    string spriteType;
    int health;
    spriteDemention hitBox;
    spriteDemention image[2];
    Texture texture;
private:
    
};
#endif