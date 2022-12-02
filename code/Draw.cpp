#include "Engine.h"

void Engine::Draw()
{
    //Clear previous frame
    m_Window.clear();
    m_Window.setView(m_MainView);
    m_Window.setView(m_HudView);    

	m_Window.draw(background, &textureBackground);
	m_Window.draw(player.GetSprite());
        
	m_Window.display();
}