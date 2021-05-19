#include "EnemyPaddle.h"

EnemyPaddle::EnemyPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height)
{
}

void EnemyPaddle::Update(const float& dt, const Ball& ball)
{
	/*if (goingDown)
	{
		pos.y += speed * dt;
		if (pos.y >= 400.0f)
		{
			goingDown = false;
		}
	}
	else
	{
		pos.y -= speed * dt;
		if (pos.y <= 50.0f)
		{
			goingDown = true;
		}
	}*/

	pos.y = ball.GetPosition().y - paddle.getGlobalBounds().height/ 2.0f;

	paddle.setPosition(pos);
}

void EnemyPaddle::DoBallCollision(Ball& ball) const
{
	sf::FloatRect paddleRect = paddle.getGlobalBounds();
	sf::FloatRect ballRect = ball.GetRect();

	const float ballBottom = ballRect.top + ballRect.height;
	const float ballRight = ballRect.left + ballRect.width;
	const float paddleBottom = paddleRect.top + paddleRect.height;
	const float paddleRight = paddleRect.left + paddleRect.width;

	// If ball is "near" the paddle
	if (ballRect.top >= paddleRect.top && ballBottom <= paddleBottom)
	{
		if (ballRight >= paddleRect.left && ballRight < paddleRight)
		{
			ball.ReboundX();
		}
	}
	else if (ballRect.left >= paddleRect.left && ballRight <= paddleRight)
	{
		if (ballBottom >= paddleRect.top && ballBottom <= paddleBottom)
		{
			ball.ReboundY();
		}
		else if (ballRect.top <= paddleBottom && ballRect.top >= paddleRect.top)
		{
			ball.ReboundY();
		}
	}
}
