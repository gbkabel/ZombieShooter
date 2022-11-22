#include <SFML/Graphics.hpp>
#include "Player.h"

#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 360), "zombie");
	Player player;
	Clock clock;
	Time gameTimeTotal;
	Vector2i mouseScreenPosition;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player.moveUp();
		}
		else
		{
			player.stopUp();
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player.moveDown();
		}
		else
		{
			player.stopDown();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player.moveLeft();
		}
		else
		{
			player.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player.moveRight();
		}
		else
		{
			player.stopRight();
		}
		Time dt = clock.restart();
		
		gameTimeTotal += dt;
		// Make a decimal fraction of 1 from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Where is the mouse pointer
		mouseScreenPosition = Mouse::getPosition();

		// Convert mouse position to world coordinates of mainView
		//mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

		// Update the player
		player.update(dtAsSeconds, Mouse::getPosition());

		// Make a note of the players new position
		//Vector2f playerPosition(player.getCenter());
		window.clear();
		window.draw(player.getSprite());
		window.display();
	}
}

