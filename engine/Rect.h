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
	
};