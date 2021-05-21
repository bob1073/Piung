#include "Game.h"
#include <iostream>

Game::Game()
    :
    window(sf::VideoMode(screenWidth, screenHeight), "Piung!", sf::Style::Close | sf::Style::Titlebar),
    walls(0.0f, 0.0f, screenWidth, screenHeight),
    ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 1.0f, 0.0f }),
    playerPaddle(sf::Vector2f(50.0f, screenHeight / 3.0f), 25.0f, 125.0f),
    enemyPaddle(sf::Vector2f(750.0f, screenHeight / 3.0f), 25.0f, 125.0f)
{
    //window.setVerticalSyncEnabled(true);

    // Font loading
    if (!font.loadFromFile("Resources/Fonts/bit5x3.ttf"))
    {
        std::cout << "Error al cargar la fuente" << std::endl;
    }  

    // UI
    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(20);
    playerScoreText.setPosition(screenWidth / 5.0f, screenHeight / 10.0f);
    playerScoreText.setString(std::to_string(playerScore));
    enemyScoreText.setFont(font);
    enemyScoreText.setCharacterSize(20);
    enemyScoreText.setPosition(4.0f * screenWidth / 5.0f, screenHeight / 10.0f);
    enemyScoreText.setString(std::to_string(enemyScore));
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

    const WallCollisions wallCollision = ball.DoWallCollisions(walls);

    if (wallCollision == WallCollisions::PLAYERSIDE)
    {
        ball.Respawn();
        ++enemyScore;
        enemyScoreText.setString(std::to_string(enemyScore));
        
    }
    else if (wallCollision == WallCollisions::ENEMYSIDE)
    {
        ball.Respawn();
        ++playerScore;
        playerScoreText.setString(std::to_string(playerScore));
    }


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
    window.draw(playerScoreText);
    window.draw(enemyScoreText);
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}
