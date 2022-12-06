#include "NormalZombie.h"

NormalZombie::NormalZombie(int StartX, int StartY, std::string _path) 
: Zombie(StartX, StartY, NORMAL_HEALTH, _path)
{
    m_Speed = NORMAL_SPEED;
    m_Damage = NORMAL_DAMAGE;
    m_KillScoreValue = 10;
}