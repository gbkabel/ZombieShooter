#include "Engine.h"

void Engine::Input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        switch (event.type)
        {
            case (Event::KeyPressed):
                if (event.key.code == Keyboard::Escape)
                {
                    m_Window.close();
                }
                if (event.key.code == Keyboard::Enter)
                {
                    m_Playing = true;
                }
                break;

            case (Event::Closed):
                m_Window.close();
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

    // Make a note of the players new position
	Vector2f playerPosition(player.GetCenter());
}