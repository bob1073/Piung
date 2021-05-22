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
	// Direction in Y axis of movement, used to follow the ball
	float dirY = 1.0f;
};

