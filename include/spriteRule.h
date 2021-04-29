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

    spriteDemention(int x = 1, int y = 1)
    {
        x > 0 ? spriteX = x : spriteX = 1;
        y > 0 ? spriteY = y : spriteY = 1;
    }
};

string SPRITE_TYPES[] = {"player", "saucer", "enemy1", "enemy2", "enemy3"};
spriteDemention SPRITE_IMAGES[][2] = {{spriteDemention(0,0), spriteDemention(50,50)}, 
                                      {spriteDemention(50,0), spriteDemention(50,50)}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}};

class Sprite : public sf::Sprite
{
public:
    Sprite();
    ~Sprite();
    void loadTexture(string file);

protected:
    string type;
    int health;
    spriteDemention hitBox; 
    spriteDemention image[2];
    Texture texture;
private:
    
};
#endif