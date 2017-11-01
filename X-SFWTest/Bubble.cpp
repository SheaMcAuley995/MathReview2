#include "Bubble.h"
#include "transform.h"
bubble::bubble(vec2 start, vec2 end)
{
	pos = start;
	des = end;
}

void bubble::explodeUpdate()
{
	counter = 298;
	des = { rand() % 775 + 15.f,rand() % 575 + 15.f };
	pos = lerp(pos, des, sfw::getDeltaTime() * 5);
}

void bubble::gatherUpdate()
{
	counter = 298;
	vec2 WhereIsTheMouse = { sfw::getMouseX(), sfw::getMouseY() };
	des = WhereIsTheMouse;
	pos = lerp(pos, des, sfw::getDeltaTime() *2);
}


void bubble::update()
{
	pos = lerp(pos, des, sfw::getDeltaTime() / 50);
	if (counter > 5000)
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

		if(pos.x > 800)
			des.x -= rand() %200;
		if (pos.x < 0)
			des.x += rand() %200;
		if (pos.y > 600)
			des.y -= rand() %200;
		if (pos.y < 0)
			des.y += rand() %200;
}

void bubble::draw()
{
	
	sfw::drawTexture(sprite_ship, pos.x, pos.y,15.f,15.f);
	//sfw::drawCircle(pos.x, pos.y, 5 , 4);
}



/*Find the area of the radius behind the player and have collsion with all other characters*/