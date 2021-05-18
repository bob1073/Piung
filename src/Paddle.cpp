#include "Paddle.h"

Paddle::Paddle(sf::Vector2f pos, float width, float height)
	:
	pos(pos)
{
	paddle.setPosition(pos);
	paddle.setFillColor(sf::Color::Yellow);
	paddle.setSize(sf::Vector2f(width, height));
}

void Paddle::Render(sf::RenderTarget& target)
{
	target.draw(paddle);
}

void Paddle::Update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pos.y -= speed * dt;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pos.y += speed * dt;
	}
	paddle.setPosition(pos);
}

void Paddle::DoBallCollision(Ball& ball) const
{
	sf::FloatRect paddleRect = paddle.getGlobalBounds();
	sf::FloatRect ballRect = ball.GetRect();

	const float ballBottom = ballRect.top + ballRect.height;
	const float paddleRight = paddleRect.left + paddleRect.width;
	const float paddleBottom = paddleRect.top + paddleRect.height;

	// If ball is "near" the paddle
	if (ballRect.top >= paddleRect.top && ballBottom <= paddleBottom)
	{
		if (ballRect.left <= paddleRight)
		{
			ball.ReboundX();
		}
	}
}

void Paddle::DoWallCollision(const sf::FloatRect& walls)
{
	const float paddlePosY = paddle.getPosition().y;
	const float wallsBottom = walls.top + walls.height;
	const float paddleHeight = paddle.getGlobalBounds().height;

	if (paddlePosY <= walls.top)
	{
		pos.y = walls.top;
	}
	else if (paddlePosY >= wallsBottom - paddleHeight)
	{
		pos.y = wallsBottom - paddleHeight;
	}
	paddle.setPosition(pos);
}
