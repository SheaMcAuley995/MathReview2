#include "Bubble.h"


bubble::bubble(vec2 start, vec2 end)
{
	pos = start;
	des = end;
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
	if (counter <= 0)
	{
		des.x += rand() % 300 - 150;
		des.y += rand() % 300 - 150;
		randSpeed = rand() % 6 + 3.f;
		counter = 200;
	}
	
	if (des.x < 775 || des.x > 15 && des.y < 575 || des.y > 15)
	{
		pos = lerp(pos, des, sfw::getDeltaTime() / randSpeed);
	}
	if (des.x >= 775)
	
	counter--;
	
	
	//	if (counter > 200)
	//	{
	//		
	//	}
	//	//counter = rand()%550+10;
	//	//	if (counter >= 400 )
	//	//	{
	//	//		counter += rand() % 2;
	//	//		//randSpeed = rand() % 6 + 3.f;
	//	//		//counter = 200;
	//	//		des = pos;
	//	//	}
	//	//	else
	//	//	{
	//	//		randSpeed = rand() % 6 + 3.f;
	//	//		des = { rand() % 775 + 15.f,rand() % 575 + 15.f };
	//	//	}
	//	//}
	//	counter++;
	//}
}

void bubble::draw()
{
		sfw::drawCircle(pos.x, pos.y, 5 , 4);
}
