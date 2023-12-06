#include "player.h"

void Player::draw(const int &screenW, const int &screenH, Circle &circle, const float &movementSpeed, const MoveKeys &moveKeys)
{
    if (IsKeyDown(moveKeys.up))
    {
        circle.y -= movementSpeed;
        if (circle.y < 0 - circle.radius)
            circle.y = screenH + circle.radius;
    }
    if (IsKeyDown(moveKeys.down))
    {
        circle.y += movementSpeed;
        if (circle.y > screenH + circle.radius)
            circle.y = 0 - circle.radius;
    }
    if (IsKeyDown(moveKeys.left))
    {
        circle.x -= movementSpeed;
        if (circle.x < 0 - circle.radius)
            circle.x = screenW + circle.radius;
    }
    if (IsKeyDown(moveKeys.right))
    {
        circle.x += movementSpeed;
        if (circle.x > screenW + circle.radius)
            circle.x = 0 - circle.radius;
    }

    DrawCircle(circle.x, circle.y, circle.radius, circle.color);
}
