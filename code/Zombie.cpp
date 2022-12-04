#include "Zombie.h"

Zombie::Zombie()
{
	zombieTexture.loadFromFile("graphics/zombie1.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setOrigin(zombieSprite.getLocalBounds().width / 2, zombieSprite.getLocalBounds().height / 2);
	zombieSprite.setPosition(-zombieSprite.getLocalBounds().width, -zombieSprite.getLocalBounds().height);
}

void Zombie::Spawn(int windowX, int windowY)
{
	arenaSize = { windowX, windowY };
	zombiePosition = { (float)windowX / 4, (float)windowY / 4 };
}

