#include "Bubble.h"
#include "transform.h"

//#include <cmath>
void bubble::draw()
{
	sprite.draw(transform.position);
	

#ifdef _DEBUG
	drawbox(collider.getGlobalBox(transform), RED);
#endif
	//sfw::drawTexture(sprite_ship, transform.position.x, transform.position.y);
	//sfw::drawCircle(pos.x, pos.y, 5 , 4);
}

bubble::bubble(vec2 start, vec2 end)
{
	transform.position = start;
	des = end;
}

void bubble::explodeUpdate()
{
	counter = 298;
	des = { rand() % 775 + 15.f,rand() % 575 + 15.f };

}

void bubble::gatherUpdate()
{

	vec2 mousePos = { sfw::getMouseX(),sfw::getMouseY() };
	vec2 desiredVelocity = dist(mousePos, transform.position) * norm(mousePos - transform.position) ;

	rigidbody.acceleration *  dist(mousePos, transform.position);
	//rigidbody.force = (desiredVelocity - rigidbody.velocity) * 10;
	rigidbody.force.x = (desiredVelocity.x - rigidbody.velocity.x) *100;
	rigidbody.force.y = (desiredVelocity.y - rigidbody.velocity.y) *100;
	rigidbody.integrate(transform, sfw::getDeltaTime());

}

void bubble::update()
{
	
	rigidbody.force.y -= rigidbody.gravity;
	

	rigidbody.integrate(transform, sfw::getDeltaTime());

	

}



//void bubble::update()
//{	
//	
//	//rigidbody.force += norm(transform.getGlobalTransform()[1].xy) * randSpeed;
//
//
//
//	transform.position = lerp(transform.position, des, sfw::getDeltaTime() / 5);
//	if (counter >= 250 && counter < 300)
//	{
//		des.x = transform.position.x;
//		des.y = transform.position.x;
//	}
//	if (counter > 300)
//	{
//		des.x += rand() % 400 - 200;
//		des.y += rand() % 400 - 200;
//		//if (rand() % 100 + 1 == 50)
//		//{
//		//	des = { rand() % 775 + 15.f,rand() % 575 + 15.f };
//		//}
//		randSpeed = rand() % 20 + 10.f;
//		counter = 0;
//	}
//	counter+=rand()%2+1;
//
//		if(transform.position.x > 800)
//			des.x -= rand() %200;
//		if (transform.position.x < 0)
//			des.x += rand() %200;
//		if (transform.position.y > 600)
//			des.y -= rand() %200;
//		if (transform.position.y < 0)
//			des.y += rand() %200;
//}

/*Find the area of the radius behind the bubble and have collsion with all other characters*/