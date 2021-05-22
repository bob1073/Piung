#include "Paddle.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f pos, float width, float height)
	:
	pos(pos),
	width(width),
	height(height)
{
	paddle.setPosition(pos);
	paddle.setFillColor(sf::Color::White);
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

		const float distFromCenter = (ballRect.top + ballRect.height / 2.0f) - (pos.y + height / 2.0f);
		const float ratio = distFromCenter / (height / 2.0f);

		ball.Rebound({ ballColllisionDir, ratio });
		/*
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
		*/
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