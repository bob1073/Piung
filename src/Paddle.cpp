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

bool Paddle::DoBallCollision(Ball& ball) const
{
	sf::FloatRect paddleRect = paddle.getGlobalBounds();
	sf::FloatRect ballRect = ball.GetRect();

	// Collision happens
	if (paddleRect.intersects(ballRect))
	{
		const float distFromCenter = (ballRect.top + ballRect.height / 2.0f) - (pos.y + height / 2.0f);
		const float ratio = distFromCenter / (height / 2.0f);

		ball.Rebound({ ballColllisionDir, ratio });
		ball.IncrementSpeed();

		//Original way of colliding with the ball. I'll let there cause why not :D


		/*// Top collision
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

		return true;
	}

	return false;
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