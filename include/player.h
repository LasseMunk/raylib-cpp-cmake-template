#pragma once
#include "raylib.h"
#include "move-keys.h"

class Player
{
public:
    Player(int radius, Color color);

    void draw(int *width, int *height, int *posX, int *posY, int *movementSpeed, MoveKeys *moveKeys);

private:
    Color color;
    int radius;
};
