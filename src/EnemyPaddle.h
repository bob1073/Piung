#pragma once

#include "Paddle.h"

class EnemyPaddle :
	public Paddle
{
public:
	EnemyPaddle(sf::Vector2f pos, float width, float height);

	virtual void Update(const float& dt, const Ball& ball);
	virtual void DoBallCollision(Ball& ball) const;

private:
	bool goingDown = true;
};

