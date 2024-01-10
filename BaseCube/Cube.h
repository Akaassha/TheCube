#pragma once
#include "Shape.h"
#include <vector>

class Cube : public Shape
{
	std::vector<Vector3D> corners;
	std::vector<Vector3D> rotated_corners;
	Vector3D center;
	int size;
	float rotation_x;
	float rotation_y;
	float rotation_z;

public:
	Cube(Vector3D center, int size);

	void Draw(class Canvas canvas) override;
	void Rotate(float angle, Axis axis);
};

