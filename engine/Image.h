#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <string>
#include "Rect.h"
#pragma once
class Image
{
public:
	Image(std::string path);
	~Image();

	ALLEGRO_BITMAP * bitmap;
	Rect crop;

	Rect source;
	
};