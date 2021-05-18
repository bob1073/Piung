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
	void Update(const float& dt);

	// Collision
	void DoBallCollision(Ball& ball) const;
	void DoWallCollision(const sf::FloatRect& walls);

private:
	// Shape
	sf::RectangleShape paddle;

	// Movement
	sf::Vector2f pos;
	static constexpr float speed = 500.0f;
};

