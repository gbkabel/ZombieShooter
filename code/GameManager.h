#pragma once
#include <vector>
#include "Player.h"
#include "Zombie.h"

using namespace std;

class GameManager
{
public:
    GameManager(Vector2f);
    void CheckZombies(Vector2f, float);
    void StartGame();
    vector<Zombie*> GetZombies() const;

private:
    const int MAX_ZOMBIES_ON_SCREEN = 100;
    vector<Zombie*> m_Zombies;
    Vector2f m_ArenaSize;
};