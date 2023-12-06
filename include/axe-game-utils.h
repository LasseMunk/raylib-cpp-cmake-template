#pragma once
#include <cstring> // for strcpy

void collisionDetection(int *x1, int *y1, int *radius1, int *x2, int *y2, int *radius2, char *textToDraw)
{
    // circle bounding box is circle_y - circle_radius, circle_y + circle_radius, circle_x - circle_radius, circle_x + circle_radius
    // does it collide with point at x300:
    // circle_y + circle_radius >= 300
    if (*y1 + *radius1 >= *y2 + *radius2)
    {
        // collision detected!
        strcpy(textToDraw, "Collision detected!");

        // printf("x1: %d, y1: %d, radius1: %d\n", *x1, *y1, *radius1);
        // printf("x2: %d, y2: %d, radius2: %d\n", *x2, *y2, *radius2);
        // printf("y1 + radius1: %d\n", *y1 + *radius1);
        // printf("y2 - radius2: %d\n", *y2 - *radius2);
        // printf("y1 - radius1: %d\n", *y1 - *radius1);
        // printf("y2 + radius2: %d\n", *y2 + *radius2);
        // printf("x1 + radius1: %d\n", *x1 + *radius1);
        // printf("x2 - radius2: %d\n", *x2 - *radius2);
        // printf("x1 - radius1: %d\n", *x1 - *radius1);
        // printf("x2 + radius2: %d\n", *x2 + *radius2);
        // printf("\n");
    }
}