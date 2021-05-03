#include "game.h"
#include "enemyLogic.h"
#include "player.h"

#include <time.h>
#include <unistd.h>
#include <iostream>
using namespace std;




int main()
{
	Game game;

	//Enemy sprite(enemy1);
	//sprite.loadTexture(textureFile);
	//game.addDraw(sprite);

	Sprite* playerS = new Player(0, game);
	playerS->loadTexture(textureFile);
	game.addDraw(playerS);

	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
    sf::Clock clock; // starts the clock
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int fps = 0;
	int ups = 0;
	float seconds = 0;

	while (!game.isFinished())
	{
		timeSinceLastUpdate += clock.restart();
		seconds += timeSinceLastUpdate.asSeconds();
		// cout << seconds << endl;
		if (seconds >= 1.0)
		{
			cout << "FPS: " << fps << "\tUPS: " << ups << "\tIn " << seconds << endl;
			seconds = 0;
			ups = 0;
			fps = 0;
		}
		while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            game.update();
			++ups;
        }
		game.render();
		++fps;
	}
	delete playerS;
	
	return 0;
}