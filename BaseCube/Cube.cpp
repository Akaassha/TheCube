#include "Cube.h"
#include "Canvas.h"
#include "Line.h"

Cube::Cube(Vector3D center, int size) : location{center}, rotation{0, 0, 0}
{
	scale.x = size;
	scale.y = size;
	scale.z = size;
}

void Cube::Draw(Canvas canvas)
{
	float half_size_x = scale.x / 2;
	float half_size_y = scale.y / 2;
	float half_size_z = scale.z / 2;
	std::vector<Vector3D> points;

	points.push_back(Vector3D{ +1 * half_size_x, +1 * half_size_y, +1 * half_size_z });
	points.push_back(Vector3D{ -1 * half_size_x, +1 * half_size_y, +1 * half_size_z });
	points.push_back(Vector3D{ -1 * half_size_x, -1 * half_size_y, +1 * half_size_z });
	points.push_back(Vector3D{ +1 * half_size_x, -1 * half_size_y, +1 * half_size_z });
									 								  
	points.push_back(Vector3D{ +1 * half_size_x, +1 * half_size_y, -1 * half_size_z });
	points.push_back(Vector3D{ -1 * half_size_x, +1 * half_size_y, -1 * half_size_z });
	points.push_back(Vector3D{ -1 * half_size_x, -1 * half_size_y, -1 * half_size_z });
	points.push_back(Vector3D{ +1 * half_size_x, -1 * half_size_y, -1 * half_size_z });

	std::vector<Vector3D> rotatedPoints;
	for (auto point : points)
	{
		rotatedPoints.push_back(point.GetRotatedVector(rotation) + location);
	}

	Line line1(rotatedPoints[0], rotatedPoints[1]);
	Line line2(rotatedPoints[1], rotatedPoints[2]);
	Line line3(rotatedPoints[2], rotatedPoints[3]);
	Line line4(rotatedPoints[3], rotatedPoints[0]);

	Line line5(rotatedPoints[4], rotatedPoints[5]);
	Line line6(rotatedPoints[5], rotatedPoints[6]);
	Line line7(rotatedPoints[6], rotatedPoints[7]);
	Line line8(rotatedPoints[7], rotatedPoints[4]);

	Line line9(rotatedPoints[0], rotatedPoints[4]);
	Line line10(rotatedPoints[1], rotatedPoints[5]);
	Line line11(rotatedPoints[2], rotatedPoints[6]);
	Line line12(rotatedPoints[3], rotatedPoints[7]);

	line1.Draw(canvas);
	line2.Draw(canvas);
	line3.Draw(canvas);
	line4.Draw(canvas);

	line5.Draw(canvas);
	line6.Draw(canvas);
	line7.Draw(canvas);
	line8.Draw(canvas);

	line9.Draw(canvas);
	line10.Draw(canvas);
	line11.Draw(canvas);
	line12.Draw(canvas);
}

void Cube::Rotate(Vector3D rotator)
{
	rotation = rotation + rotator;
}

void Cube::Move(Vector3D offset)
{
	location = location + offset;
}

void Cube::SetScale(Vector3D newScale)
{
	scale = newScale;
}