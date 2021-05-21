#pragma once

#include "Paddle.h"

class PlayerPaddle :
    public Paddle
{
public:
    // Constructor
    PlayerPaddle(sf::Vector2f pos, float width, float height);

    // Movement
    virtual void Update(const float& dt, const Ball& ball, const sf::FloatRect& walls);
};

