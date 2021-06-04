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
	virtual void Update(const float& dt, const Ball& ball, const sf::FloatRect& walls) = 0;

	// Collision
	bool DoBallCollision(Ball& ball) const;

protected:
	// Shape
	sf::RectangleShape paddle;
	const float width;
	const float height;

	// Movement
	sf::Vector2f pos;
	float ballColllisionDir = 1.0f;
	float speed = 400.0f;

	// Keep paddle inside the walls
	float ClampScreen(float y, const sf::FloatRect& walls);
};

