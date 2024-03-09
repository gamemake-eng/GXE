#include "Graphics.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

Graphics::Graphics()
{}

void Graphics::clearScreen(Color &color)
{
	al_clear_to_color(al_map_rgba(color.r,color.g,color.b,color.a));
}
void Graphics::drawCircle(float x, float y, float r, Color &color)
{
	al_draw_filled_circle(x,y,r,al_map_rgba(color.r,color.g,color.b,color.a));
}

void Graphics::drawRect(Rect &rect, Color &color)
{
	al_draw_filled_rectangle(rect.x, rect.y, rect.x+rect.w, rect.y+rect.h, al_map_rgba(color.r, color.g, color.b, color.a));
}


void Graphics::drawText(std::string text, float x, float y, Color &color, Font &font)
{
	al_draw_text(font.font, al_map_rgba(color.r,color.g,color.b,color.a), x, y, 0, text.c_str()); 
}

void Graphics::drawImage(Image &img, float x, float y)
{
	al_draw_bitmap(img.bitmap, x, y, 0);  	
}
void Graphics::drawCropImage(Image &img, Rect &source, float x, float y)
{
	al_draw_tinted_scaled_rotated_bitmap_region(img.bitmap,
		//clip dimentions
		source.x,source.y,source.w,source.h,
		//tint
		al_map_rgb(255,255,255),
		//origin point
		0,0,
		//position
		x,y,
		//scale
		1, 1, 
		//angle and flags
		0, 0);
}

void Graphics::pauseDraw(bool pause)
{
	if (pause)
	{
		al_hold_bitmap_drawing(1);
	}else
	{
		al_hold_bitmap_drawing(0);
	}
}

