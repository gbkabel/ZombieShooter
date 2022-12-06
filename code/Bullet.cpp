#include "Bullet.h"

// The constructor
Bullet::Bullet()
{
	m_MainTexture.loadFromFile("graphics/bullet1.png");
	m_Sprite.setTexture(m_MainTexture);
}

void Bullet::shoot(float startX, float startY,
	float targetX, float targetY)
{
	// Keep track of the bullet
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;

	Vector2f rawDirection = {targetX - startX, targetY - startY};

	

	//Normalize Input vector so that the magnitude is always 1
	if (abs(rawDirection.x) > 0 || abs(rawDirection.y) > 0)
	{
		float m = sqrt((rawDirection.x * rawDirection.x) + (rawDirection.y * rawDirection.y));
		m_DirectionOfTravel = { rawDirection.x / m, rawDirection.y / m};
	}


	// Finally, assign the results to the
	// member variables
	m_XTarget = targetX;
	m_YTarget = targetY;

	// Set a max range of 1000 pixels
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;
	
	// Position the bullet ready to be drawn
	m_Sprite.setPosition(m_Position);
}

void Bullet::stop()
{
	m_InFlight = false;
}

bool Bullet::isInFlight()
{
	return m_InFlight;
}

FloatRect Bullet::getPosition()
{
	return m_Sprite.getGlobalBounds();
}


void Bullet::update(float elapsedTime)
{
	// Update the bullet position variables
	m_Position.x += m_DirectionOfTravel.x * BULLET_SPEED * elapsedTime;
	m_Position.y += m_DirectionOfTravel.y * BULLET_SPEED * elapsedTime;

	// Move the bullet
	m_Sprite.setPosition(m_Position);

	// Has the bullet gone out of range?
	if (m_Position.x < m_MinX || m_Position.x > m_MaxX ||
		m_Position.y < m_MinY || m_Position.y > m_MaxY)
	{
		m_InFlight = false;
	}

}

Sprite Bullet::GetSprite() const
{
	return m_Sprite;
}
