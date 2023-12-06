#include <iostream>
#include "raylib.h"
#include "player.h"
#include "move-keys.h"
#include "axe-game-utils.h"

int main()
{
    int width = 800;
    int height = 450;

    Circle A = {static_cast<int>(width / 0.5), static_cast<int>(height * 0.5), 25, RED};
    // Circle A = {static_cast<int>(width / 0.5), height * 0.5, 25, RED};
    MoveKeys playerA_keys = {KEY_W, KEY_S, KEY_A, KEY_D};

    Circle B = {static_cast<int>(width * 0.5), static_cast<int>(height * 0.5), 35, BLUE};
    MoveKeys playerB_keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

    float movementSpeed = 500.0f; // pixels pr. second

    char textToDraw[50] = "Axe Game";

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(width, height, "Axe Game");
    SetTargetFPS(60);

    // TODO: Update player movement to deltaTime for smoother movement

    float deltatime;

    while (!WindowShouldClose())
    {
        deltatime = GetFrameTime();

        BeginDrawing();

        ClearBackground(LIGHTGRAY); // avoid flickering while double buffering

        Player::draw(width, height, A, movementSpeed * deltatime, playerA_keys);
        Player::draw(width, height, B, movementSpeed * deltatime, playerB_keys);

        if (circlesCollide(A, B))
        {
            DrawText("COLLISION", 10, 10, 20, BLACK);
        }
        else
        {
            DrawText("AXE GAME", 10, 10, 20, BLACK);
        }

        EndDrawing();
    }

    // Clean up
    CloseWindow();
}
