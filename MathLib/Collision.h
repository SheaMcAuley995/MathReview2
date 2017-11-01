#pragma once
#include "shapes.h"
#include "mathutils.h"
#include <cmath>

struct Collision
{
	float penetrationDepth;
	float handedness;
	vec2 axis;

};

Collision intersec_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision intersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle & A, const circle & B);

Collision intersec_AABB_Circle(const AABB &A, const circle &B);