#include "mathutils.h"

#include "vec2.h"
#include "vec3.h"
#include "mat3.h"

#include <cassert>

int main()
{
	//int val = min(1, 3);

	//vec2 test;
	//test.x = 5;
	//test.y = 20;

	//vec2 testB;
	//testB.x = 13;
	//testB.y = 4;

	//vec2 result = test + testB;

	//vec2 num;
	//num.x = 0;
	//num.y = 0;

	//num += test;

	//bool eq = num == test;
	//bool ieq = num == testB;
	//
	//// equality and inequality
	//{
	//	vec2 a = { 0,0 };
	//	vec2 b = { 0,0 };
	//	vec2 c = { 0,1 };

	//	assert(a == b);
	//	//assert(a != c);
	//}

	//{
	//	vec2 a = { 5,3 };
	//	vec2 b = { 4,2 };
	//	
	//	assert((a + b) == (vec2{9, 5}));

	//	
	//}

	mat3 I = mat3::indentity();
	mat3 Z = mat3::zero();
	mat3 A = { 1,2,3,4,5,6,7,8,9 };
	vec3 v = { 1,2,3 };


	assert(I + Z == I);
	assert(Z + I == I);
	assert(I - Z == I);
	assert(!(Z - I == I));
	assert(transpose(I) == I);
	assert(A*I == A);
	assert(I*A == A);

	//assert(I*v == v);

	assert(inverse(I) == I);

	mat3 T = scale(vec2{ 1,2 }) *
		rotate(90) *
		translate(vec2{ 3,0 });

	assert((T[2].xy == vec2{ 0,6 }));

	while (true) {}
}