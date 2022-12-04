#include "Player.h"
#include <iostream>

Player::Player()
{
	playerTexture.loadFromFile("graphics/shooter1.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width/2, playerSprite.getLocalBounds().height/2);
	playerSprite.setPosition(-playerSprite.getLocalBounds().width, -playerSprite.getLocalBounds().height);
}

void Player::Spawn(int windowX, int windowY)
{
	arenaSize = {windowX, windowY};
	playerPosition = {(float) windowX/2, (float) windowY/2};
}

Sprite Player::GetSprite()
{
	return playerSprite;
}

void Player::MoveLeft()
{
	leftPressed = true;
}

void Player::MoveRight()
{
	rightPressed = true;
}

void Player::MoveUp()
{
	upPressed = true;
}

void Player::MoveDown()
{
	downPressed = true;
}

void Player::StopLeft()
{
	leftPressed = false;
}

void Player::StopRight()
{
	rightPressed = false;
}

void Player::StopUp()
{
	upPressed = false;
}
void Player::StopDown()
{
	downPressed = false;
}

FloatRect Player::GetPosition()
{
	return playerSprite.getGlobalBounds();;
}

Vector2f Player::GetCenter()
{
	return playerPosition;
}

void Player::Update(float elapsedTime, Vector2i mousePosition)
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
	FloatRect playerBounds = playerSprite.getLocalBounds();

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

Time Player::GetLastHitTime()
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
	if (m_Health > m_MaxHealth) m_Health = m_MaxHealth;
}