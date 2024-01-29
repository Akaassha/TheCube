#pragma once
#include "Shape.h"
#include <vector>

class Cube :public Shape
{
	enum class ESide
	{
		front,
		behind,
		left,
		right,
		bottom,
		up
	};

	std::vector<Vector3D> SelectVisibleFace(std::vector<Vector3D>& faceA, std::vector<Vector3D>& faceB) const;
	std::vector<Vector3D> createFace(ESide side);

public:
	Cube(Vector3D location, float size);
	void Draw() override;
};

