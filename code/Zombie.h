#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Player.h"
#include <string>

using namespace sf;

class Zombie : public Character
{
private:
	void CheckCollisionWithPlayer();
	bool m_IsAlive;
protected:
	int m_Damage;
	int m_KillScoreValue = 1;
	void Damage(int);
public:
	Zombie(int, int, int, std::string);
	bool Hit();
	int GetKillValue();
	int GetDamageValue();
	bool IsAlive();
	void Spawn(int, int) override;
	void Update(Vector2f, float);
};

#endif