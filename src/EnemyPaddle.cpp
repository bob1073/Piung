#include "EnemyPaddle.h"

EnemyPaddle::EnemyPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height)
{
	ballColllisionDir = -1.0f;
}

void EnemyPaddle::Update(const float& dt, const Ball& ball, const sf::FloatRect& walls)
{	
	const float posY = ball.GetPosition().y - height / 2.0f;
	pos.y = ClampScreen(posY, walls);
	paddle.setPosition(pos);
}


