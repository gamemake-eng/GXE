#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
#include <string>
#include "../include/sol.hpp"
#pragma once
class Font
{
public:
	Font();
	Font(std::string path, int size);
	
	~Font();
	
	ALLEGRO_FONT* font;
private:
	
	
};