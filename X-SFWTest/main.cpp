
//Original RTS game
#include "sfwdraw.h"
#include "transform.h"
#include "Manager.h"
#include "MyGuy.h"
#include "mat3.h"
#include "DrawShape.h"
#include "Bubble.h"
#include <iostream>
#include <random>
#include <time.h>
#include <cmath>



int main()
{
	Manager Manage;
	bubble bub();
	vec2 RandomVec = { rand()%775+15,rand() % 575 + 15 };
	int counter = 0;
	bool clicked = false;
	bool gather = false;
	float barLeng = 15;
	float barwidth = 15;
	sfw::initContext();

	vec2 pos2;
	myGuy me(10, 5, vec2{ 300, 400 }, vec2{ 25,25 }, 0);
	
	
	Wall walls[6];

	walls[0].transform.position = { 5,400 };
	walls[0].transform.dimension = { 15,800 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");

	walls[1].transform.position = { 400,0 };
	walls[1].transform.dimension = { 800,15 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");

	walls[2].transform.position = { 800,300 };
	walls[2].transform.dimension = { 15,600 };
	walls[2].collider.box.extents = { .5,.5 };
	walls[2].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");

	walls[3].transform.position = { 600,400 };
	walls[3].transform.dimension = { 400,15 };
	walls[3].collider.box.extents = { .5,.5 };
	walls[3].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");

	walls[4].transform.position = { 400,600 };
	walls[4].transform.dimension = { 800,15 };
	walls[4].collider.box.extents = { .5,.5 };
	walls[4].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");

	for (int i = barLeng; barwidth != 0; --barwidth)
	{
		walls[5].transform.position = { 350,550 };
		walls[5].transform.dimension = { barwidth,barLeng };
	}


	Manage.wall = walls;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 13);


		//for (int i = 0; i < 4; ++i)
			//walls[i].sprite.draw(walls[i].transform);




		// player's position (third column is for translation)
		vec2 target = me.myTrans.getGlobalTransform()[2].xy;

		
		// clamp between 0,0 and 600,400  to restrict the camera from going off-screen
		target = max(vec2{ 0,0 }, min(target, vec2{ 600,400 }));

		// screen offset * zoom factor
		mat3 proj = translate({ 400, 300 }) * scale({ 1.2f,1.2f });
		mat3 view = inverse(translate(target));

		mat3 cam = proj * view;

		

		if (sfw::getMouseButton(0))
		{

			clicked = true;
		}
		if (gather == false && sfw::getMouseButton(1) && counter == 0)
		{
			counter = 10;
			
			
			gather = true;
			
		}
		else if (gather == true && sfw::getMouseButton(1) && counter == 0)
		{
			counter = 10;
			RandomVec = { rand() % 775 + 15.f,rand() % 575 + 15.f };
			gather = false;
			
		
		}
		
		if (clicked == true && counter == 0)
		{
			counter = 10;
				vec2 WhereIsTheMouse = { sfw::getMouseX(), sfw::getMouseY() };
				//RandomVec = { rand() % 775 + 15.f,rand() % 575 + 15.f };
				RandomVec = { 100,0 };
				Manage.MakeABaby(WhereIsTheMouse, RandomVec);

		}
		if (sfw::getMouseButton != (0))
		{
		
			clicked = false;
		}
		if (gather == true)
		{
		
			Manage.updateGatherAll();
		}
		if (gather == false)
		{
			Manage.updateAll();
		}


	/*	for (int i = 0; i < 4; ++i)
		{
			doCollision(&Manage.findCirclePntr[0], walls[i]);
		}*/

		Manage.drawAll();
		

		me.update();
		if (counter != 0)
		{
			counter--;
		}
		for (int i = 0; i < 5; ++i)
			drawbox(walls[i].collider.getGlobalBox(walls[i].transform), RED);
	}
	sfw::termContext();
}











////Example Game
//
//#include "sfwdraw.h"
//#include "transform.h"
//#include "Player.h"
//#include "MyGuy.h"
//#include "mat3.h"
//#include "Rigidbody.h"
//#include "shapes.h"
//#include "DrawShape.h"
//#include "Collision.h"
//#include <cmath>
//#include <string>
//#include <cstring>
//#include <cassert>
//
//
//int main()
//{
//	sfw::initContext();
//
//	Transform transform;
//	Rigidbody rigidbody;
//	AABB aabb = { { 0,0 },{ 1,1 } };
//	circle circ = { { 0,0 }, 1 };
//	AABB box = { {400,300}, {10,10} };
//	transform.position = vec2{ 400, 300 };
//	transform.dimension = vec2{ 10,15 };
//	circle circ2 = { {700,500},50 };
//	bool jumped = false;
//	while (sfw::stepContext())
//	{
//	    Collision result = intersect_AABB(transform.getGlobalTransform() * aabb, box);
//		Collision result2 = intersect_circle(transform.getGlobalTransform() * circ, circ2);
//		unsigned color = result.penetrationDepth < 0 ? RED : WHITE;
//
//		if (result2.penetrationDepth >= 0)
//		{
//			transform.position += result2.axis * result2.handedness * result2.penetrationDepth;
//			//rigidbody.force -= rigidbody.velocity * 20;
//			rigidbody.velocity = -rigidbody.velocity;
//			
//			//rigidbody.torque += -rigidbody.angularVelocity * 20;
//		}
//
//
//	/*	if (result2.penetrationDepth >= 0)
//			transform.position += result.axis * result.handedness * result.penetrationDepth;*/
//
//		drawCircle(circ2);
//		//drawbox(box, color);
//		drawbox(transform.getGlobalTransform() * aabb, color);
//		drawCircle(transform.getGlobalTransform() * circ);
//		DrawMatrix(transform.getGlobalTransform(), 1);
//
//		float dt = sfw::getDeltaTime();
//
//		//rigidbody.force += { 0, -25 }; // gravity
//
//		// moving jets
//
//
//		rigidbody.integrate(transform, dt);
//	}
//	sfw::termContext();
//}
