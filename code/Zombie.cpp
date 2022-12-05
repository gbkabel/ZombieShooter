#include "Zombie.h"

Zombie::Zombie(int _arenaX, int _arenaY, int _health) : Character(_health)
{
	LoadAndSetTextureFromFile("graphics/zombie1.png");
	SetSpriteOrigin({ m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2});
	SetPosition({-m_Sprite.getLocalBounds().width, -m_Sprite.getLocalBounds().height});
	m_ArenaSize = { _arenaX, _arenaY };
	m_Speed = 50;
}

void Zombie::Spawn(int _startX, int _startY)
{
	SetPosition({_startX, _startY});
}

void Zombie::Update(Vector2f _coords, float _elapsedTime)
{
	Vector2f rawInput = {0, 0};
	Vector2f normalizedDirection = rawInput;

	rawInput.x = _coords.x - m_CharPosition.x;
	rawInput.y = _coords.y - m_CharPosition.y;

	//Normalize Input vector so that the magnitude is always 1
	if (abs(rawInput.x) > 0 || abs(rawInput.y) > 0)
	{
		float m = sqrt((rawInput.x * rawInput.x) + (rawInput.y * rawInput.y));
		normalizedDirection.x = rawInput.x / m;
		normalizedDirection.y = rawInput.y / m;

		if (rawInput.x > 0) m_SpriteHDirection = 1;
		else if (rawInput.x < 0) m_SpriteHDirection = -1;
	}

	Vector2f desiredDirection = {m_CharPosition.x, m_CharPosition.y};
	desiredDirection += {normalizedDirection.x * m_Speed * _elapsedTime, normalizedDirection.y * m_Speed * _elapsedTime};


	SetPosition(desiredDirection);

	//Move the player and set sprite scale (which way its facing)
	m_Sprite.setScale(m_SpriteHDirection, 1);
	
	ValidateCollision(); //Check collision
}