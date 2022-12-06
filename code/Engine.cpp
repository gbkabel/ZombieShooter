#include "Engine.h"
#include "Zombie.h"

Engine::Engine()
{
	player = new Player(windowSize.x, windowSize.y, 100, "graphics/shooter1.png");
    gm = new GameManager({windowSize.x, windowSize.y});
    
    m_Window.create(VideoMode(windowSize.x, windowSize.y), "Zombie Shooter V2");
    m_MainView.setSize(windowSize);
    m_HudView.reset(FloatRect(0,0, windowSize.x, windowSize.y));

	font.loadFromFile("fonts/Zombie.ttf");
    textBox.setFont(font);

	textureBackground.loadFromFile("graphics/Tiles.png");
}

void Engine::Run()
{
    while (m_Window.isOpen())
    {
        Time dt = clock.restart();
        m_TotalGameTime += dt;

        Input();
        Update(dt.asSeconds());
        Draw();
	}
}