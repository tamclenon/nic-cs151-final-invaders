#include "game.h"
#include <iostream>
using namespace std;


Game::Game()
{
    defaultSize.x = 640;
	defaultSize.y = 360;
    window.create(VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
								Titlebar | Close);

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
        cout << event.type << endl;
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
            }
            else if (event.key.code == Keyboard::F10)
            {
                window.create(VideoMode(defaultSize.x, defaultSize.y), "Space Invaders",
                                        Titlebar | Close);
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
    for (Sprite &sprite : sDraw)
        window.draw(sprite);
    window.display();
}

bool Game::isFinished()
{
    return (!window.isOpen() || isDone);
}

void Game::addDraw(Sprite spr)
{
    sDraw.push_back(spr);
}