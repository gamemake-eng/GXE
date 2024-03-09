#include "Color.h"
#include <string>
#include <allegro5/allegro_font.h>
#include "../include/sol.hpp"
#include "Font.h"
#include "Color.h"
#pragma once 
class Graphics
{
public:
	static void clearScreen(Color &color);

private:
	Graphics();
	
};