#include "game.h"



int main()
{
	Game game;

	while (!game.isFinished())
	{
		game.update();
		game.render();
	}
	
	return 0;
}