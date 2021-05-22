#pragma once

#include "PlayerPaddle.h"
#include "EnemyPaddle.h"

class Game
{
public:
	Game();

	void UpdateEvents();
	void Update();
	void Render();

	bool IsRunning() const;

	// User functions here
	void PlaySound(sf::Sound& sound, std::string fileName);
	//
private:
	sf::RenderWindow window;
	sf::Event e;

	bool running = true;

	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;

	// User variables here
	/* Logic */
	bool gameStarted = false;
	/* Time */
	sf::Clock clock;
	/* Entities*/
	sf::FloatRect walls;
	Ball ball;
	PlayerPaddle playerPaddle;
	EnemyPaddle enemyPaddle;
	/* UI */
	sf::Font font;
	sf::Text startText;
	sf::Text playerScoreText;
	sf::Text enemyScoreText;
	/* Score */
	int playerScore = 0;
	int enemyScore = 0;
	/* Sound */
	sf::SoundBuffer soundBuffer;
	sf::Sound hitSound;
	sf::Sound pointSound;
	//
};