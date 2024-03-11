#include "Rect.h"

Rect::Rect(float xp, float yp, float wp, float hp)
{
	x = xp;
	y = yp;
	w = wp;
	h = hp;
}
Rect::Rect(float xp, float yp)
{
	x = xp;
	y = yp;
	w = 0;
	h = 0;
}

bool Rect::checkCollision(Rect &a, Rect &b)
{
	//Copied from https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection because I am lazy

	//Are any corners in the x-axis overlaping?
    bool collisionX = a.x + a.w >= b.x && b.x + b.w >= a.x;
    
    //Are any corners in the y-axis overlaping?
    bool collisionY = a.y + a.h >= b.y && b.y + b.h >= a.y;
    
    return collisionX && collisionY;
}

std::string Rect::obstacleCollision(Rect &a, Rect &aspeed, Rect &b, Rect &bspeed)
{
	//Copied from https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection because I am lazy

	//Are any corners in the x-axis overlaping?
	bool collisionX = a.x + a.w >= b.x && b.x + b.w >= a.x;

    //Are any corners in the y-axis overlaping?
	bool collisionY = a.y + a.h >= b.y && b.y + b.h >= a.y;

	std::string side = "";


	a.x += aspeed.x;
	b.x += bspeed.x;
	if (collisionX && collisionY)
	{	
		a.x -= aspeed.x+1;
		b.x -= bspeed.x+1;
		if(aspeed.x>0)
		{
			
			side = "left";
		}else if(aspeed.x<0)
		{
			side = "right";
		}
		if(bspeed.x>0)
		{
			side = "left";
		}else if(bspeed.x<0)
		{
			side = "right";
		}
	}

	a.y += aspeed.y;
	b.y += bspeed.y;
	if (collisionX && collisionY)
	{
		a.y -= aspeed.y+1;
		b.y -= bspeed.y+1;
		if(aspeed.y>0)
		{
			side = "up";
		}else if(aspeed.y<0)
		{
			side = "down";
		}
		if(bspeed.y>0)
		{
			side = "up";
		}else if(bspeed.y<0)
		{
			side = "down";
		}
	}

	return side;

}

/*void Rect::obstacleSolidCollision(Rect &a, Rect &aspeed, Rect &b)
{
	//Copied from https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection because I am lazy

	//Are any corners in the x-axis overlaping?
	bool collisionX = a.x + a.w >= b.x && b.x + b.w >= a.x;

    //Are any corners in the y-axis overlaping?
	bool collisionY = a.y + a.h >= b.y && b.y + b.h >= a.y;

	float top = b.y;
	float bottom = b.y + b.h;
	float left = b.x;
	float right = b.x + b.w;

	a.x += aspeed.x;
	if (collisionX && collisionY)
	{	
		if(a.x > right)
		{
			a.x = right;
		}
		if((a.x+a.w) < left)
		{
			a.x = left - a.w;
		}
	}

	a.y += aspeed.y;

	if (collisionX && collisionY)
	{
		if(a.y > bottom)
		{
			a.y = bottom;
		}
		if((a.y+a.h) < top)
		{
			a.y = top - a.h;
		}
		
	}
}*/