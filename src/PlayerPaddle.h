#pragma once

#include "Paddle.h"

class PlayerPaddle :
    public Paddle
{
public:
    PlayerPaddle(sf::Vector2f pos, float width, float height);

    virtual void Update(const float& dt, const Ball& ball);
    virtual void DoBallCollision(Ball& ball) const;
};

