#pragma once

#include "PlayerPaddle.h"
#include "EnemyPaddle.h"

class Game
{
public:
	Game();
	~Game();

	void UpdateEvents();
	void Update();
	void Render();

	bool IsRunning() const;
	// User functions here

	//
private:
	sf::RenderWindow window;
	sf::Event e;

	bool running = true;

	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;

	// User variables here
	/* Time */
	sf::Clock clock;
	/* Entities*/
	sf::FloatRect walls;
	Ball ball;
	PlayerPaddle playerPaddle;
	EnemyPaddle enemyPaddle;
	/* UI */
	sf::Font font;
	sf::Text playerScoreText;
	sf::Text enemyScoreText;
	/* Score */
	int playerScore = 0;
	int enemyScore = 0;

	//
};