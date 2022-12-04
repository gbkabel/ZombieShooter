#ifndef PLAYER_H
#define PLAYER_H
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
	void ValidateCollision();
	void DetermineMoveDirection();
	
public:
	Vector2i arenaSize;
	Player();
	void Spawn(int, int);
	void Heal(int);
	bool Hit(Time, int);
	Time GetLastHitTime();
	virtual Sprite GetSprite();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void StopLeft();
	void StopRight();
	void StopUp();
	void StopDown();
	FloatRect GetPosition();
	Vector2f GetCenter();
	void Update(float elapsedTime, Vector2i mousePosition);
};

#endif