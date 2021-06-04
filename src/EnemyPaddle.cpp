#include "EnemyPaddle.h"

EnemyPaddle::EnemyPaddle(sf::Vector2f pos, float width, float height)
	:
	Paddle(pos, width, height),
	rnd(rd()),
	dist(-50, 50)
{
	ballColllisionDir = -1.0f;
}

void EnemyPaddle::MoveTowards(float yDest)
{
	const float posYCenter = pos.y + height / 2.0f;
	if (yDest < posYCenter)
	{
		dirY = -1.0f;
	}
	else if (yDest > posYCenter)
	{
		dirY = 1.0f;
	}
	// 50.0f is a magic number :(
	if(yDest >= posYCenter - 50.0f && yDest <= posYCenter + 50.0f)
	{
		dirY = 0.0f;
	}
}

void EnemyPaddle::Update(const float& dt, const Ball& ball, const sf::FloatRect& walls)
{	
	timer += dt;
	
	if (timer >= movementDelay)
	{
		const float nextBallPosY = CalculateYGoal(ball.GetPosition(), ball.GetDirection());
		
		MoveTowards(nextBallPosY);
		timer = 0.0f;
	}
	
	
	pos.y += dirY * speed * dt;
	pos.y = ClampScreen(pos.y, walls);
	paddle.setPosition(pos);
}

float EnemyPaddle::CalculateYGoal(const sf::Vector2f& ballPos, const sf::Vector2f& ballDir)
{
	// Calculates intersetion of the linear equation which ball follows, then adds a little error to more human behavior.
	const float m = ballDir.y / ballDir.x;
	const float n = -m * ballPos.x + ballPos.y;


	return m * pos.x + n + (float)dist(rnd);
}


