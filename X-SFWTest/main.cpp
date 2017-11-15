
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
	int spawncounter = 0;
	int restcounter = 0;
	Manage.bubblemax = 6;
	int Spawnednum = 0;
	bool clicked = false;
	bool gather = false;
	float barLeng = 156;
	float barLengpos = 350;
	float barwidth = 12;
	sfw::initContext();
	
	vec2 pos2;
	myGuy me(10, 5, vec2{ 300, 400 }, vec2{ 25,25 }, 0);
	Ball ball;

	ball.transform.position = { 290,170 };
	ball.transform.dimension = { 15,15 };
	ball.collider.box.extents = { .5,.5 };
	
	
	//draw this					/630 , 365
	Manage.goal.transform.position = { 630 , 365 };
	Manage.goal.transform.dimension = { .5,.5 };
	Manage.goal.collider.box.extents = { 5,5 };



	Wall walls[27];
	//Boarder Walls


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

	walls[4].transform.position = { 400,600 };
	walls[4].transform.dimension = { 800,15 };
	walls[4].collider.box.extents = { .5,.5 };
	walls[4].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");
	
	//Level Walls

	//Top Block Right
	walls[3].transform.position = { 600,450 };
	walls[3].transform.dimension = { 400,15 };
	walls[3].collider.box.extents = { .5,.5 };
	walls[3].sprite.handle = sfw::loadTextureMap("../resources/Army_guy.png");
	//Top Block Left
	walls[12].transform.position = { 186,365 };
	walls[12].transform.dimension = { 347,15 };
	walls[12].collider.box.extents = { .5,.5 };


	walls[13].transform.position = { 400,600 };
	walls[13].transform.dimension = { 800,15 };
	walls[13].collider.box.extents = { .5,.5 };





	//First Objecvtive Left Wall
	walls[8].transform.position = { 150,15 };
	walls[8].transform.dimension = { 15,400 };
	walls[8].collider.box.extents = { .5,.5 };

	walls[9].transform.position = { 244,221 };
	walls[9].transform.dimension = { 200,15 };
	walls[9].collider.box.extents = { .5,.5 };

	walls[10].transform.position = { 353,235 };
	walls[10].transform.dimension = { 15,175 };
	walls[10].collider.box.extents = { .5,.5 };

	walls[11].transform.position = { 290,140 };
	walls[11].transform.dimension = { 145,15 };
	walls[11].collider.box.extents = { .5,.5 };


	walls[14].transform.position = { 550,280 };
	walls[14].transform.dimension = { 15,325 };
	walls[14].collider.box.extents = { .5,.5 };

	walls[15].transform.position = { 550,110 };
	walls[15].transform.dimension = { 200,15 };
	walls[15].collider.box.extents = { .5,.5 };


	walls[16].transform.position = { 730,210 };
	walls[16].transform.dimension = { 150,15 };
	walls[16].collider.box.extents = { .5,.5 };

	walls[17].transform.position = { 633,320 };
	walls[17].transform.dimension = { 150,15 };
	walls[17].collider.box.extents = { .5,.5 };
	// End of First Objective




	


		
	//}

	walls[25].transform.position = { 350,550 };
	walls[25].transform.dimension = { barLeng, barwidth };
	Manage.wall = walls;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 13);
		walls[26].transform.position = { barLengpos,550 };
		walls[26].transform.dimension = { barLeng, barwidth };
		vec2 WhereIsTheMouse = { sfw::getMouseX(),sfw::getMouseY() };
		vec2 Start = { 65 + rand()%80 - 40, 195 };
		//for (int i = 0; i < 4; ++i)
			//walls[i].sprite.draw(walls[i].transform);




		sfw::drawCircle(290, 170, 15, 12, BLUE);
		sfw::drawCircle(630, 365, 15, 12, BLUE);
		// player's position (third column is for translation)
		vec2 target = me.myTrans.getGlobalTransform()[2].xy;

		
		// clamp between 0,0 and 600,400  to restrict the camera from going off-screen
		target = max(vec2{ 0,0 }, min(target, vec2{ 600,400 }));

		// screen offset * zoom factor
		mat3 proj = translate({ 400, 300 }) * scale({ 1.2f,1.2f });
		mat3 view = inverse(translate(target));

		mat3 cam = proj * view;

		
		if (spawncounter > 0)
		{
			spawncounter--;

		}
		if (Spawnednum < Manage.bubblemax && spawncounter == 0)
		{
			
			//RandomVec = { rand() % 775 + 15.f,rand() % 575 + 15.f };
			//RandomVec = { 100,0 };
			Manage.MakeABaby(Start, Start);
			spawncounter = 10;
			Spawnednum++;
		}

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
			
			gather = false;
			
		
		}
		
		//if (clicked == true && counter == 0)
		//{
		//	counter = 10;
		//		vec2 WhereIsTheMouse = { sfw::getMouseX(), sfw::getMouseY() };
		//		//RandomVec = { rand() % 775 + 15.f,rand() % 575 + 15.f };
		//		RandomVec = { 100,0 };
		//		Manage.MakeABaby(WhereIsTheMouse, RandomVec);

		//}
		if (sfw::getMouseButton != (0))
		{
		
			clicked = false;
		}
		if (gather == true)
		{
			if (barLeng > 0)
			{
				barLengpos-=3;
				barLeng-=3;
			}
			if (barLeng <= 0)
			{
				//restcounter = 15;
				gather = false;
			}


			Manage.updateGatherAll();

		}
		if (gather == false)
		{
			if (barLeng <= 155)
			{
				barLengpos++;
				barLeng++;
			}
			Manage.updateAll();
		}


	/*	for (int i = 0; i < 4; ++i)
		{
			doCollision(&Manage.findCirclePntr[0], walls[i]);
		}*/

		Manage.drawAll();
		
		sfw::drawCircle(65, 15, 15);

		me.update();

		drawbox(Manage.goal.collider.getGlobalBox(Manage.goal.transform), GREEN);
		if (counter != 0)
		{
			counter--;
		}
		for (int i = 0; i < 27; ++i)
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
