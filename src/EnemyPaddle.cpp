#include "EnemyPaddle.h"

EnemyPaddle::EnemyPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height)
{
	ballColllisionDir = -1.0f;
}

void EnemyPaddle::Update(const float& dt, const Ball& ball, const sf::FloatRect& walls)
{	
	//const float posY = ball.GetPosition().y - height / 2.0f;
	const float posYCenter = pos.y + height / 2.0f;

	if (ball.GetPosition().y > posYCenter)
	{
		dirY = 1.0f;
	}
	else
	{
		dirY = -1.0f;
	}
	
	pos.y += dirY * speed * dt;
	pos.y = ClampScreen(pos.y, walls);
	paddle.setPosition(pos);
}


