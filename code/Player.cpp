#include "Player.h"

Player::Player(int windowSizeX, int windowSizeY)
{
	arenaSize = {windowSizeX, windowSizeY};
	playerTexture.loadFromFile("shooter1.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width/2, playerSprite.getLocalBounds().height/2);
	playerPosition = {(float) windowSizeX/2, (float) windowSizeY/2};
}

Sprite Player::getSprite()
{
	return playerSprite;
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

FloatRect Player::getPosition()
{
	return playerSprite.getGlobalBounds();
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	DetermineMoveDirection(elapsedTime); //Check Input
	ValidateCollision(); //Check collision

	//Move the player and set sprite scale (which way its facing)
	playerSprite.setScale(spriteHDirection, 1);
	playerSprite.setPosition(playerPosition);
}

void Player::ValidateCollision()
{
	// Keep the player in the arena
	Rect playerBounds = playerSprite.getLocalBounds();

	if (playerPosition.x > arenaSize.x - playerBounds.width)
	{
		playerPosition.x = arenaSize.x - playerBounds.width;
	}

	if (playerPosition.x < 0 + playerBounds.width)
	{
		playerPosition.x = 0 + playerBounds.width;
	}

	if (playerPosition.y > arenaSize.y - playerBounds.height)
	{
		playerPosition.y = arenaSize.y - playerBounds.height;
	}

	if (playerPosition.y < 0 + playerBounds.height)
	{
		playerPosition.y = 0 + playerBounds.height;
	}
}

void Player::DetermineMoveDirection(float _elapsedTime)
{
	if (upPressed)
	{
		playerPosition.y -= speed * _elapsedTime;
	}

	if (downPressed)
	{
		playerPosition.y += speed * _elapsedTime;
	}

	if (rightPressed)
	{
		spriteHDirection = 1;
		playerPosition.x += speed * _elapsedTime;
	}

	if (leftPressed)
	{
		spriteHDirection = -1;
		playerPosition.x -= speed * _elapsedTime;
	}
}