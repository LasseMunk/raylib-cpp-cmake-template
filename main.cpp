#include "raylib.h"
#include "player.h"

int main()
{
    int width = 800;
    int height = 450;

    Player player(width / 2, height / 2, 25); // (posX, posY, radius

    int movementSpeed = 4;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, "Axe Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(LIGHTGRAY); // avoid flickering while double buffering

        player.move(&width, &height, &movementSpeed);

        DrawText("Axe Game", 10, 10, 20, BLACK);
        EndDrawing();
    }

    // Clean up
    CloseWindow();
}
