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
}