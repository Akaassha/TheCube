#pragma once

enum class Axis
{
	X, Y, Z
};

class Vector3D
{

public:
	int x = 0;
	int y = 0;
	int z = 0;

	Vector3D(int x = 0, int y = 0, int z = 0) : x{ x }, y{ y }, z{ z } {}

	inline float GetLength() const;
	Vector3D GetRotatedVector(float angle, Axis axis);

	Vector3D operator-(Vector3D p2) { return Vector3D(p2.x - x, p2.y - y, p2.z - z); }
	Vector3D operator+(Vector3D p2) { return Vector3D(p2.x + x, p2.y + y, p2.z + z); }
};