#include "Engine.h"

void Engine::Draw()
{
    //Clear previous frame
    m_Window.clear();

    m_Window.draw(m_BackgroundSprite);
    m_Window.setView(m_MainView);

    m_Window.setView(m_HudView);

    m_Window.display();
}