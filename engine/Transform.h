#include <allegro5/allegro.h>
#pragma once
class Transform
{
public:
	Transform();
	void pushTrans();
	void translate(float x, float y);
	void scale(float x, float y);
	void popTrans();
	~Transform();

private:
	ALLEGRO_TRANSFORM currTrans;
	ALLEGRO_TRANSFORM originTrans;
	
};