#include "Line.h"
#include "Vector3D.h"
#include "Canvas.h"

Line::Line(Vector3D start, Vector3D end) : rotation{0, 0, 0}
{
	offset = find_middle_of_two_points(start, end);
	this->start = start - offset;
	this->end = end - offset;
}

void Line::Draw(Canvas canvas)
{
	Vector3D StartDrawPoin = start;
	Vector3D EndDrawPoin = end;

	StartDrawPoin = StartDrawPoin.GetRotatedVector(rotation);
	EndDrawPoin = EndDrawPoin.GetRotatedVector(rotation);

	StartDrawPoin = StartDrawPoin + offset;
	EndDrawPoin = EndDrawPoin + offset;

	MoveToEx(canvas.canvas_device, StartDrawPoin.x, StartDrawPoin.y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, EndDrawPoin.x, EndDrawPoin.y);
}

void Line::Move(Vector3D offset)
{
	this->offset =  offset;
}

void Line::Rotate(Vector3D rotator)
{
	rotation = rotation + rotator;
}

Vector3D Line::find_middle_of_two_points(Vector3D start, Vector3D end)
{
	float dX = ((end.x - start.x) /2) + start.x;
	float dY = ((end.y - start.y) /2) + start.y;
	float dZ = ((end.z - start.z) /2) + start.z;

	return Vector3D{dX, dY, dZ };
}
