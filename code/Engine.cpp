#include "Engine.h"
#include "Zombie.h"

Engine::Engine()
{
	player = new Player(windowSize.x, windowSize.y, 100, "graphics/shooter2.png");
    gm = new GameManager({windowSize.x, windowSize.y});
    
    m_Window.create(VideoMode(windowSize.x, windowSize.y), "Zombie Shooter V2");
    m_MainView.setSize(windowSize);
    m_HudView.reset(FloatRect(0,0, windowSize.x, windowSize.y));

	m_TitleFont.loadFromFile("fonts/Zombie.ttf");
	m_UiFont.loadFromFile("fonts/Neo Tech.ttf");

    textbox.setFont(m_TitleFont);
    textbox.setOutlineColor(Color::Black);
    textbox.setOutlineThickness(2);

	textureBackground.loadFromFile("graphics/Tiles.png");

	textureCrosshair.loadFromFile("graphics/crosshair1.png");
    spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(spriteCrosshair.getGlobalBounds().width/2, spriteCrosshair.getGlobalBounds().height/2);
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
