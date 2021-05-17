#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Ball
{
public:
	// Constructor
	Ball(sf::Vector2f pos, sf::Vector2f dir);

	// Render
	void Render(sf::RenderTarget& target);

	// Movement
	void Update(const float& dt);
	void ReboundX();
	void ReboundY();

	// Collision
	void DoWallCollisions(const sf::FloatRect& walls);

private:
	// Shape
	sf::CircleShape ball;
	static constexpr float radius = 7.0f;
	sf::Color color;

	// Movement
	sf::Vector2f pos;
	sf::Vector2f dir;
	float speed;
};

