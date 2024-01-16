#pragma once
#include "Vector3D.h"

class Shape
{
public:
	virtual void Draw(class Canvas canvas) = 0;
	virtual void Move(Vector3D offset) = 0;
	virtual void Rotate(Vector3D rotator) = 0;

protected:
	float deg_to_radians(float angle);
};

