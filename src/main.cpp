#include "game.h"
#include "enemyLogic.h"
#include <iostream>
using namespace std;




int main()
{
	string textureFile = "data/Sprite_Texture_Sheet_150x150.png";
	Game game;

	Enemy sprite(player);
	sprite.loadTexture(textureFile);
	game.addDraw(sprite);

	while (!game.isFinished())
	{
		game.update();
		game.render();
	}
	
	return 0;
}