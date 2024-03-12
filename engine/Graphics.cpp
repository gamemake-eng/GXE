#include "Graphics.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
ALLEGRO_STATE Graphics::previous_state;
Graphics::Graphics()
{}

void Graphics::clearScreen(Color &color)
{
	al_clear_to_color(al_map_rgba(color.r,color.g,color.b,color.a));
}
void Graphics::drawCircle(Rect &pos, float r, Color &color)
{
	al_draw_filled_circle(pos.x,pos.y,r,al_map_rgba(color.r,color.g,color.b,color.a));
}

void Graphics::drawRect(Rect &rect, Color &color)
{
	al_draw_filled_rectangle(rect.x, rect.y, rect.x+rect.w, rect.y+rect.h, al_map_rgba(color.r, color.g, color.b, color.a));
}

void Graphics::drawLine(Rect &pos1, Rect &pos2, float w, Color &color)
{
	al_draw_line(pos1.x, pos1.y, pos2.x, pos2.y, al_map_rgba(color.r, color.g, color.b, color.a), w);
}


void Graphics::drawText(std::string text, float x, float y, Color &color, Font &font)
{
	al_draw_text(font.font, al_map_rgba(color.r,color.g,color.b,color.a), x, y, 0, text.c_str()); 
}
void Graphics::drawFancyText(std::string text,float x, float y, float maxwidth, Color &color, Font &font)
{
	al_draw_multiline_text(font.font, al_map_rgba(color.r,color.g,color.b,color.a), x, y, maxwidth, 29.2f, 0, text.c_str());
}


void Graphics::drawImage(Image &img, float x, float y)
{
	al_draw_tinted_scaled_rotated_bitmap_region(img.bitmap,
		//clip dimentions
		img.crop.x,img.crop.y,img.crop.w,img.crop.h,
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
void Graphics::drawRotatedImage(Image &img, float angle, Rect &origin, float x, float y)
{
	al_draw_tinted_scaled_rotated_bitmap_region(img.bitmap,
		//clip dimentions
		img.crop.x,img.crop.y,img.crop.w,img.crop.h,
		//tint
		al_map_rgb(255,255,255),
		//origin point
		origin.x,origin.y,
		//position
		x,y,
		//scale
		1, 1, 
		//angle and flags
		angle, 0);
}

void Graphics::drawView(Viewport &img, float x, float y)
{
	al_draw_bitmap(img.view, x,y,0);
}
void Graphics::setViewport(Viewport &view)
{
	al_set_target_bitmap(view.view);
}
void Graphics::restoreViewport()
{
	al_restore_state(&previous_state);
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

