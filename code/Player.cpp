#include "Player.h"
#include <iostream>


Player::Player(int startingHealth, int arenaX, int arenaY) : Character(startingHealth)
{
	LoadAndSetTextureFromFile("graphics/shooter1.png");
	SetSpriteOrigin({m_Sprite.getLocalBounds().width/2, m_Sprite.getLocalBounds().height/2});
	SetPosition({-m_Sprite.getLocalBounds().width, -m_Sprite.getLocalBounds().height});
	//Initialize the Player in the top right corner of the world, just off screen
	m_ArenaSize = {arenaX, arenaY};
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

void Player::Spawn(int _startPositionX, int _startPositionY)
{
    this->SetPosition({(float)_startPositionX, (float)_startPositionY});	
}

void Player::Update(float elapsedTime, Vector2i mousePosition)
{
	DetermineMoveDirection(); //Check Input

	Vector2f desiredDirection = {m_CharPosition.x, m_CharPosition.y};
	desiredDirection += {playerInputVector.x * m_Speed * elapsedTime, playerInputVector.y * -m_Speed * elapsedTime};


	SetPosition(desiredDirection);

	//Move the player and set sprite scale (which way its facing)
	m_Sprite.setScale(m_SpriteHDirection, 1);
	
	ValidateCollision(); //Check collision
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
			m_SpriteHDirection = rawInput.x;
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