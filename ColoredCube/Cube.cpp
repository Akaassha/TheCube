#include "Cube.h"
#include "WinApp.h"
#include <algorithm>

Cube::Cube(Vector3D location, float size)
{
	scale.x = size;
	scale.y = size;
	scale.z = size;

	this->location = location;
	wireframeColor = EColor::red;
	surfaceColor = EColor::green;

}

void Cube::Draw()
{
	Color::SetWireframeColor(wireframeColor);
	Color::SetFaceColor(surfaceColor);

	std::vector<std::vector<Vector3D>> cube = {
		createFace(ESide::front),
		createFace(ESide::behind),
		createFace(ESide::up),
		createFace(ESide::bottom),
		createFace(ESide::left),
		createFace(ESide::right)
	};

	for (auto& side : cube)
	{
		for(auto& p : side)
			p = p.rotate(rotation) + location;
	}	

	auto face1 = SelectVisibleFace(cube[0], cube[1]);
	auto face2 = SelectVisibleFace(cube[2], cube[3]);
	auto face3 = SelectVisibleFace(cube[4], cube[5]);

	canvas.DrawPolygon(face1);
	canvas.DrawPolygon(face2);
	canvas.DrawPolygon(face3);

}

std::vector<Vector3D> Cube::SelectVisibleFace(std::vector<Vector3D>& faceA,std::vector<Vector3D>& faceB) const
{
	float distance1 = (faceA[0] + ((faceA[3] - faceA[0]) / 2)).z;
	float distance2 = (faceB[0] + ((faceB[3] - faceB[0]) / 2)).z;

	if (distance1 <  distance2)
		return faceB;
	else
		return faceA;
}

std::vector<Vector3D> Cube::createFace(ESide side)
{
	Vector3D p1, p2, p3, p4;
	std::vector<Vector3D> points;

	switch (side)
	{
	case ESide::behind:
	{
		p1 = Vector3D{ (-scale.x), (-scale.y), (-scale.z) };
		p2 = Vector3D{ ( scale.x), (-scale.y), (-scale.z) };
		p3 = Vector3D{ ( scale.x), ( scale.y), (-scale.z) };
		p4 = Vector3D{ (-scale.x), ( scale.y), (-scale.z) };
		points = { p1, p2, p3, p4 };
		break;
	}

	case ESide::front:
	{
		p1 = Vector3D{ (-scale.x), (-scale.y), (scale.z) };
		p2 = Vector3D{ ( scale.x), (-scale.y), (scale.z) };
		p3 = Vector3D{ ( scale.x), (scale.y),  (scale.z) };
		p4 = Vector3D{ (-scale.x), (scale.y),  (scale.z) };
		points = { p1, p2, p3, p4 };
		break;
	}
	case ESide::left:
	{
		p1 = Vector3D{ (-scale.x), (-scale.y), ( scale.z) };
		p2 = Vector3D{ (-scale.x), (-scale.y), (-scale.z) };
		p3 = Vector3D{ (-scale.x), ( scale.y), (-scale.z) };
		p4 = Vector3D{ (-scale.x), ( scale.y), ( scale.z) };
		points = { p1, p2, p3, p4 };
		break;
	}
	case ESide::right:
	{
		p1 = Vector3D{ (scale.x), (-scale.y), ( scale.z) };
		p2 = Vector3D{ (scale.x), (-scale.y), (-scale.z) };
		p3 = Vector3D{ (scale.x), ( scale.y), (-scale.z) };
		p4 = Vector3D{ (scale.x), ( scale.y), ( scale.z) };
		points = { p1, p2, p3, p4 };
		break;
	}

	case ESide::up:
	{
		p1 = Vector3D{ (-scale.x), (-scale.y), ( scale.z) };
		p2 = Vector3D{ (scale.x),  (-scale.y), ( scale.z) };
		p3 = Vector3D{ (scale.x),  (-scale.y), (-scale.z) };
		p4 = Vector3D{ (-scale.x), (-scale.y), (-scale.z) };
		points = { p1, p2, p3, p4 };
		break;
	}
	case ESide::bottom:
	{
		p1 = Vector3D{ (-scale.x), (scale.y), ( scale.z) };
		p2 = Vector3D{ ( scale.x), (scale.y), ( scale.z) };
		p3 = Vector3D{ ( scale.x), (scale.y), (-scale.z) };
		p4 = Vector3D{ (-scale.x), (scale.y), (-scale.z) };
		points = { p1, p2, p3, p4 };
		break;
	}
	}


	return points;
}