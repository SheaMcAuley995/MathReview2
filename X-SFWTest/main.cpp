
//Original RTS game
#include "sfwdraw.h"
#include "transform.h"
#include "Manager.h"
#include "MyGuy.h"
#include "mat3.h"
#include "player.h"
#include <iostream>
#include <random>
#include <time.h>
#include <cmath>



int main()
{
	Manager Manage;
	
	vec2 RandomVec = { rand()%775+15,rand() % 575 + 15 };
	int counter = 0;
	bool clicked = false;
	bool gather = false;
	sfw::initContext();

	vec2 pos2;
	myGuy me(10, 5, vec2{ 300, 400 }, vec2{ 25,25 }, 0);

	
	Wall walls[2];
	walls[0].transform.position = { 600,300 };
	walls[0].transform.dimension = { 80,240 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");

	while (sfw::stepContext())
	{

		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 13);

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
				RandomVec = { rand() % 775 + 15.f,rand() % 575 + 15.f };
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
	
		Manage.drawAll();

		for (int i = 0; i < 2; ++i)
			walls[i].sprite.draw(walls[i].transform);

		me.update();
		if (counter != 0)
		{
			counter--;
		}
	
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
