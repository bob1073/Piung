#include "Paddle.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f pos, float width, float height)
	:
	pos(pos),
	width(width),
	height(height)
{
	paddle.setPosition(pos);
	paddle.setFillColor(sf::Color::Yellow);
	paddle.setSize(sf::Vector2f(width, height));
}

void Paddle::Render(sf::RenderTarget& target)
{
	target.draw(paddle);
}

void Paddle::DoBallCollision(Ball& ball) const
{
	sf::FloatRect paddleRect = paddle.getGlobalBounds();
	sf::FloatRect ballRect = ball.GetRect();

	// Collision happens
	if (paddleRect.intersects(ballRect))
	{
		ball.IncrementSpeed();

		// Top collision
		if (ballRect.top <= pos.y + height / 3.0f)
		{
			ball.Rebound({ ballColllisionDir, -0.75f });
		}
		// Medium collision
		if (ballRect.top > pos.y + height / 3.0f && ballRect.top < pos.y + 2.0f * height / 3.0f)
		{
			ball.Rebound({ ballColllisionDir, 0.0f });
		}
		// Bottom collision
		if (ballRect.top >= pos.y + 2.0f * height / 3.0f)
		{
			ball.Rebound({ ballColllisionDir, 0.75f });
		}
	}
}

float Paddle::ClampScreen(float y, const sf::FloatRect& walls)
{
	const float wallsBottom = walls.top + walls.height;
	if (y <= walls.top)
	{
		return walls.top;
	}
	else if (y + height > wallsBottom)
	{
		return wallsBottom - height;
	}
	else
	{
		return y;
	}
}