#include "Collision.h"

Collision intersec_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;

	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;

	ret.penetrationDepth = min(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);

	return ret;
}

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	return Collision();
}

Collision intersect_AABB(const AABB & A, const AABB & B)
{
	Collision xres = intersec_1D(A.min().x, A.max().x, B.min().x, B.max().x);
	Collision yres = intersec_1D(A.min().y, A.max().y, B.min().y, B.max().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };

	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;

}

Collision intersect_circle(const circle & A, const circle & B)
{
	Collision ret;
	ret.axis = norm(B.position - A.position);
	ret.handedness = -1;

	float Ap = dot(ret.axis, A.position);
	float Bp = dot(ret.axis, B.position);

	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;

	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;

	ret.penetrationDepth = intersec_1D(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;
}

void static_resolution(vec2 & Apos, vec2 & Avel, float Amass,
	vec2 & Bpos, vec2 & Bvel, float Bmass,
	const Collision & hit, float elasticity)
{
	// Law of conservation
	/*
	mass * vel = momentum

	Ap + BP = ` AP + `BP // converation of mementum

	Avel * Amass + Bvel * Bmass = fAvel*Amass + fBvel* Bmass
	Avel - Bvel= -(fBvel - fAvel)

	fBvel = Bvel - Avel + fAvel1

	Avel*Amass +  = fAvel
	
	
	*/
	vec2 normal = hit.axis * hit.handedness;

	vec2 Rvel = Avel - Bvel;

	//dot(Rvel, normal);

	
	float j = -(1 + elasticity)*dot(Rvel, normal) / dot(normal, normal*(1 / Amass + 1 / Bmass));

	Avel += (j / Amass) * normal;
	Bvel -= (j / Bmass) * normal;

	Apos += normal * hit.penetrationDepth * Amass / (Amass + Bmass);
	Bpos -= normal * hit.penetrationDepth * Bmass / (Amass + Bmass);

	vec2 fAvel = Avel + (j / Amass) * hit.axis * hit.handedness;
}


//Collision intersec_AABB_Circle(const AABB & A, const circle & B)
//{ 
//
//}
