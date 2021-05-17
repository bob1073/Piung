#include "Ball.h"

Ball::Ball(sf::Vector2f pos, sf::Vector2f dir)
	:
	pos(pos),
	dir(dir)
{
	speed = 500.0f;
	ball.setPosition(pos);
	ball.setOrigin(radius, radius); // Sets origin at center of circle
	ball.setRadius(radius);
	ball.setFillColor(sf::Color::Magenta);
}

void Ball::Render(sf::RenderTarget& target)
{
	target.draw(ball);
}

void Ball::Update(const float& dt)
{
	pos += dir * speed * dt;
	ball.setPosition(pos);
}

void Ball::ReboundX()
{
	dir.x = -dir.x;
}

void Ball::ReboundY()
{
	dir.y = -dir.y;
}

void Ball::DoWallCollisions(const sf::FloatRect& walls)
{
	const float right = walls.left + walls.width;
	const float bottom = walls.top + walls.height;

	if (pos.x <= walls.left || pos.x + radius >= right)
	{
		ReboundX();
	}
	else if(pos.y <= walls.top || pos.y + radius >= bottom)
	{
		ReboundY();
	}
}