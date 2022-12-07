#include "Engine.h"
#include "Player.h"

#include <sstream>

void Engine::Update(float _dt)
{
    if (state == State::PLAYING)
    {
        m_TimeElapsed += _dt;
        if (player->GetHealth() <= 0) 
        {
            state = State::GAME_OVER;
            gm->Reset();
        }
        player->Update(_dt);
        weapon.Update(player->GetCharPosition(), mouseScreenPosition);
        gm->Update(m_TotalGameTime);
        gm->CheckZombies(player, _dt);
        gm->ShootBullets(player, mouseScreenPosition, m_TotalGameTime);
        gm->CheckForCollision(player, m_TotalGameTime);
        gm->CheckBullets(_dt);
    }
}
