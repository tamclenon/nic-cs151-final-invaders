/**
 * @file player.cpp
 * @author Toby Mclenon
 * @brief Player class definition file
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "player.h"
#include "game.h"

/**
 * @brief Construct a new Player:: Player object
 * 
 */
Player::Player() : Sprite(PLAYER)
{
    speed = 5;
    health = 3;
    setPosition((Game::windowSize.x * PLAYPERCENT / 2) - 25, Game::windowSize.y * .9 + Game::windowSize.y * .05 - 25);
    bullet = nullptr;
}

/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player()
{

}

/**
 * @brief Checks for user input and updates player
 * 
 */
void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(Game::windowScale.x * speed, 0);
        if (isCollision(Game::walls[RIGHT]))
            move(Game::windowScale.x * -speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move(Game::windowScale.x * -speed, 0);
        if (isCollision(Game::walls[LEFT]))
            move(Game::windowScale.x * speed, 0);
    }
    if (bullet != nullptr && bullet->getHealth() == 0)
    {
        delete bullet;
        bullet = nullptr;
    }
}

/**
 * @brief Creates a new member instance of Bullet (fires a bullet)
 * 
 * @return Bullet* The Bullet pointer to assign the new bullet to
 */
Bullet* Player::fire()
{
    bullet = new Bullet(getPosition().x + 20, getPosition().y - 50, PLAYER);
    return bullet;
}
/**
 * @brief Checks whether player bullet is still on screen
 * 
 * @return true Bullet is on screen
 * @return false Bullet is not on screen
 */
bool Player::bulletExists()
{
    return bullet != nullptr;
}