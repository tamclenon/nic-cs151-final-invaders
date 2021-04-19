#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
    Game();
    virtual ~Game();

    void input();
    void update();
    void render();
    bool isFinished();




private:
    sf::RenderWindow window;
    sf::Vector2u defaultSize;
    bool    isDone;


};



#endif