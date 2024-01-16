#pragma once
#include "Shape.h"
#include <vector>

class Cube : public Shape
{
	Vector3D location;
	Vector3D rotation;
	Vector3D scale;

public:
	Cube(Vector3D center, int size);

	void Draw(class Canvas canvas) override;
	void Rotate(Vector3D rotator) override;
	void Move(Vector3D offset) override;

	void SetScale(Vector3D newScale);
};

