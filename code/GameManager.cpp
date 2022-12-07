#include "GameManager.h"
#include "Engine.h"
#include "Bullet.h"
#include <random>


GameManager::GameManager(Vector2f _arenaSize)
{
	m_ArenaSize = _arenaSize;
	m_ShootBuffer.loadFromFile("sounds/8bit-Gunshot1.wav");
	m_ShootSound.setBuffer(m_ShootBuffer);
}

Zombie* GameManager::GetARandomZombieType() const
{
	int r = rand() % NUM_ZOMBIE_TYPES;
	Zombie* newZombie = nullptr;
	switch (r)
	{
	case 0:
		newZombie = new NormalZombie(m_ArenaSize.x, m_ArenaSize.y, "graphics/normalZombie1.png");
		break;
	case 1:
		newZombie = new CrawlerZombie(m_ArenaSize.x, m_ArenaSize.y, "graphics/crawlerZombie1.png");
		break;
	}
	return newZombie;
}

void GameManager::SpawnNewZombie()
{
	Zombie* newZombie;
	Vector2i randomSpawn;

	newZombie = GetARandomZombieType();

	//pick a side of the arena
	int side = (rand() % 4); //0 is the Top side, going clockwise
	switch (side)
	{
	case 0: //Up
		randomSpawn = { rand() % (int)m_ArenaSize.x, -(int)newZombie->GetSpriteGlobalBounds().height };
		break;
	case 1: //Right
		randomSpawn = { (int)m_ArenaSize.x + (int)newZombie->GetSpriteGlobalBounds().width, rand() % (int)m_ArenaSize.y };
		break;
	case 2: //Down
		randomSpawn = { rand() % (int)m_ArenaSize.x, (int)m_ArenaSize.y + (int)newZombie->GetSpriteGlobalBounds().height };
		break;
	case 3: //Left
		randomSpawn = { -(int)newZombie->GetSpriteGlobalBounds().width, rand() % (int)m_ArenaSize.y };
		break;
	}

	newZombie->Spawn(randomSpawn.x, randomSpawn.y);
	m_Zombies.push_back(newZombie);
}

void GameManager::StartGame()
{
	m_Score = 0;
	for (int i = 0; i < NUM_STARTING_ZOMBIES; i++)
	{
		SpawnNewZombie();
	}
}

void GameManager::Update(Time _gameTime)
{
	if (m_Zombies.size() < MAX_ZOMBIES_ON_SCREEN && _gameTime.asMilliseconds() - lastSpawn.asMilliseconds() > SPAWN_COOLDOWN_AMOUNT)
	{
		SpawnNewZombie();
		lastSpawn = _gameTime;
	}
}

int GameManager::GetScore() const
{
	return m_Score;
}


void GameManager::Reset()
{
	for (size_t i = 0; i < m_Zombies.size(); i++)
	{
		delete m_Zombies[i];
	}
	m_Zombies.clear();

	for (size_t i = 0; i < m_Bullets.size(); i++)
	{
		delete m_Bullets[i];
	}
	m_Bullets.clear();
}

void GameManager::CheckZombies(Player* _player, float _dtAsSeconds)
{
	for (size_t i = 0; i < m_Zombies.size(); i++)
	{
		if (m_Zombies[i]->IsAlive())
		{
			m_Zombies[i]->Update(_player->GetCharPosition(), _dtAsSeconds);
		}
	}
}

void GameManager::ShootBullets(Player* _player, Vector2f _direction, Time _totalGameTime)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (_totalGameTime.asMilliseconds() - lastPressed.asMilliseconds() > 100 / fireRate)
		{
			Bullet* newBullet = new Bullet();
			m_Bullets.push_back(newBullet);
			newBullet->shoot(_player->GetCharPosition().x, _player->GetCharPosition().y, _direction.x, _direction.y);
			m_ShootSound.play();
			lastPressed = _totalGameTime;
		}
	}
}

void GameManager::CheckBullets(float _dtAsSeconds)
{
	for (size_t i = 0; i < m_Bullets.size(); i++)
	{
		if (m_Bullets[i]->isInFlight())
		{
			m_Bullets[i]->update(_dtAsSeconds);
		}
		else
		{
			delete m_Bullets[i];
			m_Bullets.erase(m_Bullets.begin() + i);
		}
	}
}

void GameManager::CheckForCollision(Player* _player, Time _timeHit)
{
	//Check if zombies have been shot
	for (size_t i = 0; i < m_Bullets.size(); i++)
	{
		for (size_t j = 0; j < m_Zombies.size(); j++)
		{
			if (m_Bullets[i]->isInFlight())
			{
				if (m_Zombies[j]->IsAlive())
				{
					if (m_Bullets[i]->getPosition().intersects(m_Zombies[j]->GetSpriteGlobalBounds()))
					{
						//Stop the bullet
						m_Bullets[i]->stop();

						if (m_Zombies[j]->Hit(25))
						{
							m_Score += m_Zombies[j]->GetKillValue();

							delete m_Zombies[j];
							m_Zombies.erase(m_Zombies.begin() + j);
						}

						delete m_Bullets[i];
						m_Bullets.erase(m_Bullets.begin() + i);
						break;
					}
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

			}
		}
	}
	//Check if player has touched a collision
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
