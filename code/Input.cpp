#include "Engine.h"
#include "ZombieShooter.h"

void Engine::Input()
{
	IntRect arena;
  	Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			m_Window.close();
			break;

		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape) m_Window.close();
			if (event.key.code == Keyboard::Enter) 
			{
				if (state == State::MAIN_MENU || state == State::GAME_OVER)
				{
					//Prepare level
					arena.width = windowSize.x;
					arena.height = windowSize.y;
					arena.left = 0;
					arena.top = 0;

					//int tileSize = 
					CreateBackground(background, arena);
					gm->StartGame();
					

					state = State::PLAYING;
					player->Spawn(windowSize.x/2, windowSize.y/2);

					clock.restart();
					}
				}
				break;

			default:
				break;
			}
		}	

    
	// Where is the mouse pointer
	mouseScreenPosition = Mouse::getPosition();

	// Convert mouse position to world coordinates of mainView
	//mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), main_view);

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->MoveUp();
	}
	else
	{
		player->StopUp();
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->MoveDown();
	}
	else
	{
		player->StopDown();
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->MoveLeft();
	}
	else
	{
		player->StopLeft();
	}
    
    if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->MoveRight();
	}
	else
	{
		player->StopRight();
	}

    // Make a note of the players new position
	Vector2f playerPosition(player->GetCharPosition());
}
