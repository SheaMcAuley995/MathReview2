#include "DrawShape.h"
#include "sfwdraw.h"

void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void DrawVecLine(const vec2 & a, const vec2 & b)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, RED);
}
void drawbox(const AABB & B, int color)
{
	vec2 TR = B.position + B.extents;
	vec2 BL = B.position - B.extents;
	vec2 TL = { B.position.x - B.extents.x, B.position.y + B.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, TL);
	DrawVecLine(TL, BL);
	DrawVecLine(BL, BR);
	DrawVecLine(BR, TR);
	
}


