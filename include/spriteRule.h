#ifndef SPRITERULE_H
#define SPRITERULE_H

#include <string>
using std::string;

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
spriteDemention SPRITE_IMAGES[][2] = {{spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}, 
                                      {spriteDemention(), spriteDemention()}};

class Sprite
{
public:
    Sprite();
    ~Sprite();

protected:

private:
    string type;
    int health;
    spriteDemention hitBox; 
    spriteDemention image[2];
};

#endif