#include <allegro5/allegro.h>
#pragma once

class Keyboard
{
public:
	
	static int keys[ALLEGRO_KEY_MAX - 1];
	static const int KEY_UP;
	static const int KEY_DOWN;
	static const int KEY_LEFT;
	static const int KEY_RIGHT;
	static bool isKeyDown(int code);
	static bool isKeyJustPress(int code);
private:
	Keyboard();
};