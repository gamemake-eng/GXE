#include <string>
#pragma once
class Rect
{
public:
	Rect(float xp, float yp, float wp, float hp);
	Rect(float xp, float yp);

	float x;
	float y;
	float w;
	float h;

	static bool checkCollision(Rect &a, Rect &b);
	static std::string obstacleCollision(Rect &a, Rect &aspeed, Rect &b, Rect &bspeed);
	static void obstacleSolidCollision(Rect &a, Rect &aspeed, Rect &b);

	
};