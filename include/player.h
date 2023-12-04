#pragma once

class Player
{
public:
    Player(int posX, int posY, int radius);

    void move(int *width, int *height, int *movementSpeed);

private:
    int posX, posY, radius;
};
