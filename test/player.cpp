#include "player.h"
#include "game.h"

Player::Player() : Sprite(PLAYER)
{
    speed = 5;
    health = 3;
    setPosition((Game::windowSize.x * PLAYPERCENT / 2) - 25, Game::windowSize.y * .9 + Game::windowSize.y * .05 - 25);
}

Player::~Player()
{
    // delete bullet;
    // bullet = nullptr;
}

void Player::update(vector<Sprite*>& vec)
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

    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !(this->bulletExists))
    {
        fire(vec);
        this->bulletExists = true;
    }
    if (bulletExists)
    {
        float back = -5;
        this->bullet->move(0, back);
    }
    if ((this->bullet != nullptr) && bulletExists)
    {
        if (this->bullet->getPosition().y <= -50)
        {
            this->bulletExists = false;
        }
    }
}


void Player::fire(vector<Sprite*>& vec)
{
    this->bullet = new Bullet(BULLET, this->getPosition().x + 25, this->getPosition().y);
    vec.push_back(this->bullet);
}