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
	virtual void DoBallCollision(Ball& ball) const = 0;

protected:
	// Shape
	sf::RectangleShape paddle;
	const float width;
	const float height;

	// Movement
	sf::Vector2f pos;
	static constexpr float speed = 500.0f;

	// Keep paddle inside the walls
	float ClampScreen(float y, const sf::FloatRect& walls);
};

