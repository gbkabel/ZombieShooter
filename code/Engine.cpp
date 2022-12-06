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
    textbox.setFont(font);
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