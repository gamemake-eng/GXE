#include "Graphics.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

Graphics::Graphics()
{}

void Graphics::clearScreen(Color &color)
{
	al_clear_to_color(al_map_rgba(color.r,color.g,color.b,color.a));
}
