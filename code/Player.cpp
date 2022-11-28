#include "Player.h"

Player::Player(int startX, int startY)
{
	playerTexture.loadFromFile("shooter1.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width/2, playerSprite.getLocalBounds().height/2);
	playerPosition = {(float) startX, (float) startY};
}

Sprite Player::getSprite()
{
	return playerSprite;
}

void Player::moveLeft()
{
	leftPressed = true;
}

void Player::moveRight()
{
	rightPressed = true;
}

void Player::moveUp()
{
	upPressed = true;
}

void Player::moveDown()
{
	downPressed = true;
}

void Player::stopLeft()
{
	leftPressed = false;
}

void Player::stopRight()
{
	rightPressed = false;
}

void Player::stopUp()
{
	upPressed = false;
}
void Player::stopDown()
{
	downPressed = false;
}

FloatRect Player::getPosition()
{
	return playerSprite.getGlobalBounds();
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	if (upPressed)
	{
		playerPosition.y -= speed * elapsedTime;
	}

	if (downPressed)
	{
		playerPosition.y += speed * elapsedTime;
	}

	if (rightPressed)
	{
		spriteHDirection = 1;
		playerPosition.x += speed * elapsedTime;
	}

	if (leftPressed)
	{
		spriteHDirection = -1;
		playerPosition.x -= speed * elapsedTime;
	}

	playerSprite.setScale(spriteHDirection, 1);
	playerSprite.setPosition(playerPosition);



	// Keep the player in the arena
	/*if (m_Position.x > m_Arena.width - m_TileSize)
	{
		m_Position.x = m_Arena.width - m_TileSize;
	}

	if (m_Position.x < m_Arena.left + m_TileSize)
	{
		m_Position.x = m_Arena.left + m_TileSize;
	}

	if (m_Position.y > m_Arena.height - m_TileSize)
	{
		m_Position.y = m_Arena.height - m_TileSize;
	}

	if (m_Position.y < m_Arena.top + m_TileSize)
	{
		m_Position.y = m_Arena.top + m_TileSize;
	}

	// Calculate the angle the player is facing
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
		mousePosition.x - m_Resolution.x / 2)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);
	*/
}
