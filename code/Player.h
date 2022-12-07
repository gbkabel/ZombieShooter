#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : public Character
{
private:
	const int HIT_INVINCIBILITY_TIME_MS = 200;
	const int STARTING_HEALTH = 100;
	const int STARTING_SPEED = 100;
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
	Time GetLastHitTime() const;
	int GetHealth() const;
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void StopLeft();
	void StopRight();
	void StopUp();
	void StopDown();
	void Update(float elapsedTime);
};

#endif
