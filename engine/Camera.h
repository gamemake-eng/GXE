#include "Transform.h"
#include "Rect.h"
#pragma once
class Camera
{
public:
	Camera(float w, float h);

	void mount();
	void unmount();

	void centerOnTarget(Rect &t, float dt);

	Rect space;
	float zoom;

	Transform trans;
	
};