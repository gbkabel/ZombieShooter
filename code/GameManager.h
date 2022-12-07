#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Player.h"
#include "Bullet.h"
#include "Pickup.h"
#include "Zombie.h"
#include "NormalZombie.h"
#include "CrawlerZombie.h"

class GameManager
{
private:
    const int NUM_ZOMBIE_TYPES = 2;
    const int NUM_STARTING_ZOMBIES = 15;
    const size_t MAX_ZOMBIES_ON_SCREEN = 100;
    const int SPAWN_COOLDOWN_AMOUNT = 200;
    Time lastSpawn;
    Time lastPressed;
	float fireRate = 1;
	int currentBullet = 0;
    int m_Score = 0;
    Zombie* GetARandomZombieType() const;
    void SpawnNewZombie();
    vector<Zombie*> m_Zombies;
    vector<Bullet*> m_Bullets;
    vector<Pickup*> m_Pickups;
    Vector2f m_ArenaSize;
public:
    GameManager(Vector2f);
    void ShootBullets(Player*, Vector2f, Time);
    void CheckZombies(Player*, float);
    void CheckBullets(float);
    void CheckForCollision(Player*, Time);
    void StartGame();
    void Reset();
    void Update(Time);
    int GetScore();
    vector<Zombie*> GetZombies() const;
    vector<Bullet*> GetBullets() const;
    vector<Pickup*> GetPickups() const;
    enum class ZombieTypes {NORMAL, CRAWLER, TANK, SPRINTER};
};

#endif
