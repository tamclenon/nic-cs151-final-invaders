#include "game.h"
#include "player.h"
#include <iostream>
using namespace std;



Game::Game()
{
    defaultSize.x = 650;
	defaultSize.y = 350;
    
    windowScale.x = sf::VideoMode::getDesktopMode().width;
    windowScale.y = sf::VideoMode::getDesktopMode().height;

    window.create(VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
								Titlebar | Close);
    // window.setMouseCursorGrabbed(true);

    isDone = false;
    const VideoMode &vid = VideoMode::getDesktopMode();
    cout << vid.width << ',' << vid.height << endl;
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
                Vector2f scaled;
                scaled.x = window.getSize().x;
                scaled.y = window.getSize().y;
                window.create(VideoMode::getDesktopMode(), "Space Invaders", Fullscreen);
                scaled.x = window.getSize().x / scaled.x;
                scaled.y = window.getSize().y / scaled.y;
                sprite->setPosition(scaled.x * sprite->getPosition().x, window.getSize().y - (50 * scaled.y));
                for (Sprite *sprite : sDraw)
                    sprite->scale(scaled);
            }
            else if (event.key.code == Keyboard::F10)
            {
                Vector2f scaled;
                scaled.x = window.getSize().x;
                scaled.y = window.getSize().y;
                window.create(VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
                                        Titlebar | Close);
                scaled.x = window.getSize().x / scaled.x;
                scaled.y = window.getSize().y / scaled.y;
                sprite->setPosition(scaled.x * sprite->getPosition().x, window.getSize().y - 50);
                for (Sprite *sprite : sDraw)
                    sprite->scale(scaled);
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
    {
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