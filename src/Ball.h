#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class WallCollisions
{
	NONE, 
	TOPBOTTOMWALL,
	PLAYERSIDE,
	ENEMYSIDE
};

class Ball
{
public:
	// Constructor
	Ball(const sf::Vector2f& startPos, const sf::Vector2f& startDir);

	// Render
	void Render(sf::RenderTarget& target);

	// Movement
	void Update(const float& dt);
	void ReboundX();
	void ReboundY();
	void Rebound(sf::Vector2f dir);
	void IncrementSpeed();
	void Respawn();

	// Collision
	WallCollisions DoWallCollisions(const sf::FloatRect& walls);

	// Getters
	sf::FloatRect GetRect() const;
	const sf::Vector2f GetPosition() const;
	const sf::Vector2f GetDirection() const;

private:
	// Shape
	sf::CircleShape ball;
	static constexpr float radius = 7.0f;
	sf::Color color;

	// Movement
	static constexpr float speedRate = 20.0f;
	static constexpr float startSpeed = 500.0f;
	const sf::Vector2f startPos;
	sf::Vector2f startDir;
	sf::Vector2f pos;
	sf::Vector2f dir;
	int startDirX = 1;
	float speed;

	// Functions
	void NormalizeDir();
};

