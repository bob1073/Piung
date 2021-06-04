#pragma once

#include "Paddle.h"
#include <random>

class EnemyPaddle :
	public Paddle
{
public:
	// Constructor
	EnemyPaddle(sf::Vector2f pos, float width, float height);

	// Movement
	void MoveTowards(float yDest);
	virtual void Update(const float& dt, const Ball& ball, const sf::FloatRect& walls);

private:
	// Direction in Y axis of movement, used to follow the ball
	static constexpr float movementDelay = 0.25f;
	float dirY = 1.0f;
	float timer = 0.0f;
	std::random_device rd;
	std::mt19937 rnd;
	std::uniform_real_distribution<> dist;

	// Private methods
	float CalculateYGoal(const sf::Vector2f& ballPos, const sf::Vector2f& ballDir);
};

