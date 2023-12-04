#include "raylib.h"
#include "player.h"

Player::Player(int posX, int posY, int radius)
{
    this->posX = posX;
    this->posY = posY;
    this->radius = radius;
}

void Player::move(int *width, int *height, int *movementSpeed)
{
    if (IsKeyDown(KEY_D))
    {
        this->posX += *movementSpeed;
        if (this->posX > *width + this->radius)
            this->posX = 0 - this->radius;
    }
    if (IsKeyDown(KEY_A))
    {
        this->posX -= *movementSpeed;
        if (this->posX < 0 - this->radius)
            this->posX = *width + this->radius;
    }
    if (IsKeyDown(KEY_W))
    {
        this->posY -= *movementSpeed;
        if (this->posY < 0 - this->radius)
            this->posY = *height + this->radius;
    }
    if (IsKeyDown(KEY_S))
    {
        this->posY += *movementSpeed;
        if (this->posY > *height + this->radius)
            this->posY = 0 - this->radius;
    }

    DrawCircle(this->posX, this->posY, this->radius, RED);
}
