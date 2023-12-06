#pragma once
#include <cstring> // for strcpy
#include <cmath>
#include "axe-game-types.h"

bool circlesCollide(const Circle &A, const Circle &B)
{
    // Calculate distance between centers of circles using the distance formula
    // distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
    double distance = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));

    // check if the distance is less than the sum of the radii
    return distance <= A.radius + B.radius;
}