#include "sfwdraw.h"
#include "transform.h"

#include "MyGuy.h"
#include "mat3.h"

#include <iostream>
#include <random>
#include <time.h>
#include <cmath>

int main()
{
	//sfw::initContext();
	//int 15 = 1;
	//myGuy me(10, 5, vec2{ 300, 400 }, vec2{ 25,25 }, 0);

	//Transform tran_background = { { 400,300 },{ 800,600 }, 0 }; //pos,dim,ang
	//Transform army_guy =   { { 300, 400 }, { 25,25 }, 0 };
	//Transform tran_tree1 = { { 200,300 },{ 100,100 }, 0 };
	//Transform tran_tree2 = { { 400,500 },{ 72,72 }, 0 };
	//Transform tran_tree3 = { { 700,200 },{ 72,72 }, 0 };
	//Transform tran_tree4 = { { 100,100 },{ 72,72 }, 0 };

	//
	//unsigned sprite_background = sfw::loadTextureMap("../resources/back.jpg");
	//unsigned sprite_tree = sfw::loadTextureMap("../resources/House.png");
	//unsigned sprite_ship = sfw::loadTextureMap("../resources/pixil-layer-Background.png");
	////unsigned army_guy = sfw::loadTextureMap("../resources/pixil-layer-Background.png");

	//// adjust space so that screen center is 0,0 and dimensions are 250,250

	//while (sfw::stepContext())
	//{

	//	// player's position (third column is for translation)
	//	vec2 target = me.myTrans.getGlobalTransform()[2].xy;

	//	// clamp between 0,0 and 600,400  to restrict the camera from going off-screen
	//	target = max(vec2{ 0,0 }, min(target, vec2{ 600,400 }));

	//	// screen offset * zoom factor
	//	mat3 proj = translate({ 400, 300 }) * scale({ 1.2f,1.2f });
	//	mat3 view = inverse(translate(target));

	//	mat3 cam = proj * view;

	//	
	//	if (sfw::getMouseButton(0))
	//	{
	//		if (15 != 50)
	//		{
	//			15++;
	//		}
	//	}
	//	else
	//	{
	//		15 = 10;
	//	}
	//	DrawTexture(sprite_background, cam * tran_background.getGlobalTransform());
	//	DrawTexture(sprite_tree, cam * tran_tree1.getGlobalTransform());
	//	//DrawTexture(army_guy, cam * army_guy.getGlobalTransform());
	//	//DrawTexture(sprite_tree, cam * tran_tree2.getGlobalTransform());
	//	//DrawTexture(sprite_tree, cam * tran_tree3.getGlobalTransform());
	//	//DrawTexture(sprite_tree, cam * tran_tree4.getGlobalTransform());
	//	sfw::drawCircle(sfw::getMouseX() + 25, sfw::getMouseY(), 15);
	//	sfw::drawCircle(sfw::getMouseX() - 25, sfw::getMouseY(), 15);
	//	sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY() + 25, 15);
	//	sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY() - 25, 15);
	//	sfw::drawCircle(sfw::getMouseX() + 25, sfw::getMouseY() + 25, 15);
	//	sfw::drawCircle(sfw::getMouseX() - 25, sfw::getMouseY() + 25, 15);
	//	sfw::drawCircle(sfw::getMouseX() - 25, sfw::getMouseY() - 25, 15);
	//	sfw::drawCircle(sfw::getMouseX() + 25, sfw::getMouseY() - 25, 15);
	//	DrawTexture(sprite_ship, cam * me.myTrans.getGlobalTransform());
	//	
	//	//DrawTexture(sprite_ship,);
	//	me.update();
	//	//sfw::drawCircle(300, 400, 15, 12, RED);
	//}
	//sfw::termContext();
	sfw::initContext();
	srand(time(NULL));

	vec2 pos;
	vec2 pos2;
	//vec2 movement = { 0,0 };
	

	
	//int 15 = 1;
	myGuy me(10, 5, vec2{ 300, 400 }, vec2{ 25,25 }, 0);

	

	//Transform::Transform(vec2 a_pos, vec2 a_dim, float a_ang)
	//{
	//	position = a_pos; //vec2{ 0,0 };
	//	dimension = a_dim;//  vec2{ 0,0 };
	//	angle = a_ang; // 0;
	//	e_parent = nullptr;
	//}
	
	int randSpeed = rand() % 3 + 1;
	int i = 0;
	int Rx1 = rand() % 775 + 15;
	int Ry1 = rand() & 575 + 15;

	int Rx2 = rand() % 775 + 15;
	int Ry2 = rand() & 575 + 15;

	int Xv = Rx2 - Rx1;
	int Yv = Ry2 - Ry1;

	vec2 r1 = { Rx1, Ry1 };
	vec2 r2 = { Rx2, Ry2 };

	int counter = 0;
	float circlespeed = 2;
	pos.x = Rx1;
	pos.y = Ry1;
	pos2.x = Rx1;
	pos2.y = Ry1;

	vec2 Dir(norm(r2 - r1)*circlespeed);
	while (sfw::stepContext())
	{
		/*	if (sfw::getMouseButton(0))
			{
				if (15 != 50)
				{
					15++;
				}
			}
			else
			{
				15 = 10;
			}
*/

		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 15);
		if (sfw::getMouseButton(0))
		{
				
		}
		
		sfw::drawCircle(775, 575, 15, 12, RED);
		sfw::drawCircle(0, 0, 15, 12, RED);
		// player's position (third column is for translation)
		vec2 target = me.myTrans.getGlobalTransform()[2].xy;

		
		// clamp between 0,0 and 600,400  to restrict the camera from going off-screen
		target = max(vec2{ 0,0 }, min(target, vec2{ 600,400 }));

		// screen offset * zoom factor
		mat3 proj = translate({ 400, 300 }) * scale({ 1.2f,1.2f });
		mat3 view = inverse(translate(target));
		/*sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 15);*/
		mat3 cam = proj * view;
		
		
		/*sfw::drawCircle(pos.x, pos.y, 15, 12, RED);
		pos += Dir;
		sfw::drawCircle(pos2.x, pos2.y, 15, 12, RED);*/
		/*pos2 = lerp(pos2, r2, sfw::getDeltaTime()/randSpeed);
		counter += sfw::getDeltaTime();
		counter++;
		if (counter == 200)
		{
			randSpeed = rand() % 5 + 1;
			r2 = { rand() % 600 + 1.f,rand() % 800 + 1.f };
			counter = 0;
		}*/
	
		unsigned sprite_ship = sfw::loadTextureMap("../resources/pixil-layer-Background.png");

		DrawTexture(sprite_ship, cam * me.myTrans.getGlobalTransform());
		me.update();
		std::cout << counter << std::endl;
	}
	sfw::termContext();
}



