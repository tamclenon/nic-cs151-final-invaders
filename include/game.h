
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

enum SIDE {TOP, BOTTOM, LEFT, RIGHT};

class Game
{
public:
    Game();
    virtual ~Game();

    void input();
    void update();
    void render();
    bool isFinished();

    void addDraw(Sprite* spr);
    void addWall(int side);

    static Vector2f windowScale;
    static Vector2u windowSize;
    static vector<Sprite*> sDraw;
    static vector<Sprite*> walls;

private:
    RenderWindow window;
    VideoMode fullSize;
    VideoMode defaultSize;
    bool fullScreen;
    bool    isDone;
};




#endif