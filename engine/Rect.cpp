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