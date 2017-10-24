#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "MyGuy.h"
#include "mat3.h"

#include <cmath>

int main()
{
	sfw::initContext();
	int circle_size = 1;
	myGuy me(10, 5, vec2{ 300, 400 }, vec2{ 25,25 }, 0);

	Transform tran_background = { { 400,300 },{ 800,600 }, 0 }; //pos,dim,ang

	Transform tran_tree1 = { { 200,300 },{ 72,72 }, 0 };
	Transform tran_tree2 = { { 400,500 },{ 72,72 }, 0 };
	Transform tran_tree3 = { { 700,200 },{ 72,72 }, 0 };
	Transform tran_tree4 = { { 100,100 },{ 72,72 }, 0 };


	unsigned sprite_background = sfw::loadTextureMap("../resources/back.jpg");
	unsigned sprite_tree = sfw::loadTextureMap("../resources/Giant_Tree.png");
	unsigned sprite_ship = sfw::loadTextureMap("../resources/pixil-layer-Background.png");

	// adjust space so that screen center is 0,0 and dimensions are 250,250

	while (sfw::stepContext())
	{

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
			if (circle_size != 50)
			{
				circle_size++;
			}
		}
		else
		{
			circle_size = 10;
		}
		DrawTexture(sprite_background, cam * tran_background.getGlobalTransform());
		//DrawTexture(sprite_tree, cam * tran_tree1.getGlobalTransform());
		//DrawTexture(sprite_tree, cam * tran_tree2.getGlobalTransform());
		//DrawTexture(sprite_tree, cam * tran_tree3.getGlobalTransform());
		//DrawTexture(sprite_tree, cam * tran_tree4.getGlobalTransform());
		sfw::drawCircle(sfw::getMouseX() + 25, sfw::getMouseY(), circle_size);
		sfw::drawCircle(sfw::getMouseX() - 25, sfw::getMouseY(), circle_size);
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY() + 25, circle_size);
		sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY() - 25, circle_size);
		sfw::drawCircle(sfw::getMouseX() + 25, sfw::getMouseY() + 25, circle_size);
		sfw::drawCircle(sfw::getMouseX() - 25, sfw::getMouseY() + 25, circle_size);
		sfw::drawCircle(sfw::getMouseX() - 25, sfw::getMouseY() - 25, circle_size);
		sfw::drawCircle(sfw::getMouseX() + 25, sfw::getMouseY() - 25, circle_size);
		DrawTexture(sprite_ship, cam * me.myTrans.getGlobalTransform());
		DrawTexture(sprite_ship,);
		me.update();
		
	}
	sfw::termContext();
}





