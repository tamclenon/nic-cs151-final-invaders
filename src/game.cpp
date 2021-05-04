#include "game.h"
#include <iostream>
using namespace std;



Game::Game()
{
    defaultSize = VideoMode(windowSize.x, windowSize.y);
    
    fullSize = sf::VideoMode::getDesktopMode();

    window.create(defaultSize, "Space Invaders",
								Titlebar | Close);
    // window.setMouseCursorGrabbed(true);

    fullScreen = 0;
    isDone = false;

    showBorder = 0;
    for (int i = 0; i < 4; ++i)
        addWall(i);
    addShadow({0,0}, {(windowSize.x * PLAYPERCENT),(windowSize.y * .7f)});
    addShadow({0,(windowSize.y * .7f)}, {(windowSize.x * PLAYPERCENT),(windowSize.y * .2f)});
    addShadow({0,(windowSize.y * .9f)}, {(windowSize.x * PLAYPERCENT),(windowSize.y * .1f)});

    loadPlayer();
    loadEnemy();
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

                windowScale.x = static_cast<float>(fullSize.width) / defaultSize.width;
                windowScale.y = static_cast<float>(fullSize.height) / defaultSize.height;

                windowSize = window.getSize();

                for (RectangleShape* shadow : sShadow)
                {
                    shadow->scale(windowScale);
                    shadow->setPosition({shadow->getPosition().x * windowScale.x, shadow->getPosition().y * windowScale.y});
                }
                for (Sprite *sprite : sDraw)
                    sprite->scale(windowScale);
                for (RectangleShape* wall : walls)
                {
                    wall->scale(windowScale);
                    wall->setPosition({wall->getPosition().x * windowScale.x, wall->getPosition().y * windowScale.y});
                }
                walls.clear();
                for (int i = 0; i < 4; ++i)
                    addWall(i);
            }
            else if (event.key.code == Keyboard::F10)
            {
                fullScreen = 0;
                window.create(defaultSize, "Space Invaders",
                                        Titlebar | Close);
                
                windowScale.x = static_cast<float>(defaultSize.width) / fullSize.width;
                windowScale.y = static_cast<float>(defaultSize.height) / fullSize.height;

                windowSize = window.getSize();

                for (RectangleShape* shadow : sShadow)
                {
                    shadow->scale(windowScale);
                    shadow->setPosition({shadow->getPosition().x * windowScale.x, shadow->getPosition().y * windowScale.y});
                }
                for (Sprite* sprite : sDraw)
                    sprite->scale(windowScale);
                for (RectangleShape* wall : walls)
                {
                    wall->scale(windowScale);
                    wall->setPosition({wall->getPosition().x * windowScale.x, wall->getPosition().y * windowScale.y});
                }
                walls.clear();
                for (int i = 0; i < 4; ++i)
                    addWall(i);
                windowScale.x = 1;
                windowScale.y = 1;
            }
            else if ((event.key.code == Keyboard::F9) && (!showBorder))
            {
                showBorder = 1;
                for (RectangleShape *wall : walls)
                    wall->setFillColor({255,255,255});
            }
            else if ((event.key.code == Keyboard::F9))
            {
                showBorder = 0;
                for (RectangleShape *wall : walls)
                    wall->setFillColor({0,0,0});
            }
        }
    }
}

void Game::update()
{
    player->update();
    bool swap = enemies[0]->testCollision();
    for (Enemy* enemy : enemies)
    {
        enemy->update();
    }
    if (swap)
        enemies[0]->swapTests(enemies);
    input();
}

void Game::render()
{
    // window.clear();

    for (RectangleShape* shadow : sShadow)
        window.draw(*shadow);
    for (Sprite* sprite : sDraw)
        window.draw(*sprite);
    for (RectangleShape* wall : walls)
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
    Vector2f size;
    Vector2f pos;
    switch (side)
    {
        case TOP:
        {
            size.x = windowSize.x * PLAYPERCENT;
            size.y = 1;
            pos.x = 0;
            pos.y = 0;
            break;
        }
        case BOTTOM:
        {
            size.x = windowSize.x * PLAYPERCENT;
            size.y = 1;
            pos.x = 0;
            pos.y = windowSize.y - 1;
            break;
        }
        case LEFT:
        {
            size.x = 1;
            size.y = windowSize.y;
            pos.x = 0;
            pos.y = 0;
            break;
        }
        case RIGHT:
        {
            size.x = 1;
            size.y = windowSize.y;
            pos.x = windowSize.x * PLAYPERCENT - 1;
            pos.y = 0;
            break;
        }
    };

    RectangleShape* wall = new RectangleShape(size);
    wall->setPosition(pos);
    wall->setFillColor({0,0,0});
    walls.push_back(wall);
    cout << "Wall" << side << endl;
}
void Game::addShadow(const Vector2f &pos, const Vector2f &size)
{
    RectangleShape* shadow = new RectangleShape(size);
    shadow->setPosition(pos);
    shadow->setFillColor({0,0,0});
    sShadow.push_back(shadow);
}
void Game::loadPlayer()
{
    player = new Player;
    addDraw(player);
}
void Game::loadEnemy()
{
    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 11; ++col)
        {
            Enemy* enemy = new Enemy(row, col);
            enemies.push_back(enemy);
            addDraw(enemy);
        }
    }
}