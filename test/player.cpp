#include "player.h"
using std::cout;
using std::endl;

Player::Player(int type, const Game& game) : Sprite(type)
{
    setPosition((Game::windowSize.x / 2) - 25, Game::windowSize.y - 50);
    loadShadow();
}

Player::~Player()
{

}

void Player::playerUpdate()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(Game::windowScale.x * 5, 0); // (static_cast<float>(vec.x) + 3) / 150
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(Game::windowScale.x * -5, 0); // -(static_cast<float>(vec.x) + 3) / 150
    }
}