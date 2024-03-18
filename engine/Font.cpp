#include "Font.h"

Font::Font()
{
	font = al_create_builtin_font();
}
Font::Font(std::string path, int size)
{
	font = al_load_font(path.c_str(), size, 0);
}

Font::~Font()
{
	//printf("\ndestroying font");
	al_destroy_font(font);
}