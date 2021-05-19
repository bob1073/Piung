#include "Ball.h"

Ball::Ball(sf::Vector2f pos, sf::Vector2f dir)
	:
	pos(pos),
	dir(dir)
{
	speed = 500.0f;
	NormalizeDir();

	ball.setPosition(pos);
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

	if(pos.y <= walls.top || pos.y + 2.0f*radius >= bottom)
	{
		ReboundY();
	}
}

sf::FloatRect Ball::GetRect() const
{
	return ball.getGlobalBounds();
}

const sf::Vector2f Ball::GetPosition() const
{
	return pos;
}

void Ball::NormalizeDir()
{
	const float norm = std::sqrt(dir.x * dir.x + dir.y * dir.y);

	dir /= norm;
}
