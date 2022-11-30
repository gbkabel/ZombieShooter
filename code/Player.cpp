#include "Player.h"
#include <iostream>

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
	DetermineMoveDirection(); //Check Input

	playerPosition.x += playerInputVector.x * speed * elapsedTime;
	playerPosition.y -= playerInputVector.y * speed * elapsedTime;

	ValidateCollision(); //Check collision

	//Move the player and set sprite scale (which way its facing)
	playerSprite.setScale(spriteHDirection, 1);
	playerSprite.setPosition(playerPosition);
}

void Player::ValidateCollision()
{
	// Keep the player in the arena
	Rect playerBounds = playerSprite.getLocalBounds();

	if (playerPosition.x > arenaSize.x - (playerBounds.width/2))
	{
		playerPosition.x = arenaSize.x - (playerBounds.width/2);
	}

	if (playerPosition.x < (playerBounds.width/2))
	{
		playerPosition.x = (playerBounds.width/2);
	}

	if (playerPosition.y > arenaSize.y - (playerBounds.height/2))
	{
		playerPosition.y = arenaSize.y - (playerBounds.height/2);
	}

	if (playerPosition.y < (playerBounds.height/2))
	{
		playerPosition.y = (playerBounds.height/2);
	}
}

void Player::DetermineMoveDirection()
{
	Vector2f rawInput = {0, 0};
	playerInputVector = rawInput;

	rawInput.x = rightPressed - leftPressed;
	rawInput.y = upPressed - downPressed;

	//Normalize Input vector so that the magnitude is always 1
	if (abs(rawInput.x) > 0 || abs(rawInput.y) > 0)
	{
		float m = sqrt((rawInput.x * rawInput.x) + (rawInput.y * rawInput.y));
		playerInputVector.x = rawInput.x / m;
		playerInputVector.y = rawInput.y / m;

		if (abs(rawInput.x) > 0)
		{
			spriteHDirection = rawInput.x;
		}
	}
}

Time Player::getLastHitTime()
{
	return m_LastHit;
}

bool Player::Hit(Time timeHit, int damage)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > HIT_INVINCIBILITY_TIME_MS)
	{
		m_LastHit = timeHit;
		m_Health -= damage;
		return true;
	}
	else return false;
}

void Player::Heal(int amount)
{
	m_Health += amount;


}