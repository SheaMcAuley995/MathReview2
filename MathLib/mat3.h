#pragma once

#include "vec2.h"
#include "vec3.h"

union mat3
{
	vec3 c[3];
	float m[9];
	float mm[3][3];
	

	      vec3 &operator[](size_t idx)       { return c[idx]; }
	const vec3 &operator[](size_t idx) const { return c[idx]; }

	static mat3 indentity()
	{
		return mat3{1, 0, 0,
			0, 1, 0,
			0, 0, 1};
	}
	static mat3 zero()
	{
		return mat3{ 0, 0, 0,
			0, 0, 0,
			0, 0, 0 };
	}
};


mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
bool operator==(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &V); 


//10x4 * 4x1 = 10x1
//3x3 * 3x3 * 3x3 * 3x3 * 3x3 * 3x1 = 3x1
mat3 transpose(const mat3 &A); 
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);


mat3 translate(const vec2 &t);
mat3 translate(float x, float y);

mat3 scale(const vec2&s);
mat3 scale(float x, float y);

mat3 rotate(float deg);