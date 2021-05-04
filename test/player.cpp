#include "player.h"
using std::cout;
using std::endl;

Player::Player(int type) : Sprite(type)
{
    speed = 5;
    setPosition((Game::windowSize.x * .56 / 2) - 25, Game::windowSize.y * .9 + Game::windowSize.y * .05 - 25);
}

Player::~Player()
{

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
}