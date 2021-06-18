#include "Game.h"
#include <iostream>

Game::Game()
    :
    window(sf::VideoMode(screenWidth, screenHeight), "Piung!", sf::Style::Close | sf::Style::Titlebar)
{

    states.push(std::make_unique<GameState>(states, screenWidth, screenHeight));
    window.setFramerateLimit(120);
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

    if (!states.empty())
    {
        states.top()->Update(dt);

        if (!states.top()->IsRunning())
        {
            states.pop();
        }
    }
    else
    {
        running = false;
    }
    
}

void Game::Render()
{
    window.clear();
    // Render things here
    if (!states.empty())
    {
        states.top()->Render(window);
    }
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}