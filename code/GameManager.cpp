#include "GameManager.h"
#include <random>

using namespace std;

GameManager::GameManager(Vector2f _arenaSize)
{
    m_ArenaSize = _arenaSize;
}

void GameManager::CheckZombies(Vector2f _playerPosition, float _deltaTime)
{
    for (size_t i = 0; i < m_Zombies.size(); i++)
    {
        m_Zombies[i]->Update(_playerPosition, _deltaTime);
    }
}

vector<Zombie*> GameManager::GetZombies() const
{
    return m_Zombies;
}

void GameManager::StartGame()
{
    srand(420);
    Zombie* newZombie;
    Vector2i randomSpawn;

    for (int i = 0; i < MAX_ZOMBIES_ON_SCREEN; i++)
    {
        newZombie = new Zombie(m_ArenaSize.x, m_ArenaSize.y, 100);

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