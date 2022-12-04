#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Player.h"

class Zombie : public Player
{
private:
	Texture zombieTexture;
	Sprite zombieSprite;
	Vector2f zombiePosition;
public:
	Zombie();
	void Spawn(int, int);
};

#endif