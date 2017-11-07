#include "Bubble.h"
#include "transform.h"

bubble::bubble(vec2 start, vec2 end)
{
	trans.position = start;
	des = end;
}

void bubble::explodeUpdate()
{
	counter = 298;
	des = { rand() % 775 + 15.f,rand() % 575 + 15.f };
	trans.position = lerp(trans.position, des, sfw::getDeltaTime() * 5);
}

void bubble::gatherUpdate()
{
	counter = 298;
	vec2 WhereIsTheMouse = { sfw::getMouseX(), sfw::getMouseY() };
	des = WhereIsTheMouse;
	trans.position = lerp(trans.position, des, sfw::getDeltaTime() *2);
}


void bubble::update()
{	
	
	trans.position = lerp(trans.position, des, sfw::getDeltaTime() / 5);
	if (counter >= 250 && counter < 300)
	{
		des.x = trans.position.x;
		des.y = trans.position.x;
	}
	if (counter > 300)
	{
		des.x += rand() % 400 - 200;
		des.y += rand() % 400 - 200;
		//if (rand() % 100 + 1 == 50)
		//{
		//	des = { rand() % 775 + 15.f,rand() % 575 + 15.f };
		//}
		randSpeed = rand() % 20 + 10.f;
		counter = 0;
	}
	counter+=rand()%2+1;

		if(trans.position.x > 800)
			des.x -= rand() %200;
		if (trans.position.x < 0)
			des.x += rand() %200;
		if (trans.position.y > 600)
			des.y -= rand() %200;
		if (trans.position.y < 0)
			des.y += rand() %200;
}

void bubble::draw()
{
	
	sfw::drawTexture(sprite_ship, trans.position.x, trans.position.y,15.f,15.f);
	//sfw::drawCircle(pos.x, pos.y, 5 , 4);
}



/*Find the area of the radius behind the player and have collsion with all other characters*/