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
    for (int i = 0; i < 4; ++i)
        addWall(i);
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
                fullScreen = 1;
                window.create(fullSize, "Space Invaders", Fullscreen);
                windowScale.x = fullSize.width / defaultSize.width;
                windowScale.y = fullSize.height / defaultSize.height;
                for (Sprite *sprite : sDraw)
                    sprite->scale(windowScale);
                for (Sprite *sprite : walls)
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
                for (Sprite *sprite : walls)
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
        if (sprite->getType() == PLAYER)
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
    for (sf::Sprite* wall : walls)
        window.draw(*wall);
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

void Game::addWall(int side)
{
    Sprite* wall = new Sprite(WALL);
    walls.push_back(wall);
    Vector2f size;
    Vector2f pos;
    switch (side)
    {
        case TOP:
        {
            size.x = windowSize.x;
            size.y = 1;
            pos.x = 0;
            pos.y = -1;
            break;
        }
        case BOTTOM:
        {
            size.x = windowSize.x;
            size.y = 1;
            pos.x = 0;
            pos.y = windowSize.y;
            break;
        }
        case LEFT:
        {
            size.x = 1;
            size.y = windowSize.y;
            pos.x = -1;
            pos.y = 0;
            break;
        }
        case RIGHT:
        {
            size.x = 1;
            size.y = windowSize.y;
            pos.x = windowSize.x;
            pos.y = 0;
            break;
        }
    };
    wall->setScale(size);
    wall->setPosition(pos);
    cout << wall->getScale().x << ',' << wall->getScale().y << ' '
         << wall->getPosition().x << ',' << wall->getPosition().y << endl;
}