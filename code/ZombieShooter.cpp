#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ZombieShooter.h"
#include <iostream>

using namespace sf;


int main()
{
	Vector2i windowSize = {640, 368};
	RenderWindow window(VideoMode(windowSize.x, windowSize.y), "Zombie Shooter V2");

	enum class State { MAIN_MENU, PAUSED, GAME_OVER, PLAYING };
	State state = State::MAIN_MENU;

	Player player;
	IntRect arena;

	VertexArray background;
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/Tiles.png");


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

			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) window.close();
				if (event.key.code == Keyboard::Enter) 
				{
					if (state == State::MAIN_MENU || state == State::GAME_OVER)
					{
						//Prepare level
						arena.width = windowSize.x;
						arena.height = windowSize.y;
						arena.left = 0;
						arena.top = 0;

						int tileSize = CreateBackground(background, arena);

						state = State::PLAYING;
						player.Spawn(windowSize.x, windowSize.y);
						clock.restart();
					}
				}
				break;

			default:
				break;
			}
		}

		if (state == State::PLAYING)
		{
			Time dt = clock.restart();
			gameTimeTotal += dt;

			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();

			// Where is the mouse pointer
			mouseScreenPosition = Mouse::getPosition();

			// Convert mouse position to world coordinates of mainView
			//mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), main_view);


			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.MoveUp();
			}
			else
			{
				player.StopUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.MoveDown();
			}
			else
			{
				player.StopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.MoveLeft();
			}
			else
			{
				player.StopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.MoveRight();
			}
			else
			{
				player.StopRight();
			}

			// Update the player
			player.Update(dtAsSeconds, Mouse::getPosition());
		}

		
		// Make a note of the players new position
		Vector2f playerPosition(player.GetCenter());
		window.clear();

		window.draw(background, &textureBackground);

		window.draw(player.GetSprite());
		window.display();
	}
}