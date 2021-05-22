#include "Game.h"
#include <iostream>

Game::Game()
    :
    window(sf::VideoMode(screenWidth, screenHeight), "Piung!", sf::Style::Close | sf::Style::Titlebar),
    walls(0.0f, 0.0f, screenWidth, screenHeight),
    ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 1.0f, 0.0f }),
    playerPaddle({ 50.0f, screenHeight / 3.0f }, 15.0f, 125.0f),
    enemyPaddle({ 750.0f, screenHeight / 3.0f }, 15.0f, 125.0f)
{
    //window.setVerticalSyncEnabled(true);

    // Font loading
    if (!font.loadFromFile("Resources/Fonts/bit5x3.ttf"))
    {
        std::cout << "Error al cargar la fuente" << std::endl;
    }  

    // Start text
    startText.setFont(font);
    startText.setCharacterSize(40);
    startText.setPosition(screenWidth / 4.0f, screenHeight / 3.0f);
    startText.setString("Press Enter to start");
    // Player Score Text
    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(40);
    playerScoreText.setPosition(screenWidth / 5.0f, screenHeight / 10.0f);
    playerScoreText.setString(std::to_string(playerScore));

    // Enemy Score Text
    enemyScoreText.setFont(font);
    enemyScoreText.setCharacterSize(40);
    enemyScoreText.setPosition(4.0f * screenWidth / 5.0f, screenHeight / 10.0f);
    enemyScoreText.setString(std::to_string(enemyScore));
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

    if (!gameStarted)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            gameStarted = true;
        }
    }
    else
    {
        ball.Update(dt);

        const WallCollisions wallCollision = ball.DoWallCollisions(walls);

        // Score for enemy
        if (wallCollision == WallCollisions::PLAYERSIDE)
        {
            ball.Respawn();
            ++enemyScore;
            enemyScoreText.setString(std::to_string(enemyScore));
            PlaySound(hitSound, "Resources/Audio/pointSound.ogg");
        }
        // Score for player
        else if (wallCollision == WallCollisions::ENEMYSIDE)
        {
            ball.Respawn();
            ++playerScore;
            playerScoreText.setString(std::to_string(playerScore));
            PlaySound(hitSound, "Resources/Audio/pointSound.ogg");
        }

        playerPaddle.Update(dt, ball, walls);
        enemyPaddle.Update(dt, ball, walls);

        if (playerPaddle.DoBallCollision(ball) || enemyPaddle.DoBallCollision(ball))
        {
            PlaySound(hitSound, "Resources/Audio/hitSound.ogg");
        }
    }   
}

void Game::Render()
{
    window.clear();
    // Render things here
    if (!gameStarted)
    {
        window.draw(startText);
    }
    else
    {
        ball.Render(window);
        playerPaddle.Render(window);
        enemyPaddle.Render(window);
        window.draw(playerScoreText);
        window.draw(enemyScoreText);
    }
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}

void Game::PlaySound(sf::Sound& sound, std::string fileName)
{
    if (!soundBuffer.loadFromFile(fileName))
    {
        std::cout << "Error al cargar archivo " << fileName << std::endl;
    }
    else
    {
        sound.setBuffer(soundBuffer);
        sound.play();
    }
}