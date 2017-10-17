#include "vec3.h"
#include "mathutils.h"

#include <cmath>
#include <cfloat>


vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;

	return result;

}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;

	return result;
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	vec3 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	result.z = lhs.z * rhs;

	return result;
}

vec3 operator*(float lhs, const vec3 & rhs)
{
	return rhs * lhs;
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	vec3 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;
	result.z = lhs.z / rhs;
	return vec3();
}

vec3 operator-(const vec3 & lhs)
{
	vec3 result;
	result.x = lhs.x * -1;
	result.y = lhs.y * -1;
	result.z = lhs.z * -1;

	return result;
}

vec3 operator+=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;

	return lhs;
}

vec3 operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 operator*=(vec3 & lhs, float & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 operator/=(vec3 & lhs, float & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON) 
	{ return true; }

	else { return false; }
	
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return !(lhs == rhs);
}

float mag(const vec3 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;
	float cSqr = v.z * v.z;

	return sqrtf(aSqr + bSqr + cSqr);
}

vec3 norm(const vec3 & v)
{
	vec3 temp = v;
	float len = mag(v);

	temp /= len;

	return temp;
}

vec3 & normalize(vec3 & v)
{
	v = norm(v);

	return v;
}

float dot(const vec3 & a, const vec3 & b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float dist(const vec3 & a, const vec3 & b)
{
	return mag(b - a);
}

vec3 min(const vec3 & a, const vec3 & b)
{
	vec3 temp; 
	temp.x = fmin(a.x, b.x);
	temp.y = fmin(a.y, b.y);
	temp.z = fmin(a.z, b.z);

	
	return vec3();
}

vec3 max(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = fmax(a.x, b.x);
	temp.y = fmax(a.y, b.y);
	temp.z = fmax(a.z, b.z);

	return temp;
}

vec3 clamp(const vec3 & min, const vec3 & v, const vec3 & max)
{
	vec3 dummy = v;

	if (dummy.x < min.x) { dummy.x = min.x; }
	if (dummy.x > max.x) { dummy.x = min.x; }


}




