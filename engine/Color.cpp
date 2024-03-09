#include "Color.h"

Color::Color(float rc, float gc, float bc, float ac)
{
	r=rc;
	b=bc;
	g=gc;
	a=ac;
}

Color Color::EyeStrainBlue(0,0,255,255);
Color Color::MonogameBlue(100, 149, 237,255);
Color Color::BloodShotRed(255,0,0,255);
Color Color::ReallyGreen(0,255,0,255);