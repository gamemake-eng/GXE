#include "Image.h"

Image::Image(std::string path)
	: crop(0,0,0,0), source(0,0,0,0)
{
	bitmap = al_load_bitmap(path.c_str());
	crop.x = 0;
	crop.y = 0;
	crop.w = al_get_bitmap_width(bitmap);
    crop.h = al_get_bitmap_height(bitmap);

    source.x = 0;
	source.y = 0;
	source.w = al_get_bitmap_width(bitmap);
    source.h = al_get_bitmap_height(bitmap);
}

Image::~Image()
{
	al_destroy_bitmap(bitmap); 
}