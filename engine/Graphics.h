#include "Color.h"
#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "../include/sol.hpp"
#include "Font.h"
#include "Color.h"
#include "Rect.h"
#include "Image.h"
#pragma once 
class Graphics
{
public:
	static void clearScreen(Color &color);
	static void drawCircle(float x, float y, float r, Color &color);
	static void drawRect(Rect &rect, Color &color);
	static void drawText(std::string text,float x, float y, Color &color, Font &font);

	static void drawImage(Image &img, float x, float y);
	static void drawCropImage(Image &img, Rect &source, float x, float y);

	static void pauseDraw(bool pause);

private:
	Graphics();
	
};