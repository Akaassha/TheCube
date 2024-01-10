#include "Canvas.h"
#include "Vector3D.h"
#include "Shape.h"

Canvas::Canvas(HWND& WindowsHandle)
{
	canvas_device = GetDC(WindowsHandle);
}

void Canvas::Draw(Shape* shape)
{
	shape->Draw(*this);
}

Canvas::~Canvas()
{

}

POINT Canvas::Point_to_WinPOINT(Vector3D point)
{
	POINT WinPoint;
	WinPoint.x = point.x;
	WinPoint.y = point.y;

	return WinPoint;
}