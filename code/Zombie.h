#pragma once
#include "Character.h"
#include <string>

class Zombie : public Character
{
private:
	bool m_IsAlive = false;
protected:
	int m_Damage = 10;
	int m_KillScoreValue = 1;
public:
	Zombie(int, int, int, std::string);
	bool Hit(int);
	int GetKillValue() const;
	int GetDamageValue() const;
	bool IsAlive() const ;
	void Spawn(int, int) override;
	void Update(Vector2f, float);
	virtual ~Zombie();
};