#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Rect.h"
#pragma once
class Viewport
{
public:
	Viewport(Rect &rect);

	~Viewport();

	ALLEGRO_BITMAP* view;
	
	
};