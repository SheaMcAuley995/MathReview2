#pragma once

#include "vec2.h"

class Player
{
public:
	vec2 pos;
	
	void update();
	void draw();
};