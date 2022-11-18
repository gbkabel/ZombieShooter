#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	float speed;
	int health;
	Vector2f mousePosition;
	Sprite playerSprite;
	Texture playerTexture;
	Vector2f resolution;
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
public:
	Player();
	void spawn(Vector2f resolution);
	FloatRect getPosition();
	Vector2f getCenter();
	int getHealth();
	Sprite getSprite();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	void update(float elapsedTime, Vector2i mousePosition);
};