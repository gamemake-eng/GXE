#include "Graphics.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

Graphics::Graphics()
{}

void Graphics::clearScreen(float r, float g, float b )
{
	al_clear_to_color(al_map_rgb(r,g,b));
}
