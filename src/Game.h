#pragma once

#include "GameState.h"
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

private:
	sf::RenderWindow window;
	sf::Event e;
	sf::Clock clock;
	bool running = true;

	std::stack<std::unique_ptr<State>> states;

	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;
};