#include "CrawlerZombie.h"

CrawlerZombie::CrawlerZombie(int StartX, int StartY, std::string _path) 
: Zombie(StartX, StartY, CRAWLER_HEALTH, _path)
{
    m_Speed = CRAWLER_SPEED;
    m_Damage = CRAWLER_DAMAGE;
    m_KillScoreValue = 20;
    SetHealth(CRAWLER_HEALTH);
}