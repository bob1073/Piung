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
