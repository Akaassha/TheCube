#pragma once
#include <Windows.h>
#include <vector>
#include "Vector3D.h"

class Canvas
{
	friend class Color;
	HDC Device;

public:
	Canvas(HWND windowHnadle);

	void DrawLine(Vector3D start, Vector3D end);
	void DrawSquare(Vector3D leftUp, Vector3D rightBottom);
	void DrawPolygon(std::vector<Vector3D> points) const; 
	void DrawCircle(Vector3D center, int radius);
};

