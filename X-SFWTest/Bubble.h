#pragma once
#include "vec2.h"
#include "mat3.h"
#include "sfwdraw.h"
#include <time.h>
#include <random>
#include "transform.h"


class bubble
{
public:

	vec2 pos;
	vec2 des;
	int counter = 0;
	float randSpeed = rand() % 6 + 3.f;
	bubble(vec2 start, vec2 end);
	unsigned sprite_ship = sfw::loadTextureMap("../resources/pixil-layer-Background.png");
	void explodeUpdate();
	void gatherUpdate();
	void update();
	void draw();
};

//void MakeBubble();


//
//
//void Holdinfo()
//{
//	srand(time(NULL));
//	vec2 pos;
//	int randSpeed = rand() % 3 + 1;
//	int i = 0;
//	int Rx1 = rand() % 775 + 15;
//	int Ry1 = rand() & 575 + 15;
//
//	int Rx2 = rand() % 775 + 15;
//	int Ry2 = rand() & 575 + 15;
//
//	int Xv = Rx2 - Rx1;
//	int Yv = Ry2 - Ry1;
//
//	vec2 r1 = { Rx1, Ry1 };
//	vec2 r2 = { Rx2, Ry2 };
//
//	int counter = 0;
//	float circlespeed = 2;
//	pos.x = Rx1;
//	pos.y = Ry1;
//
//	
//	
//	sfw::drawCircle(pos.x, pos.y, 15, 12, RED);
//	
//	
//	pos = lerp(pos, r2, sfw::getDeltaTime() / randSpeed);
//	counter += sfw::getDeltaTime();
//	counter++;
//	if (counter == 200)
//	{
//		randSpeed = rand() % 5 + 1;
//		r2 = { rand() % 600 + 1.f,rand() % 800 + 1.f };
//		counter = 0;
//	}
//	std::cout << counter << std::endl;
//
//}
//
