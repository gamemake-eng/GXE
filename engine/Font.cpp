#include "Font.h"
#include <stdio.h>
Font::Font()
{
	font = al_create_builtin_font();
}
Font::Font(std::string path, int size)
{
	font = al_load_font(path.c_str(), size, 0);
}
void Font::Draw(std::string text, float x, float y)
{
	al_draw_text(font, al_map_rgb(255,255,255), x, y, 0, text.c_str()); 
}
Font::~Font()
{
	printf("destroying font");
	al_destroy_font(font);
}