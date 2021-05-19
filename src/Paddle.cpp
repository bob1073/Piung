#include "Paddle.h"
#include <iostream>

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



bool Paddle::DoWallCollision(const sf::FloatRect& walls)
{
	const float paddlePosY = paddle.getPosition().y;
	const float wallsBottom = walls.top + walls.height;
	const float paddleHeight = paddle.getGlobalBounds().height;

	if (paddlePosY <= walls.top)
	{
		pos.y = walls.top;
		return true;
	}
	else if (paddlePosY >= wallsBottom - paddleHeight)
	{
		pos.y = wallsBottom - paddleHeight;
		return true;
	}
	paddle.setPosition(pos);

	return false;
}
