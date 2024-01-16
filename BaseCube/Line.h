#pragma once
#include "Shape.h"

class Line : public Shape
{
	class Vector3D start, end, offset;
	class Vector3D rotation;

public:
	Line(Vector3D start, Vector3D end);
	
	virtual void Draw(class Canvas canvas) override;
	virtual void Move(class Vector3D offset) override;
	virtual void Rotate(Vector3D rotator) override;

private:
	Vector3D find_middle_of_two_points(Vector3D start, Vector3D end);
};

