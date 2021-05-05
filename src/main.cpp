#include "game.h"
#include "enemy.h"
#include "player.h"

#include <time.h>
#include <unistd.h>



Vector2f Game::windowScale = {1,1};
Vector2u Game::windowSize = {1333, 750};
// vector<Sprite*> Game::sDraw;
vector<sf::RectangleShape*> Game::sShadow;
vector<RectangleShape*> Game::walls;

int Enemy::direction = RIGHT;
bool Enemy::collision;
int Enemy::shots;

int main()
{
	srand(time(0));
	Game game;

	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
    sf::Clock clock; // starts the clock
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	// int fps = 0;
	// int ups = 0;
	// float seconds = 0;

	while (!game.isFinished())
	{
		timeSinceLastUpdate += clock.restart();
		// seconds += timeSinceLastUpdate.asSeconds();
		// cout << seconds << endl;
		// if (seconds >= 1.0)
		// {
		// 	seconds = 0;
		// 	ups = 0;
		// 	fps = 0;
		// }
		while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            game.update();
			// ++ups;
        }
		game.render();
		// ++fps;
	}
	// delete playerS;
	// delete enemy;
	
	return 0;
}