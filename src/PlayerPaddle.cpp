#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height)
{
}

void PlayerPaddle::Update(const float& dt, const Ball& ball, const sf::FloatRect& walls)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pos.y -= speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pos.y += speed * dt;
	}

	pos.y = ClampScreen(pos.y, walls);

	paddle.setPosition(pos);
}

void PlayerPaddle::DoBallCollision(Ball& ball) const
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
		if (ballRect.left <= paddleRight && ballRect.left > paddleRect.left)
		{
			ball.ReboundX();
		}
	}
	else if (ballRect.left <= paddleRight && ballRight >= paddleRect.left)
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
