#include "game.h"
#include <iostream>
using namespace std;




int main()
{
	string textureFile = "data/Sprite_Texture_Sheet_150x150.png";
	Game game;

	Sprite sprite;
	sprite.loadTexture(textureFile);
	game.addDraw(sprite);

	while (!game.isFinished())
	{
		game.update();
		game.render();
	}
	
	return 0;
}