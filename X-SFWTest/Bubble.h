#pragma once
#include "vec2.h"
#include "mat3.h"
#include "sfwdraw.h"
#include <time.h>
#include <random>
#include "transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Sprite.h"
#include "DrawShape.h"

class bubble
{
public:
	
	Transform   transform;
	Rigidbody   rigidbody;
	Collider    collider;
	Sprite sprite;
	vec2 des = {0,0};
	vec2 WhereisMyMouse = { sfw::getMouseX(), sfw::getMouseY() };
	int counter = 0;
	float randSpeed = rand() % 6 + 3.f;

	//unsigned sprite_ship = sfw::loadTextureMap("../resources/Army_guy.png");
	void explodeUpdate();
	void gatherUpdate();

	void update();
	//void update(Rigidbody &rb, Transform &t);
	void draw();

	bubble(vec2 start, vec2 end);
};


class Wall // static rigidbody
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

class Goal // static rigidbody
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

class Ball // dynamic rigidbody
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
};


//Ball *ball;

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
