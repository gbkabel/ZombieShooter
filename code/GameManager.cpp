#include "GameManager.h"
#include <random>

using namespace std;

GameManager::GameManager(Vector2f _arenaSize)
{
    m_ArenaSize = _arenaSize;
}

void GameManager::CheckZombies(Player* _player, float _dtAsSeconds)
{
    for (size_t i = 0; i < m_Zombies.size(); i++)
    {
        if (m_Zombies[i]->IsAlive())
            m_Zombies[i]->Update(_player->GetCharPosition(), _dtAsSeconds);
    }
}

void GameManager::CheckBullets(float _dtAsSeconds)
{
    for (size_t i = 0; i < m_Bullets.size(); i++)
    {
        if (m_Bullets[i]->isInFlight()) m_Bullets[i]->update(_dtAsSeconds);
    }
}

void GameManager::CheckForCollision(Player* _player, Time _timeHit)
{
    //Check if zombies have been shot
    for (size_t i = 0; i < m_Bullets.size(); i++)
    {
        for (size_t j = 0; j < m_Zombies.size(); j++)
        {
            if (m_Bullets[i]->isInFlight() && m_Zombies[j]->IsAlive())
                {
                    if (m_Bullets[i]->getPosition().intersects(m_Zombies[j]->GetSpriteGlobalBounds()))
                    {
                        //Stop the bullet
                        m_Bullets[i]->stop();

                        if (m_Zombies[i]->Hit())
                        {
                            m_Score += m_Zombies[i]->GetKillValue();
                        }
                        
                        m_Zombies.erase(m_Zombies.begin() + i);
                    }
                }
        }
    }
    //Check if player has been touched by a zombie
    for (size_t i = 0; i < m_Zombies.size(); i++)
    {
        if (_player->GetSpriteGlobalBounds().intersects(m_Zombies[i]->GetSpriteGlobalBounds()) && m_Zombies[i]->IsAlive())
        {
            if (_player->Hit(_timeHit, m_Zombies[i]->GetDamageValue()))
            {
                cout << "Dead" << endl;
            }
        }
    }

    for (size_t i = 0; i < m_Pickups.size(); i++)
    {
        if (_player->GetSpriteGlobalBounds().intersects(m_Pickups[i]->getPosition()))
        {
            m_Pickups[i]->Obtain(_player);
        }
    }
}

vector<Zombie*> GameManager::GetZombies() const
{
    return m_Zombies;
}

vector<Bullet*> GameManager::GetBullets() const
{
    return m_Bullets;
}

void GameManager::StartGame()
{
    srand(420);
    Zombie* newZombie;
    Vector2i randomSpawn;

    for (int i = 0; i < MAX_ZOMBIES_ON_SCREEN; i++)
    {
        newZombie = GetARandomZombie();

        //pick a side of the arena
        int side = (rand() % 4); //0 is the Top side, going clockwise
        switch (side)
        {
        case 0: //Up
            randomSpawn = { rand() % (int)m_ArenaSize.x, -(int)newZombie->GetSpriteGlobalBounds().height};
            break;
        case 1: //Right
            randomSpawn = {(int)m_ArenaSize.x + (int)newZombie->GetSpriteGlobalBounds().width, rand() % (int)m_ArenaSize.y };
            break;
        case 2: //Down
            randomSpawn = { rand() % (int)m_ArenaSize.x, (int)m_ArenaSize.y + (int)newZombie->GetSpriteGlobalBounds().height};
            break;
        case 3: //Left
            randomSpawn = {-(int)newZombie->GetSpriteGlobalBounds().width, rand() % (int)m_ArenaSize.y };
            break;
        }

        newZombie->Spawn(randomSpawn.x, randomSpawn.y);

        m_Zombies.push_back(newZombie);
    }
}

Zombie* GameManager::GetARandomZombie() const
{
    int r = rand() % NUM_ZOMBIE_TYPES;
    Zombie* newZombie = nullptr;
    switch (r)
    {
        case 0:
            newZombie =  new NormalZombie(m_ArenaSize.x, m_ArenaSize.y, "graphics/normalZombie1.png");
            break;
        case 1:
            newZombie = new CrawlerZombie(m_ArenaSize.x, m_ArenaSize.y, "graphics/crawlerZombie1.png");
            break;
    }

    return newZombie;
}