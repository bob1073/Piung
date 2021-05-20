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