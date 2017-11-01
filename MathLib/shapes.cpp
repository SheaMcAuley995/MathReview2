#include "shapes.h"
#include <cmath>

circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = mag(M[0].xy);
	scale.y = mag(M[1].xy);
	// Average? 

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}


AABB operator*(const mat3 &M, const AABB &B)
{
	AABB retval;
	vec2 TR = B.position + B.extents; // B
	vec2 BL = B.position - B.extents; //C
	vec2 BR = { B.position.x + B.extents.x, B.position.y - B.extents.y };//D
	vec2 TL = { B.position.x - B.extents.x, B.position.y + B.extents.y };  // A

	TR = (M * vec3{ TR.x, TR.y, 1 }).xy;
	BL = (M * vec3{ BL.x,BL.y,1 }).xy;
	TL = (M * vec3{ TL.x,TL.y,1 }).xy;
	BR = (M * vec3{ BR.x,BR.y,1 }).xy;
	
	retval.MinCorner = min(TR, min(BL, min(TL, BR)));
	retval.MaxCorner = max(TR, max(BL, max(TL, BR)));

	retval.position = (retval.MaxCorner + retval.MinCorner) / 2;
	retval.extents = (retval.MaxCorner - retval.MinCorner) / 2;

	return retval;
}