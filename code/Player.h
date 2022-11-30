#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

class Player
{
private:
	Texture playerTexture;
	Sprite playerSprite;
	const float speed = 100;
	const int HIT_INVINCIBILITY_TIME_MS = 200;
	int m_Health;
	int m_MaxHealth;
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	Vector2f playerPosition;
	Vector2f playerInputVector = {0, 0};
	Time m_LastHit;
	int spriteHDirection = 1;
	Vector2i arenaSize;
	void ValidateCollision();
	void DetermineMoveDirection();
public:
	Player(int, int);
	void Heal(int);
	bool Hit(Time, int);
	Time getLastHitTime();
	Sprite getSprite();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	FloatRect getPosition();
	void update(float elapsedTime, Vector2i mousePosition);
};
