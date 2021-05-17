#include "Game.h"
#include <iostream>

Game::Game()
	: 
    window(sf::VideoMode(screenWidth, screenHeight), "Piung!", sf::Style::Close | sf::Style::Titlebar),
    walls(0.0f, 0.0f, screenWidth, screenHeight),
    ball(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1.0f, 1.0f))
{
    window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
}

void Game::UpdateEvents()
{
    while (window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            running = false;
    }
}

void Game::Update()
{
    const float dt = clock.restart().asSeconds();

    ball.Update(dt);
    ball.DoWallCollisions(walls);
}

void Game::Render()
{
    window.clear();
    // Render things here
    ball.Render(window);
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}
