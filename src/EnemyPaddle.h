#pragma once

#include "Paddle.h"

class EnemyPaddle :
	public Paddle
{
public:
	// Constructor
	EnemyPaddle(sf::Vector2f pos, float width, float height);

	// Movement
	virtual void Update(const float& dt, const Ball& ball, const sf::FloatRect& walls);

private:
	int dirY = 1.0f;
};

