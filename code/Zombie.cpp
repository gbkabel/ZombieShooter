#include "Zombie.h"

Zombie::Zombie(int _arenaX, int _arenaY, int _health, string _path) : Character(_arenaX, _arenaY, _path)
{
	SetHealth(_health);
	m_HurtBuffer.loadFromFile("sounds/8bit-ZombieHit1.wav");
	m_HurtSound.setBuffer(m_HurtBuffer);
}

void Zombie::Spawn(int _startX, int _startY)
{
	SetPosition({(float)_startX, (float)_startY});
	m_IsAlive = true;
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
	desiredDirection.x += normalizedDirection.x * m_Speed * _elapsedTime;
	desiredDirection.y += normalizedDirection.y * m_Speed * _elapsedTime;

	SetPosition(desiredDirection);

	//Move the Zombie and set sprite scale (which way its facing)
	m_Sprite.setScale(m_SpriteHDirection, 1);
	
	//ValidateCollision(); //Check collision
}

int Zombie::GetKillValue() const
{
	return m_KillScoreValue;
}

bool Zombie::IsAlive() const
{
	return m_IsAlive;
}

bool Zombie::Hit(int _damage)
{
	m_Health -= _damage;
	m_HurtSound.play();

	if (m_Health <= 0)
	{
		m_IsAlive = false;
		m_MainTexture.loadFromFile("graphics/bloodPool1.png");
		m_Sprite.setTexture(m_MainTexture);
	}
	return !m_IsAlive;
}

int Zombie::GetDamageValue() const
{
	return m_Damage;
}

Zombie::~Zombie()
{
}
