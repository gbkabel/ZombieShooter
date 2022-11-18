#include <SFML/Graphics.hpp>
#include "Player.h"

// Make code easier to type with "using namespace"
using namespace sf;

int main()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y),"Zombie Shooter!", Style::Default);
	Player player;
	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/


		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame
		//window.clear();

		// Draw our game scene here
		//window.draw(spriteBackground);
		player.spawn(resolution);
		window.draw(player.getSprite());
		// Show everything we just drew
		window.display();


	}

	return 0;
}

