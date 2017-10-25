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
	pos = lerp(pos, des, sfw::getDeltaTime() / randSpeed);
	if (counter > 200)
	{
		des.x += rand() % 100 - 50;
		des.y += rand() % 100 - 50;
		if (rand() % 100 + 1 == 50)
		{
			des = { rand() % 775 + 15.f,rand() % 575 + 15.f };
		}
		randSpeed = rand() % 6 + 3.f;
		counter = 0;
	}
	counter+=rand()%2+1;
}

void bubble::draw()
{
	
	sfw::drawTexture(sprite_ship, pos.x, pos.y,15.f,15.f);
	//sfw::drawCircle(pos.x, pos.y, 5 , 4);
}



/*Find the area of the radius behind the player and have collsion with all other characters*/