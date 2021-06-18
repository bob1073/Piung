#pragma once

#include "State.h"
#include "Ball.h"
#include "PlayerPaddle.h"
#include "EnemyPaddle.h"

class GameState :
    public State
{
public:
    // Constructor
    GameState(std::stack<std::unique_ptr<State>>& states, int screenWidth, int screenHeight);

    // Core functions
    virtual void Update(float dt);
    virtual void Render(sf::RenderTarget& target);

	// Functions
	void PlaySound(sf::Sound& sound, std::string fileName);

private:
	/* Logic */
	bool gameStarted = false;

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
};

