#include "game.h"
#include "player.h"
#include <iostream>
using namespace std;



Game::Game()
{
    defaultSize.x = 640;
	defaultSize.y = 360;
    
    windowScale.x = sf::VideoMode::getDesktopMode().width;
    windowScale.y = sf::VideoMode::getDesktopMode().height;

    window.create(VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
								Titlebar | Close);

    isDone = false;
}

Game::~Game()
{

}

void Game::input(Sprite* sprite)
{
    Event event;
    while (window.pollEvent(event))
    {
        if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
        {
            window.close();
            isDone = false;
        }
        if (event.type == Event::KeyPressed)
        {
            if ((event.key.code == Keyboard::F10) && (window.getSize() == defaultSize))
            {
                window.create(VideoMode::getFullscreenModes()[0], "Space Invaders", Fullscreen);

                float scaleX = (/*window.getSize().x*/windowScale.x / defaultSize.x) * sprite->getPosition().x;
                sprite->setPosition(scaleX + (scaleX / 10), window.getSize().y - 50);
            }
            else if (event.key.code == Keyboard::F10)
            {
                float scaleX = sprite->getPosition().x / (/*window.getSize().x*/windowScale.x / defaultSize.x);

                window.create(VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
                                        Titlebar | Close);

                sprite->setPosition(scaleX - (scaleX / 10), window.getSize().y - 50);
            }
        }
    }
}

void Game::update(Sprite* sprite)
{
    Player* playerConvert = static_cast<Player*>(sprite);
    playerConvert->playerUpdate(window.getSize());
    input(sprite);
}

void Game::render()
{
    window.clear();
    for (Sprite *sprite : sDraw)
        window.draw(*sprite);
    window.display();
}

bool Game::isFinished()
{
    return (!window.isOpen() || isDone);
}

void Game::addDraw(Sprite* spr)
{
    sDraw.push_back(spr);
}