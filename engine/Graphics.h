#include "Color.h"
#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "../include/sol.hpp"
#include "Font.h"
#include "Color.h"
#include "Rect.h"
#include "Image.h"
#include "Viewport.h"
#pragma once 
class Graphics
{
public:
	static void clearScreen(Color &color);
	static void drawCircle(float x, float y, float r, Color &color);
	static void drawRect(Rect &rect, Color &color);
	static void drawText(std::string text,float x, float y, Color &color, Font &font);
	static void drawFancyText(std::string text,float x, float y, float maxwidth, Color &color, Font &font);


	static void drawImage(Image &img, float x, float y);
	static void drawView(Viewport &img, float x, float y);
	static void drawRotatedImage(Image &img, float angle, Rect &origin, float x, float y);

	static void setViewport(Viewport &view);
	static void restoreViewport();

	static void pauseDraw(bool pause);

	static ALLEGRO_STATE previous_state;

private:
	Graphics();
	
};