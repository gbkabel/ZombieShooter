#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

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
    void SetSpeed(float);
    void SetHealth(int);

public:
    Character(int, int, std::string);
    int GetHealth();
	void ValidateCollision();
    void LoadAndSetTextureFromFile(std::string);
    void SetSpriteOrigin(Vector2f);
	virtual void Spawn(int, int) = 0;
    Vector2f GetCharPosition() const;
    int GetSpriteHorizontalDirection() const;
    Sprite GetSprite() const;
    FloatRect GetSpriteGlobalBounds() const;
};