#include "player.h"
#include "game.h"

Player::Player() : Sprite(PLAYER)
{
    speed = 5;
    health = 3;
    setPosition((Game::windowSize.x * PLAYPERCENT / 2) - 25, Game::windowSize.y * .9 + Game::windowSize.y * .05 - 25);
    bullet = nullptr;
}

Player::~Player()
{
    // delete bullet;
    // bullet = nullptr;
}

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


Bullet* Player::fire()
{
    bullet = new Bullet(getPosition().x + 20, getPosition().y - 50, PLAYER);
    return bullet;
}
bool Player::bulletExists()
{
    return bullet != nullptr;
}