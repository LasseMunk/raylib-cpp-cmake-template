#include "player.h"

Player::Player(int radius, Color color)
{
    this->radius = radius;
    this->color = color;
}

void Player::draw(int *width, int *height, int *posX, int *posY, int *movementSpeed, MoveKeys *moveKeys)
{
    if (IsKeyDown(moveKeys->up))
    {
        *posY -= *movementSpeed;
        if (*posY < 0 - this->radius)
            *posY = *height + this->radius;
    }
    if (IsKeyDown(moveKeys->down))
    {
        *posY += *movementSpeed;
        if (*posY > *height + this->radius)
            *posY = 0 - this->radius;
    }
    if (IsKeyDown(moveKeys->left))
    {
        *posX -= *movementSpeed;
        if (*posX < 0 - this->radius)
            *posX = *width + this->radius;
    }
    if (IsKeyDown(moveKeys->right))
    {
        *posX += *movementSpeed;
        if (*posX > *width + this->radius)
            *posX = 0 - this->radius;
    }

    DrawCircle(*posX, *posY, this->radius, this->color);
}
