#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

class Character
{
protected:
    Texture m_MainTexture;
	Sprite m_Sprite;
	Vector2f m_CharPosition;
	int m_SpriteHDirection = 1;
	Vector2i m_ArenaSize;
    int m_Health;
    int m_MaxHealth;
	float m_Speed = 100;
    void SetPosition(Vector2f);
    void SetHealth(int);
    void SetSpeed(float);
public:
    Character(int, int, string);
    void LoadAndSetTextureFromFile(string);
    void SetSpriteOrigin(Vector2f);
    virtual void Spawn(int, int) = 0;
    Vector2f GetCharPosition() const;
    Sprite GetSprite() const;
    int GetSpriteHorizontalDirection() const;
    FloatRect GetSpriteGlobalBounds() const;
    void ValidateCollision();
    int GetHealth() const;
};