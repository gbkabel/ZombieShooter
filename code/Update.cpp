#include "Engine.h"
#include "Player.h"

#include <sstream>

void Engine::Update(float _dt)
{
    if (state == State::PLAYING)
    {
        m_TimeElapsed += _dt;
    	if (player->Update(_dt, Mouse::getPosition()))
        {
            gm->CheckBullets(_dt);
            gm->CheckZombies(player, _dt);
            gm->CheckForCollision(player, m_TotalGameTime);
        }
        else state = State::GAME_OVER;
    }
}