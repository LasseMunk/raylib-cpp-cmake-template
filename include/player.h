#pragma once
#include "raylib.h"
#include "move-keys.h"
#include "axe-game-types.h"

class Player
{
public:
    static void draw(const int &screenW, const int &screenH, Circle &circle, const float &movementSpeed, const MoveKeys &moveKeys);
};
