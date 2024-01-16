#pragma once
#include <Windows.h>

class Canvas
{
public:
	Canvas(HWND& WindowsHandle );
	~Canvas();

	void Draw(class Shape* shape);

	friend class Line;
	friend class Square;
	friend class Cube;
private:
	HDC canvas_device;
	POINT LastDrawPosition;
	POINT Point_to_WinPOINT(class Vector3D);
};