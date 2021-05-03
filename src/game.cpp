#include "game.h"
#include "player.h"
#include <iostream>
using namespace std;



Game::Game()
{
    defaultSize = VideoMode(650, 350);
    
    fullSize = sf::VideoMode::getDesktopMode();

    window.create(defaultSize, "Space Invaders",
								Titlebar | Close);
    // window.setMouseCursorGrabbed(true);

    isDone = false;
}

Game::~Game()
{

}

void Game::input()
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
            if ((event.key.code == Keyboard::F10) && (!fullScreen))
            {
                ++fullScreen;
                window.create(fullSize, "Space Invaders", Fullscreen);
                windowScale.x = fullSize.width / defaultSize.width;
                windowScale.y = fullSize.height / defaultSize.height;
                for (Sprite *sprite : sDraw)
                    sprite->scale(windowScale);
            }
            else if (event.key.code == Keyboard::F10)
            {
                fullScreen = 0;
                window.create(defaultSize, "Space Invaders",
                                        Titlebar | Close);
                windowScale.x = defaultSize.width / fullSize.width;
                windowScale.y = defaultSize.height / fullSize.height;
                for (Sprite *sprite : sDraw)
                    sprite->scale(windowScale);
                windowScale.x = 1;
                windowScale.y = 1;
            }
        }
    }
}

void Game::update()
{
    for (Sprite* sprite : sDraw)
    {
        if (sprite->getType() == player)
        {
            Player* playerConvert = static_cast<Player*>(sprite);
            playerConvert->playerUpdate();
        }
    }
    input();
}

void Game::render()
{
    // window.clear();
    for (Sprite *sprite : sDraw)
    {
        if (sprite->shadowSprite != nullptr)
            window.draw(*sprite->shadowSprite);
        window.draw(*sprite);
    }
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

void Game::addWall(spriteDemention rectangle, int side)
{
    sf::Sprite* wall = new sf::Sprite;
    walls.push_back(wall);
}