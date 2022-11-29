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
}

void Engine::Update(float dtAsSeconds)
{
    if (m_Playing)
    {
        m_TimeElapsed += dtAsSeconds;
    //Check if any zombies are left in the playing field
    //Verify the health of each zombie
    }
}

void Engine::Draw()
{
    //Clear previous frame
    m_Window.clear();

    m_Window.draw(m_BackgroundSprite);
    m_Window.setView(m_MainView);

    m_Window.setView(m_HudView);

    m_Window.display();
}