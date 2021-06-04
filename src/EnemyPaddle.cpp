#include "EnemyPaddle.h"

EnemyPaddle::EnemyPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height)
{
	ballColllisionDir = -1.0f;
}

void EnemyPaddle::Update(const float& dt, const Ball& ball, const sf::FloatRect& walls)
{	
	const float posYCenter = pos.y + height / 2.0f;
	
	timer += dt;
	
	if (timer >= movementDelay)
	{
		const float ballPosY = ball.GetPosition().y;
		if (ballPosY > posYCenter)
		{
			dirY = 1.0f;
		}
		else
		{
			dirY = -1.0f;
		}
		timer = 0.0f;

		if (ballPosY >= pos.y && ballPosY <= pos.y + height)
		{
			speed = 0.0f;
		}
		else
		{
			speed = 400.0f;
		}
	}
	
	
	pos.y += dirY * speed * dt;
	pos.y = ClampScreen(pos.y, walls);
	paddle.setPosition(pos);
}


