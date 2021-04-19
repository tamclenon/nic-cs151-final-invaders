#include "game.h"



Game::Game()
{
    defaultSize.x = 640;
	defaultSize.y = 360;
    window.create(sf::VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
								sf::Style::Titlebar | sf::Style::Close);

    isDone = false;
}

Game::~Game()
{

}

void Game::input()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        
        if (event.type == sf::Event::KeyReleased)
        {
            if ((event.key.code == sf::Keyboard::F10) && (window.getSize() == defaultSize))
            {
                window.create(sf::VideoMode::getFullscreenModes()[0], "Space Invaders",
                                        sf::Style::Fullscreen);
            }
            else if (event.key.code == sf::Keyboard::F10)
            {
                window.create(sf::VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
                                        sf::Style::Titlebar | sf::Style::Close);
            }
        }
    }
}

void Game::update()
{
    input();
}

void Game::render()
{
    window.clear();
    //window.draw();
    window.display();
}

bool Game::isFinished()
{
    return (!window.isOpen() || isDone);
}

