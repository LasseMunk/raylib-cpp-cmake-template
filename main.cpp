#include <iostream>
#include "raylib.h"
#include "player.h"
#include "move-keys.h"
#include "axe-game-utils.h"

int main()
{
    int width = 800;
    int height = 450;

    int playerA_x = width / 2;
    int playerA_y = height / 2;
    int playerA_radius = 25;
    Player playerA(playerA_radius, RED); // radius, color
    MoveKeys playerA_keys = {KEY_W, KEY_S, KEY_A, KEY_D};

    int playerB_x = width / 3;
    int playerB_y = height / 3;
    int playerB_radius = 35;
    Player playerB(playerB_radius, BLUE);
    MoveKeys playerB_keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

    int movementSpeed = 4;

    char textToDraw[50] = "Axe Game";

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, "Axe Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(LIGHTGRAY); // avoid flickering while double buffering

        playerA.draw(&width, &height, &playerA_x, &playerA_y, &movementSpeed, &playerA_keys);
        playerB.draw(&width, &height, &playerB_x, &playerB_y, &movementSpeed, &playerB_keys);

        collisionDetection(&playerA_x, &playerA_y, &playerA_radius, &playerB_x, &playerB_y, &playerB_radius, textToDraw);

        DrawText(textToDraw, 10, 10, 20, BLACK);
        EndDrawing();
    }

    // Clean up
    CloseWindow();
}

// Collision detection
// circle bounding box is circle_y - circle_radius, circle_y + circle_radius, circle_x - circle_radius, circle_x + circle_radius
// does it collide with point at x300:
// circle_y + circle_radius >= 300