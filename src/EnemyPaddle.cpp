#include "EnemyPaddle.h"

EnemyPaddle::EnemyPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height)
{
}

void EnemyPaddle::Update(const float& dt, const Ball& ball, const sf::FloatRect& walls)
{	
	pos.y = ClampScreen(ball.GetPosition().y - paddle.getGlobalBounds().height / 2.0f, walls);
	paddle.setPosition(pos);
}

void EnemyPaddle::DoBallCollision(Ball& ball) const
{
	sf::FloatRect paddleRect = paddle.getGlobalBounds();
	sf::FloatRect ballRect = ball.GetRect();

	const float ballBottom = ballRect.top + ballRect.height;
	const float ballRight = ballRect.left + ballRect.width;
	const float paddleBottom = pos.y + height;
	const float paddleRight = pos.x + width;

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


