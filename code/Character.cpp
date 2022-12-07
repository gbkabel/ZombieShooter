#include "Character.h"

// Private Functions
void Character::SetPosition(Vector2f _position)
{
    this->m_CharPosition = _position;
    this->m_Sprite.setPosition(m_CharPosition.x, m_CharPosition.y);
}

void Character::SetHealth(int _amount)
{
	this->m_Health = _amount;
	this->m_MaxHealth = _amount;
}

void Character::SetSpeed(float _newSpeed)
{
	this->m_Speed = _newSpeed;
}

// Public Functions
Character::Character(int _arenaX, int _arenaY, string _path = "")
{
	this->m_ArenaSize = { _arenaX, _arenaY };

	LoadAndSetTextureFromFile(_path);
	SetSpriteOrigin({ m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2});
	SetPosition({-m_Sprite.getLocalBounds().width, -m_Sprite.getLocalBounds().height});
}

void Character::LoadAndSetTextureFromFile(string _path)
{
    this->m_MainTexture.loadFromFile(_path);
    this->m_Sprite.setTexture(m_MainTexture);
}

void Character::SetSpriteOrigin(Vector2f _coords)
{
    this->m_Sprite.setOrigin(_coords.x, _coords.y);
}

Vector2f Character::GetCharPosition() const
{
    return this->m_CharPosition;
}

Sprite Character::GetSprite() const
{
    return this->m_Sprite;
}

int Character::GetSpriteHorizontalDirection() const
{
    return this->m_SpriteHDirection;
}

FloatRect Character::GetSpriteGlobalBounds() const
{
    return this->m_Sprite.getGlobalBounds();
}

void Character::ValidateCollision()
{
    // Keep the player in the arena
	FloatRect playerBounds = m_Sprite.getLocalBounds();

	if (m_CharPosition.x > m_ArenaSize.x - (playerBounds.width/2))
	{
		this->SetPosition({m_ArenaSize.x - (playerBounds.width/2), m_CharPosition.y});
	}

	if (m_CharPosition.x < (playerBounds.width/2))
	{
		this->SetPosition({playerBounds.width/2, m_CharPosition.y});
	}

	if (m_CharPosition.y > m_ArenaSize.y - (playerBounds.height/2))
	{
        this->SetPosition({m_CharPosition.x, m_ArenaSize.y - (playerBounds.height/2)});
	}

	if (m_CharPosition.y < (playerBounds.height/2))
	{
        this->SetPosition({m_CharPosition.x, playerBounds.height/2 });
	}
}

int Character::GetHealth() const
{
	return this->m_Health;
}
