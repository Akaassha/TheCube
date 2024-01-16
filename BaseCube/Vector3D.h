#pragma once

enum class Axis
{
	X, Y, Z
};

class Vector3D
{

public:
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3D(float x = 0, float y = 0, float z = 0) : x{ x }, y{ y }, z{ z } {}

	inline float GetLength() const;
	Vector3D GetRotatedVector(Vector3D rotator);

	Vector3D operator-(Vector3D p2) { return Vector3D(p2.x - x, p2.y - y, p2.z - z); }
	Vector3D operator+(Vector3D p2) { return Vector3D(p2.x + x, p2.y + y, p2.z + z); }
	Vector3D operator+=(Vector3D p2) { return Vector3D(p2.x + x, p2.y + y, p2.z + z); }
	Vector3D operator-=(Vector3D p2) { return Vector3D(p2.x - x, p2.y - y, p2.z - z); }
};