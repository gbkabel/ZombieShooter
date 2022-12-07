#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Character.h"
#include <string>

using namespace sf;

class Zombie : public Character
{
private:
	bool m_IsAlive;
protected:
	int m_Damage;
	int m_KillScoreValue = 1;
	void Damage(int);
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

#endif
