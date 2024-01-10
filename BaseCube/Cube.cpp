#include "Cube.h"
#include "Canvas.h"

Cube::Cube(Vector3D center, int size) : center{center}, size{size}
{
	size /= 0.5f;
	corners.push_back(Vector3D(center.x + size, center.y + size, center.z + size));
	corners.push_back(Vector3D(center.x + size, center.y - size, center.z + size));
	corners.push_back(Vector3D(center.x - size, center.y - size, center.z + size));
	corners.push_back(Vector3D(center.x - size, center.y + size, center.z + size));
	corners.push_back(Vector3D(center.x + size, center.y + size, center.z - size));
	corners.push_back(Vector3D(center.x + size, center.y - size, center.z - size));
	corners.push_back(Vector3D(center.x - size, center.y - size, center.z - size));
	corners.push_back(Vector3D(center.x - size, center.y + size, center.z - size));

	rotated_corners.insert(rotated_corners.begin(), corners.begin(), corners.end());

}

void Cube::Draw(Canvas canvas)
{
	MoveToEx(canvas.canvas_device, rotated_corners[3].x, rotated_corners[3].y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, rotated_corners[0].x, rotated_corners[0].y);
	LineTo(canvas.canvas_device, rotated_corners[1].x, rotated_corners[1].y);
	LineTo(canvas.canvas_device, rotated_corners[2].x, rotated_corners[2].y);
	LineTo(canvas.canvas_device, rotated_corners[3].x, rotated_corners[3].y);

	MoveToEx(canvas.canvas_device, rotated_corners[7].x, rotated_corners[7].y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, rotated_corners[4].x, rotated_corners[4].y);
	LineTo(canvas.canvas_device, rotated_corners[5].x, rotated_corners[5].y);
	LineTo(canvas.canvas_device, rotated_corners[6].x, rotated_corners[6].y);
	LineTo(canvas.canvas_device, rotated_corners[7].x, rotated_corners[7].y);

	MoveToEx(canvas.canvas_device, rotated_corners[0].x, rotated_corners[0].y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, rotated_corners[4].x, rotated_corners[4].y);
	MoveToEx(canvas.canvas_device, rotated_corners[1].x, rotated_corners[1].y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, rotated_corners[5].x, rotated_corners[5].y);
	MoveToEx(canvas.canvas_device, rotated_corners[2].x, rotated_corners[2].y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, rotated_corners[6].x, rotated_corners[6].y);
	MoveToEx(canvas.canvas_device, rotated_corners[3].x, rotated_corners[3].y, &canvas.LastDrawPosition);
	LineTo(canvas.canvas_device, rotated_corners[7].x, rotated_corners[7].y);

}

void Cube::Rotate(float angle, Axis axis)
{
	switch (axis)
	{
	case Axis::X:
		rotation_x += angle;
		break;
	case Axis::Y:
		rotation_y += angle;
		break;
	case Axis::Z:
		rotation_z += angle;
		break;
	}

	const Vector3D offset = center;
	angle = deg_to_radians(angle);

	rotated_corners.insert(rotated_corners.begin(), corners.begin(), corners.end());

	for (auto& corner : rotated_corners)
	{
		corner = corner - offset;
		corner = corner.GetRotatedVector(rotation_x, Axis::Z);
		corner = corner.GetRotatedVector(rotation_y, Axis::Y);
		corner = corner.GetRotatedVector(rotation_z, Axis::Z);
		corner = corner + offset;
	}
}