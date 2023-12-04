#include "raylib.h"
#include "player.h"
#include "move-keys.h"

int main()
{
    int width = 800;
    int height = 450;

    Player playerA(width / 2, height / 2, 25, RED); // posX, posY, radius, color
    MoveKeys playerA_keys = {KEY_W, KEY_S, KEY_A, KEY_D};

    Player playerB(width / 3, height / 3, 35, BLUE);
    MoveKeys playerB_keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

    int movementSpeed = 4;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, "Axe Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(LIGHTGRAY); // avoid flickering while double buffering

        playerA.move(&width, &height, &movementSpeed, &playerA_keys);
        playerB.move(&width, &height, &movementSpeed, &playerB_keys);

        DrawText("Axe Game", 10, 10, 20, BLACK);
        EndDrawing();
    }

    // Clean up
    CloseWindow();
}
