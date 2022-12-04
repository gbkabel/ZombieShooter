#include "Engine.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::Update(float dtAsSeconds)
{
    if (state == State::PLAYING)
    {
        m_TimeElapsed += dtAsSeconds;
    	player.Update(dtAsSeconds, Mouse::getPosition());

    }
}