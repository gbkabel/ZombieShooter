#include "player.h"

Player::Player()
{
	speed = 250;
	health = 100;
	playerTexture.loadFromFile("graphics/player.png");
	playerSprite.setTexture(playerTexture);
}