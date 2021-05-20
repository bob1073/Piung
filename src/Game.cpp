#include "Game.h"
#include <iostream>

Game::Game()
    :
    window(sf::VideoMode(screenWidth, screenHeight), "Piung!", sf::Style::Close | sf::Style::Titlebar),
    walls(0.0f, 0.0f, screenWidth, screenHeight),
    ball(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1.0f, 1.0f)),
    playerPaddle(sf::Vector2f(50.0f, screenHeight / 3.0f), 25.0f, 125.0f),
    enemyPaddle(sf::Vector2f(750.0f, screenHeight / 3.0f), 25.0f, 125.0f)
{
    //window.setVerticalSyncEnabled(true);
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

    playerPaddle.Update(dt, ball, walls);
    playerPaddle.DoBallCollision(ball);

    enemyPaddle.Update(dt, ball, walls);
    enemyPaddle.DoBallCollision(ball);
}

void Game::Render()
{
    window.clear();
    // Render things here
    ball.Render(window);
    playerPaddle.Render(window);
    enemyPaddle.Render(window);
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}
