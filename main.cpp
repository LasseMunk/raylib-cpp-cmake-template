#include "raylib.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 450;
    const char *windowTitle = "Hello, World!";
    InitWindow(screenWidth, screenHeight, windowTitle);

    // The following only works after InitWindow is called
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, World!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // Clean up
    CloseWindow();
}