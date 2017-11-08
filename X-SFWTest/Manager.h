#pragma once
#include "mat3.h"
#include "vec2.h"
#include "Bubble.h"
#include "DrawShape.h"
#include "Rigidbody.h"
#include "transform.h"

class Manager
{
public:

	Rigidbody rb;
	Transform t;
	int bubblemax = 25;
	Wall * wall;
	bubble * OtherBub;
	bubble * findCirclePntr[256] = { nullptr };
	vec2 WhereIsTheMouse = { sfw::getMouseX(), sfw::getMouseY() };
	void MakeABaby(vec2 spawn, vec2 target);
	void updateAll();
	
	void drawAll();
	void updateGatherAll();
	void updateExplodeAll();
};
//void doCollision(bubble * bub, bubble & bub2);
bool doCollision(bubble &bubble, const Wall &wall);
bool doCollision(Ball &ball, const Wall &wall);
bool doCollision(bubble &bubble, Ball &wall);
void doCollision(bubble * bub, bubble * bub2);
//
//class Manager
//{
//	int baseArray;
//	int * findCirclePntr[256] = { nullptr };
//
//	void MakeABaby(vec2 spawn, vec2 target)
//	{
//		int c = 0;
//		for (; findCirclePntr[c] != nullptr && c < 255; ++c);
//		if (c == 255) return;
//		findCirclePntr[c] = new Child(spawn, target);
//
//	}



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
