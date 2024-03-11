#include "Viewport.h"

Viewport::Viewport(Rect &rect)
{
	view = al_create_bitmap(rect.w, rect.h);
}

Viewport::~Viewport()
{
	al_destroy_bitmap(view);
}