#pragma once

#include <SFML/Graphics.hpp>
#include <stack>

class State
{
public:
	// Constructor & Destructor
	State(std::stack<std::unique_ptr<State>>& states);
	virtual ~State() = default;

	// Core functions
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderTarget& target) = 0;
	virtual void EndState();

	// Getters
	bool IsRunning() const { return running; }

protected:
	std::stack<std::unique_ptr<State>>& states;
	bool running;
};

