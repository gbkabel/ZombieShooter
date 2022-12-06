#pragma once
#include <vector>
#include "Player.h"
#include "Bullet.h"
#include "Pickup.h"
#include "Zombie.h"
#include "NormalZombie.h"
#include "CrawlerZombie.h"

using namespace std;

class GameManager
{
public:
    GameManager(Vector2f);
    void ShootBullets(Player*, Vector2f, Time);
    void CheckZombies(Player*, float);
    void CheckBullets(float);
    void CheckForCollision(Player*, Time);
    void StartGame();
    vector<Zombie*> GetZombies() const;
    vector<Bullet*> GetBullets() const;
    vector<Pickup*> GetPickups() const;
    
    enum class ZombieTypes {NORMAL, CRAWLER, TANK, SPRINTER};

private:
    const int NUM_ZOMBIE_TYPES = 2;
    const int MAX_ZOMBIES_ON_SCREEN = 100;
    Time lastPressed;
	float fireRate = 1;
	int currentBullet = 0;
    int m_Score = 0;
    Zombie* GetARandomZombie() const;
    vector<Zombie*> m_Zombies;
    vector<Bullet*> m_Bullets;
    vector<Pickup*> m_Pickups;
    Vector2f m_ArenaSize;
};