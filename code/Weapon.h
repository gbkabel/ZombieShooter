#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Weapon
{
public:
    Weapon();
    void Update(Vector2f, Vector2f);
    Sprite GetSprite();
private:
    Vector2f m_WorldPosition;
    Vector2f m_WorldDirection;
    Texture m_Texture;
    Sprite m_Sprite;
};