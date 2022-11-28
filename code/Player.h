#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	Texture playerTexture;
	Sprite playerSprite;
	const float speed = 100;
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	Vector2f playerPosition;
public:
	Player();
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
