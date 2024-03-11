#include "Camera.h"

Camera::Camera(float w, float h)
	: space(0,0,w,h), trans()
{
	zoom = 1;
	space.x = space.w;
	space.y = space.h;

}


void Camera::mount()
{
	//NOTE: Make it gay
	trans.pushTrans();

	trans.translate(space.x - (space.w/2) /zoom, space.y - (space.h/2)/zoom);
	trans.scale(zoom, zoom);


}
void Camera::unmount()
{
	trans.popTrans();
}
void Camera::centerOnTarget(Rect &t, float dt)
{
	float targetx = t.x;
	float targety = t.y;
	space.x = space.x + (targetx - space.x) * dt;
	space.y = space.y + (targety - space.y) * dt;

}