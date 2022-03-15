#include "Math.h"

namespace ae {

namespace Math {

namespace V2 {

Vector2 Up()
{
    return Vector2(-1, 0);
}

Vector2 Down()
{
    return Vector2(1, 0);
}

Vector2 Left()
{
    return Vector2(0, -1);
}

Vector2 Right()
{
    return Vector2(0, 1);
}

Vector2 One()
{
    return Vector2(1, 1);
}

Vector2 Zero()
{
    return Vector2(0, 0);
}

float Length(Vector2 v)
{
    return sqrt(Dot(v, v));
}

Vector2 Normalize(Vector2 v)
{
    return v / Length(v);
}

float Distance(Vector2 v1, Vector2 v2)
{
    return Length(v2 - v1);
}

Vector2 Add(Vector2 v1, Vector2 v2)
{
    return Vector2(v1.x + v2.x, v1.y + v2.y);
}

Vector2 Substract(Vector2 v1, Vector2 v2)
{
    return Vector2(v1.x - v2.x, v1.y - v2.y);
}

Vector2 Scale(Vector2 v1, Vector2 v2)
{
    return Vector2(v1.x * v2.x, v1.y * v2.y);
}

float Dot(Vector2 v1, Vector2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

Vector2 Multiply(Vector2 v, float f)
{
    return Vector2(v.x * f, v.y * f);
}

Vector2 Divide(Vector2 v, float f)
{
    return Vector2(v.x / f, v.y / f);
}

bool Equals(Vector2 v1, Vector2 v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

}

}

}