#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

class Player : public Character
{
private:

	const int HIT_INVINCIBILITY_TIME_MS = 200;

	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	Vector2f playerInputVector = {0, 0};
	Time m_LastHit;
	void DetermineMoveDirection();
	
public:
	Player(int, int, int, std::string);
	void Spawn(int, int) override;
	void Heal(int);
	bool Hit(Time, int);
	Time GetLastHitTime();
	int GetHealth();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void StopLeft();
	void StopRight();
	void StopUp();
	void StopDown();
	bool Update(float elapsedTime);
};

#endif