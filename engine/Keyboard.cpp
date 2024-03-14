#include "Keyboard.h"

int Keyboard::keys[ALLEGRO_KEY_MAX - 1];
const int Keyboard::KEY_UP = ALLEGRO_KEY_UP;
const int Keyboard::KEY_DOWN = ALLEGRO_KEY_DOWN;
const int Keyboard::KEY_LEFT = ALLEGRO_KEY_LEFT;
const int Keyboard::KEY_RIGHT = ALLEGRO_KEY_RIGHT;
const int Keyboard::KEY_W = ALLEGRO_KEY_W;
const int Keyboard::KEY_A = ALLEGRO_KEY_A;
const int Keyboard::KEY_S = ALLEGRO_KEY_S;
const int Keyboard::KEY_D = ALLEGRO_KEY_D;

Rect Keyboard::mouse = Rect(0,0);

Keyboard::Keyboard()
{}

bool Keyboard::isKeyDown(int code)
{
	return keys[code];
}

bool Keyboard::isKeyJustPress(int code)
{
	bool press = false;
	if((!press) && keys[code])
	{
		return true;
		press = true;
	}
	return false;
}