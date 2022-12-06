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
            gm->CheckZombies(player, _dt);
            gm->ShootBullets(player, m_TotalGameTime);
            gm->CheckForCollision(player, m_TotalGameTime);
            gm->CheckBullets(_dt);
        }
        else state = State::GAME_OVER;
    }
}