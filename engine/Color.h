#pragma once
class Color
{
public:
	Color(float rc, float gc, float bc, float ac);
	float r;
	float g;
	float b;
	float a;

	static Color EyeStrainBlue;
	static Color MonogameBlue;
	static Color BloodShotRed;
	static Color ReallyGreen;
};