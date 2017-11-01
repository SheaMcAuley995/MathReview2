#include "mat3.h"
#include <cmath>
mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	for (int i = 0; i < 9; ++i) { retval.m[i] = A.m[i] + B.m[i]; }

	return retval;

}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	for (int i = 0; i < 9; ++i) { retval.m[i] = A.m[i] - B.m[i]; }

	return retval;

}

bool operator==(const mat3 & A, const mat3 & B)
{
	return A[0] == B[0] &&
		   A[1] == B[1] &&
		   A[2] == B[2];
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	//for (int x = 0; x < 3; ++x)
	//	for (int y = 0; y < 3; ++y)
	//	{
	//		retval[y][x] = dot(vec3{ A[0][x],A[1][x], A[2][x] }, B[y]);
	//	}
	//return retval;
	mat3 retval;
	//
	mat3 At = transpose(A);

	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 3; ++x)		
		{
			retval[y][x] = dot(At[x],B[y]);
		}

	return retval;
}

vec3 operator*(const mat3 & A, const vec3 & V)
{
	mat3 at = transpose(A);

	return vec3{ dot(at[0], V),
		dot(at[1], V),
		dot(at[2], V) };
}

mat3 transpose(const mat3 & A)
{
	mat3 retval;
	for (int x = 0; x < 3; ++x)
		for (int y = 0; y < 3; ++y)
			retval[x][y] = A[y][x];

	return retval;

	return mat3{ A[0][0], A[1][0], A[2][0],
				 A[0][1], A[1][1], A[2][1],
				 A[0][2], A[1][2], A[2][2] };
}

float determinant(const mat3 & A)
{
	return dot(A[0], cross(A[1], A[2]));
}

mat3 inverse(const mat3 & A)
{
	float di = 1 / determinant(A);


	return transpose(mat3{
		cross(A[1], A[2]) * di,
		cross(A[2], A[0]) * di,
		cross(A[0], A[1]) * di } );
}

mat3 translate(const vec2 & t)
{
	//mat3 retval = mat3::indentity();

	//retval[2].xy = t;

	//return retval;

	return mat3{ 1,   0,  0,
				  0,   1,  0,
				t.x, t.y,  1 };
}

mat3 scale(const vec2 & s)
{
	return mat3{ s.x,  0,   0,
				  0, s.y,   0,
				  0,   0,   1 };
}

mat3 rotate(float deg)
{
	float rad = deg * 0.0174533;

	return{ cos(rad), sin(rad),0, // x-axis
		   -sin(rad), cos(rad),0, // y-axis
			0,        0,       1 }; // position
}

// x-axis:
	// x = cos(angle)
	// y = sin(angle)

// y-axis: perp(x-axis)
	// x = -X.y
	// y =  X.x

