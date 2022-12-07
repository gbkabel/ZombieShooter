#pragma once
#include "SFML/Graphics.hpp"

#include <cmath>
#include <iostream>

using namespace sf;

class Weapon
{
public:
    Weapon();
    void Update(Vector2f, Vector2f);
    Sprite GetSprite() const;
private:
    Vector2f m_WorldPosition;
    Vector2f m_WorldDirection;
    Texture m_Texture;
    Sprite m_Sprite;
};
