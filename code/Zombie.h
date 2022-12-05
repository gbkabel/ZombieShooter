#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Player.h"

using namespace sf;

class Zombie : public Character
{
private:
	int damage;
	void Damage(int);
public:
	Zombie(int, int, int);
	void Spawn(int, int) override;
	void Update(Vector2f, float);
};

#endif