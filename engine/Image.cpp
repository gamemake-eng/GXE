#include "Image.h"

Image::Image(std::string path)
{
	bitmap = al_load_bitmap(path.c_str());
}

Image::~Image()
{
	al_destroy_bitmap(bitmap); 
}