#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::Update(float dtAsSeconds)
{
    if (m_Playing)
    {
        m_TimeElapsed += dtAsSeconds;
    //Check if any zombies are left in the playing field
    //Verify the health of each zombie
    }
}