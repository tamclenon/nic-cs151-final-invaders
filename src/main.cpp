#include "game.h"
#include "spriteRule.h"
#include <iostream>
using namespace std;



int main()
{
	cout << SPRITE_IMAGES[0][0].spriteX << ' ' << SPRITE_IMAGES[0][0].spriteY << '\n';
	Game game;

	while (!game.isFinished())
	{
		game.update();
		game.render();
	}
	
	return 0;
}