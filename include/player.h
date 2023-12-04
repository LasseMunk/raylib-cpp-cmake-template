#pragma once
#include "raylib.h"
#include "move-keys.h"

class Player
{
public:
    Player(int initPosX, int initPosY, int radius, Color color);

    void move(int *width, int *height, int *movementSpeed, MoveKeys *moveKeys);

private:
    int posX, posY, radius;
    Color color;
};
