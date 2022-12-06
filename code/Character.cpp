#include "Character.h"

Character::Character(int _arenaX, int _arenaY, int _health, std::string _path = "")
{
    this->m_MaxHealth = _health;
    this->m_Health = _health;

	m_ArenaSize = { _arenaX, _arenaY };

	LoadAndSetTextureFromFile(_path);
	SetSpriteOrigin({ m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2});
	SetPosition({-m_Sprite.getLocalBounds().width, -m_Sprite.getLocalBounds().height});
}

void Character::LoadAndSetTextureFromFile(std::string _path)
{
    this->m_MainTexture.loadFromFile(_path);
    this->m_Sprite.setTexture(m_MainTexture);
}

void Character::SetSpriteOrigin(Vector2f _coords)
{
    this->m_Sprite.setOrigin(_coords.x, _coords.y);
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

int Character::GetSpriteHorizontalDirection() const
{
    return m_SpriteHDirection;
}

Sprite Character::GetSprite() const
{
    return this->m_Sprite;
}

FloatRect Character::GetSpriteGlobalBounds() const
{
    return this->m_Sprite.getGlobalBounds();
}

Vector2f Character::GetCharPosition() const
{
    return this->m_CharPosition;
}

void Character::SetPosition(Vector2f _position)
{
    this->m_CharPosition = _position;
    this->m_Sprite.setPosition(m_CharPosition.x, m_CharPosition.y);
}

void Character::SetSpeed(float _newSpeed)
{
	m_Speed = _newSpeed;
}