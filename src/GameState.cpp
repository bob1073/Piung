#include "GameState.h"

GameState::GameState(std::stack<std::unique_ptr<State>>& states, int screenWidth, int screenHeight)
	:
	State(states),
	walls(0.0f, 0.0f, screenWidth, screenHeight),
	ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 1.0f, 0.0f }),
	playerPaddle({ 50.0f, screenHeight / 3.0f }, 15.0f, 125.0f),
	enemyPaddle({ 750.0f, screenHeight / 3.0f }, 15.0f, 125.0f)
{
    // Font loading
    if (!font.loadFromFile("Resources/Fonts/bit5x3.ttf"))
    {
        sf::err() << "Error al cargar la fuente\n";
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


void GameState::Update(float dt)
{
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            EndState();
        }
    }
}

void GameState::Render(sf::RenderTarget& target)
{
    if (!gameStarted)
    {
        target.draw(startText);
    }
    else
    {
        ball.Render(target);
        playerPaddle.Render(target);
        enemyPaddle.Render(target);
        target.draw(playerScoreText);
        target.draw(enemyScoreText);
    }
}

void GameState::PlaySound(sf::Sound& sound, std::string fileName)
{
    if (!soundBuffer.loadFromFile(fileName))
    {
        sf::err() << "Error al cargar archivo " << fileName << std::endl;
    }
    else
    {
        sound.setBuffer(soundBuffer);
        sound.play();
    }
}
