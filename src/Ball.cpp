#include "Ball.h"

Ball::Ball(const sf::Vector2f& startPos, const sf::Vector2f& startDir)
	:
	startPos(startPos),
	startDir(startDir),
	pos(startPos),
	dir(startDir),
	speed(startSpeed)
{
	NormalizeDir();

	ball.setPosition(pos);
	ball.setRadius(radius);
	ball.setFillColor(sf::Color::White);
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

void Ball::Rebound(sf::Vector2f dir)
{
	this->dir = dir;

	NormalizeDir();
}

void Ball::IncrementSpeed()
{
	speed += speedRate;
}

void Ball::Respawn()
{
	startDirX *= -1;
	pos = startPos;
	dir.x = startDirX * startDir.x;
	dir.y = startDir.y;
	speed = startSpeed;
}

WallCollisions Ball::DoWallCollisions(const sf::FloatRect& walls)
{
	const float right = walls.left + walls.width;
	const float bottom = walls.top + walls.height;
	const float margin = 200.0f;

	if(pos.y <= walls.top || pos.y + 2.0f * radius >= bottom)
	{
		ReboundY();
		return WallCollisions::TOPBOTTOMWALL;
	}

	if (pos.x < walls.left - margin)
	{
		return WallCollisions::PLAYERSIDE;
	}
	else if (pos.x > right + margin)
	{
		return WallCollisions::ENEMYSIDE;
	}

	return WallCollisions::NONE;
}

sf::FloatRect Ball::GetRect() const
{
	return ball.getGlobalBounds();
}

const sf::Vector2f Ball::GetPosition() const
{
	return pos;
}

const sf::Vector2f Ball::GetDirection() const
{
	return dir;
}

void Ball::NormalizeDir()
{
	const float norm = std::sqrt(dir.x * dir.x + dir.y * dir.y);

	dir /= norm;
}