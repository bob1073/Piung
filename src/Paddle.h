#pragma once

#include "Ball.h"

class Paddle
{
public:
	// Constructor
	Paddle(sf::Vector2f pos, float width, float height);

	// Render
	void Render(sf::RenderTarget& target);

	// Movement
	virtual void Update(const float& dt, const Ball& ball) = 0;

	// Collision
	virtual void DoBallCollision(Ball& ball) const = 0;
	bool DoWallCollision(const sf::FloatRect& walls);

protected:
	// Shape
	sf::RectangleShape paddle;

	// Movement
	sf::Vector2f pos;
	static constexpr float speed = 500.0f;
};

