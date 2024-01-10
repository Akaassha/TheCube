#pragma once
#include "Vector3D.h"

class Shape
{
public:
	virtual void Draw(class Canvas canvas) = 0;
	virtual void Rotate(float angle, Axis axis) = 0;

protected:
	float deg_to_radians(float angle);
};

