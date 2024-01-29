#include "Canvas.h"

Canvas::Canvas(HWND windowHnadle)
{
	Device = GetDC(windowHnadle);

}

void Canvas::DrawLine(Vector3D start, Vector3D end)
{
	MoveToEx(Device, start.x, start.y, NULL);
	LineTo(Device, end.x, end.y);
}

void Canvas::DrawSquare(Vector3D leftUp, Vector3D rightBottom)
{

}

void Canvas::DrawPolygon(std::vector<Vector3D> points) const
{
	int cornersAmount = points.size();
	POINT* polyPoints = new POINT[cornersAmount];

	for (int i = 0; i < cornersAmount; ++i)
	{
		POINT p;
		p.x = points[i].x;
		p.y = points[i].y;
		polyPoints[i] = p;
	}

	Polygon(Device, polyPoints, cornersAmount);
}

void Canvas::DrawCircle(Vector3D center, int radius)
{

}