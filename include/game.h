
#ifndef GAME_H
#define GAME_H

#include "spriteRule.h"

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using std::vector;

using sf::RenderWindow;
using sf::Vector2u;
using sf::Vector2f;
using sf::Event;
using sf::Keyboard;
using sf::VideoMode;
using sf::Style::Titlebar;
using sf::Style::Close;
using sf::Style::Fullscreen;
using sf::Style::None;

enum SIDE {top, bottom, left, right};

class Game
{
public:
    Game();
    virtual ~Game();

    void input();
    void update(Sprite* sprite);
    void render();
    bool isFinished();

    void addDraw(Sprite &spr);
    void addWall(spriteDemention rectangle, int side);


private:
    
    Vector2u defaultSize;
    bool    isDone;
    vector<Sprite*> sDraw;
    vector<Sprite*> walls;

};



#endif