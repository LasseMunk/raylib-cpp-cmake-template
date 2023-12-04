#include "player.h"

Player::Player(int initPosX, int initPosY, int radius, Color color)
{
    this->posX = initPosX;
    this->posY = initPosY;
    this->radius = radius;
    this->color = color;
}

void Player::move(int *width, int *height, int *movementSpeed, MoveKeys *moveKeys)
{
    if (IsKeyDown(moveKeys->up))
    {
        this->posY -= *movementSpeed;
        if (this->posY < 0 - this->radius)
            this->posY = *height + this->radius;
    }
    if (IsKeyDown(moveKeys->down))
    {
        this->posY += *movementSpeed;
        if (this->posY > *height + this->radius)
            this->posY = 0 - this->radius;
    }
    if (IsKeyDown(moveKeys->left))
    {
        this->posX -= *movementSpeed;
        if (this->posX < 0 - this->radius)
            this->posX = *width + this->radius;
    }
    if (IsKeyDown(moveKeys->right))
    {
        this->posX += *movementSpeed;
        if (this->posX > *width + this->radius)
            this->posX = 0 - this->radius;
    }

    DrawCircle(this->posX, this->posY, this->radius, this->color);
}
