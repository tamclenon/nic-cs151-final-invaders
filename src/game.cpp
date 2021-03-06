/**
 * @file game.cpp
 * @author Game definition file
 * @brief Shaun Martin, Toby Mclenon
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "game.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 */
Game::Game()
{
    defaultSize = VideoMode(windowSize.x, windowSize.y);
    
    fullSize = sf::VideoMode::getDesktopMode();

    window.create(defaultSize, "Space Invaders",
								Titlebar | Close);
    // window.setMouseCursorGrabbed(true);

    fullScreen = 0;
    isDone = false;
    isPaused = true;
    isOver = false;
    
    loadWalls();
    loadShadows();
    loadPlayer();
    loadEnemy();
    loadBarrier();
    loadInfo();
}

/**
 * @brief Destroy the Game:: Game object
 * 
 */
Game::~Game()
{

}

/**
 * @brief Checks for user input and makes changes based on input
 * 
 */
void Game::input()
{
    Event event;
    while (window.pollEvent(event))
    {
        if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
        {
            info->saveHighScore();
            window.close();
            isDone = true;
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
                for (Text *text : info->drawText())
                {
                    text->scale(windowScale);
                    text->setPosition({text->getPosition().x * windowScale.x, text->getPosition().y * windowScale.y});
                }
                for (Sprite* sprite : info->drawLives())
                    sprite->scale(windowScale);
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
                for (Text *text : info->drawText())
                {
                    text->scale(windowScale);
                    text->setPosition({text->getPosition().x * windowScale.x, text->getPosition().y * windowScale.y});
                }
                for (Sprite* sprite : info->drawLives())
                    sprite->scale(windowScale);
                windowScale.x = 1;
                windowScale.y = 1;
            }
            else if ((event.key.code == Keyboard::F9) && (!showBorder))
            {
                showBorder = 1;
                for (RectangleShape *wall : walls)
                    wall->setFillColor({255,255,255});
            }
            else if (event.key.code == Keyboard::F9)
            {
                showBorder = 0;
                for (RectangleShape *wall : walls)
                    wall->setFillColor({0,0,0});
            }
            else if (isOver && event.key.code == Keyboard::Space)
            {
                restart();
                isOver = false;
                isPaused = false;
            }
            else if (event.key.code == Keyboard::P && !isPaused)
                isPaused = true;
            else if (isPaused && event.key.code == Keyboard::Space)
                isPaused = false;
            else if (event.key.code == Keyboard::R)
                restart();
        }
    }
    if (!isPaused && Keyboard::isKeyPressed(Keyboard::Space) && !(player->bulletExists()))
    {
        Bullet* bullet = player->fire();
        bullets.push_back(bullet);
        addDraw(bullet);
    }
}

/**
 * @brief Updates the game with all changes made in input section, as
 *          well as class update functions
 * 
 */
void Game::update()
{
    if (!isPaused)
    {
        for (Bullet* bullet : bullets)
        {
            bullet->update(sDraw);
            if (bullet->getHealth() == 0)
                bullet = nullptr;
        }
        removeDead();
        player->update();
        bool swap = enemies[0]->testCollision();
        for (Enemy* enemy : enemies)
        {
            enemy->update();
            if (enemy->isShoot())
            {
                Bullet* bullet = enemy->fire();
                bullets.push_back(bullet);
                addDraw(bullet);
            }
        }
        if (swap)
            enemies[0]->swapTests(enemies);
        info->update();
        if (enemies[0]->levelOver())
        {
            resetEnemies();
            info->incLevel();
            info->addToScore(1000);
        }
        if (player->getHealth() <= 0)
        {
            isPaused = true;
            isOver = true;
        }
    }
    input();
}

/**
 * @brief Renders all of the sprites
 * 
 */
void Game::render()
{
    // window.clear();
    if (!isPaused)
    {
        for (RectangleShape* shadow : sShadow)
        {
            if (shadow != nullptr)
                window.draw(*shadow);
        }
            
        for (Sprite* sprite : sDraw)
        {
            if (sprite != nullptr)
                window.draw(*sprite);
        }
        for (RectangleShape* wall : walls)
        {
            if (wall != nullptr)
                window.draw(*wall);
        }
        for (RectangleShape* wall : walls)
            window.draw(*wall);
        for (Sprite* sprite : sDraw)
            window.draw(*sprite);
        for (Text *text : info->drawText())
            window.draw(*text);
        for (Sprite* sprite : info->drawLives())
            window.draw(*sprite);
    }
    else
    {
        window.draw(*info->drawPaused());
    }
    window.display();
}

/**
 * @brief Checks whether the game is done
 * 
 * @return true Game is over
 * @return false Game is not over
 */
bool Game::isFinished()
{
    return (!window.isOpen() || isDone);
}

/**
 * @brief Adds the sprite pointer to the vector of sprites to be drawn
 * 
 * @param spr The sprite pointer to be added to the vector
 */
void Game::addDraw(Sprite* spr)
{
    sDraw.push_back(spr);
}

/**
 * @brief Add walls to the game
 * 
 * @param side The side to add the walls to
 */
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
}
/**
 * @brief Adds a shadow to the shadow vector
 * 
 * @param pos The position data of the shadow
 * @param size The size of the shadow
 */
void Game::addShadow(const Vector2f &pos, const Vector2f &size)
{
    RectangleShape* shadow = new RectangleShape(size);
    shadow->setPosition(pos);
    shadow->setFillColor({0,0,0});
    sShadow.push_back(shadow);
}

void Game::loadWalls()
{
    showBorder = 0;
    for (int i = 0; i < 4; ++i)
        addWall(i);
}
void Game::loadShadows()
{
    addShadow({0,0}, {(windowSize.x * PLAYPERCENT),(windowSize.y * .7f)});
    addShadow({0,(windowSize.y * .7f)}, {(windowSize.x * PLAYPERCENT),(windowSize.y * .2f)});
    addShadow({0,(windowSize.y * .9f)}, {(windowSize.x * PLAYPERCENT),(windowSize.y * .1f)});
    addShadow({(windowSize.x * PLAYPERCENT),0}, {(windowSize.x * (1 - PLAYPERCENT)),(windowSize.y * .3f)});
    addShadow({(windowSize.x * PLAYPERCENT),(windowSize.y * .8f)}, {(windowSize.x * (1 - PLAYPERCENT)),(windowSize.y * .2f)});
}
/**
 * @brief Initialize a new player sprite
 * 
 */
void Game::loadPlayer()
{
    player = new Player;
    addDraw(player);
}
/**
 * @brief Initialize enemy sprites
 * 
 */
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
    enemies[0]->swapTests(enemies);
}
/**
 * @brief Initialize barriers
 * 
 */
void Game::loadBarrier()
{
    for (int set = 1; set <= 4; ++set)
    {
        for (int row = 0; row < 5; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                if (!((row == 0 && col == 0) || (row == 0 && col == 7) || (row == 4 && col == 0) || (row == 4 && col == 7)))
                {
                    Vector2f pos = {((windowSize.x * PLAYPERCENT / 5 * set - 40.0f) + (10 * col)), ((windowSize.y * .7f) + (10 * row))};
                    Barrier* barrier = new Barrier(row, col, pos);
                    barriers.push_back(barrier);
                    addDraw(barrier);
                }
            }
        }
    }
}
/**
 * @brief initialize the info board
 * 
 */
void Game::loadInfo()
{
    info = new Info(player);
}

/**
 * @brief stop dead enemies from being drawn
 * 
 */
void Game::removeDead()
{
    int i = 0;
    while (i < bullets.size())
    {
        if (bullets[i] == nullptr || bullets[i]->getHealth() == 0)
        {
            bullets[i] = bullets[bullets.size() - 1];
            bullets.pop_back();
        }
        else
            ++i;
    }
    i = 0;
    while (i < sDraw.size())
    {
        if (sDraw[i] == nullptr || (sDraw[i]->getHealth() == 0 && sDraw[i]->getType() != PLAYER))
        {
            if (sDraw[i] != nullptr && sDraw[i]->getType() == ENEMY)
                enemies[0]->deathCount();
            sDraw[i] = sDraw[sDraw.size() - 1];
            sDraw.pop_back();
        }
        else
            ++i;
    }
}
/**
 * @brief Reinitialize enemies
 * 
 */
void Game::resetEnemies()
{
    int i = 0;
    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 11; ++col)
        {
            enemies[i]->setPosition({col * 60.0f, row * 60.0f});
            enemies[i]->setColumn(col);
            enemies[i]->setHealth(1);
            addDraw(enemies[i]);
            ++i;
        }
    }
    enemies[0]->swapTests(enemies);
    enemies[0]->setDirection(RIGHT);
}
/**
 * @brief Restarts game
 * 
 */
void Game::restart()
{
    info->saveHighScore();
    delete info;
    resetEnemies();
    player->setHealth(3);
    for (Bullet* bullet : bullets)
        bullet->setHealth(0);
    for (Barrier* barrier : barriers)
    {
        if (barrier->getHealth() <= 0)
        {
            barrier->setHealth(1);
            addDraw(barrier);
        }
    }
    loadInfo();
}