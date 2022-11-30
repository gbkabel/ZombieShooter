#include "Engine.h"

Engine::Engine()
{
    Vector2f resolution = { VideoMode::getDesktopMode().width * m_WindowScale, VideoMode::getDesktopMode().height * m_WindowScale};

    m_Window.create(VideoMode(resolution.x, resolution.y),"ZombieShooterV2", Style::Resize);
    m_MainView.setSize(resolution);
    m_HudView.reset(FloatRect(0,0, resolution.x, resolution.y));

    //m_BackgroundTexture = ;
    //m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::Run()
{
    Clock clock;

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        Input();
        Update(dtAsSeconds);
        Draw();
    }
}