#include "Transform.h"

Transform::Transform()
{
	
}
void Transform::pushTrans()
{
	al_copy_transform(&originTrans, al_get_current_transform());
	al_identity_transform(&currTrans);
}
void Transform::translate(float x, float y)
{
	al_translate_transform(&currTrans, -x,-y);
	al_compose_transform(&currTrans, &originTrans);
	al_use_transform(&currTrans);
}
void Transform::scale(float x, float y)
{
	al_scale_transform(&currTrans, x,y);
	al_compose_transform(&currTrans, &originTrans);
	al_use_transform(&currTrans);
}
void Transform::popTrans()
{
	
	al_use_transform(&originTrans);

}
Transform::~Transform()
{}