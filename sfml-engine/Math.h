#pragma once

#include <math.h>

#include "Vector2.h"

namespace ae {

namespace Math {

namespace V2 {

	Vector2 Up();
	Vector2 Down();
	Vector2 Left();
	Vector2 Right();
	Vector2 One();
	Vector2 Zero();

	Vector2 Normalize(Vector2 v);
	float Length(Vector2 v);

	Vector2 Add(Vector2 v1, Vector2 v2);
	Vector2 Substract(Vector2 v1, Vector2 v2);
	Vector2 Scale(Vector2 v1, Vector2 v2);
	float Distance(Vector2 v1, Vector2 v2);
	float Dot(Vector2 v1, Vector2 v2);

	Vector2 Multiply(Vector2 v, float f);
	Vector2 Divide(Vector2 v, float f);

	bool Equals(Vector2 v1, Vector2 v2);

}

}

}