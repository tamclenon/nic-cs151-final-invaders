#include "player.h"
using std::cout;
using std::endl;

Player::Player(int type, const Game& game)
{
    type = player;
    sf::Vector2u windowSize = game.window.getSize();
    spriteType = SPRITE_TYPES[type];
    image = SPRITE_IMAGES[type];
    this->setPosition((windowSize.x / 2) - 25, windowSize.y - 50);
}

Player::~Player()
{

}

void Player::changePos(sf::RenderWindow window)
{
    this->setPosition(getPosition().x, window.getSize().y - 50);
}

void Player::playerUpdate(Vector2u vec)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ((this->getPosition().x + 50) <= vec.x))
    {
        this->move((static_cast<float>(vec.x) + 3) / 150, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ((this->getPosition().x) >= 0))
    {
        this->move(-(static_cast<float>(vec.x) + 3) / 150, 0);
    }
}