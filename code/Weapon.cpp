#include "Weapon.h"


Weapon::Weapon()
{
    m_Texture.loadFromFile("graphics/tommygun1.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width/2, m_Sprite.getGlobalBounds().height/2);
}

void Weapon::Update(Vector2f _playerCoords, Vector2f _mouseCoords)
{
    Vector2f rawDirection = {_mouseCoords.x - _playerCoords.x, _mouseCoords.y - _playerCoords.y};
    float angle = atan2(rawDirection.y, rawDirection.x);
    if (angle >= 1.5 || angle <= -1.5) m_Sprite.setScale(1, -1);
    else m_Sprite.setScale(1,1);
    m_Sprite.setPosition(_playerCoords.x, _playerCoords.y);
    m_Sprite.setRotation(angle * 180.0 / M_PI);
}

Sprite Weapon::GetSprite() const
{
    return m_Sprite;
}
