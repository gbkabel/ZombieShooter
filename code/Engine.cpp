#include "Engine.h"
#include "ZombieShooter.h"

Engine::Engine()
{

    m_Window.create(VideoMode(windowSize.x, windowSize.y), "Zombie Shooter V2");
    m_MainView.setSize(windowSize);
    m_HudView.reset(FloatRect(0,0, windowSize.x, windowSize.y));

	textureBackground.loadFromFile("graphics/Tiles.png");
}

void Engine::Run()
{
	enum class State { MAIN_MENU, PAUSED, GAME_OVER, PLAYING };
	State state = State::MAIN_MENU;
	IntRect arena;

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();
        gameTimeTotal += dt;

        // Make a decimal fraction of 1 from the delta time
        float dtAsSeconds = dt.asSeconds();

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

						int tileSize = CreateBackground(background, arena);

						state = State::PLAYING;
                        m_Playing = true;
						player.Spawn(windowSize.x, windowSize.y);
						clock.restart();
					}
				}
				break;

			default:
				break;
			}
		}	
        Input();
        Update(dtAsSeconds);
        Draw();
	}
}