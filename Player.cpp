#include "player.h"

Player::Player()
{
	speed = 250;
	health = 100;
	playerTexture.loadFromFile("graphics/shooter1.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(25, 25);
}

void Player::spawn(Vector2f resolution)
{
	mousePosition.x = resolution.x / 2;
	mousePosition.y = resolution.y / 2;
}

int Player::getHealth()
{
	return health;
}

Sprite Player::getSprite()
{
	return Sprite();
}

void Player::moveLeft()
{
	leftPressed = true;
}

void Player::moveRight()
{
	rightPressed = true;
}

void Player::moveUp()
{
	upPressed = true;
}

void Player::moveDown()
{
	downPressed = true;
}

void Player::stopLeft()
{
	leftPressed = false;
}

void Player::stopRight()
{
	rightPressed = false;
}

void Player::stopUp()
{
	upPressed = false;
}

void Player::stopDown()
{
	downPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	if (upPressed)
	{
		mousePosition.y -= speed * elapsedTime;
	}

	if (downPressed)
	{
		mousePosition.y += speed * elapsedTime;
	}

	if (rightPressed)
	{
		mousePosition.x += speed * elapsedTime;
	}

	if (leftPressed)
	{
		mousePosition.x -= speed * elapsedTime;
	}
	
}
