#pragma once
#include <cmath>

struct Vector3D
{
	float x, y, z;
	Vector3D() : x{ 0 }, y{ 0 }, z{ 0 } {};
	Vector3D(float x, float y, float z) : x{ x }, y{ y }, z{ z } {};

	const Vector3D& operator+(const Vector3D v2) const { return Vector3D{x+v2.x, y+v2.y, z+v2.z}; } ;
	const Vector3D& operator-(const Vector3D v2) const { return Vector3D{x-v2.x, y-v2.y, z-v2.z}; };
	Vector3D operator+=(Vector3D v2) { return Vector3D{x=x+v2.x, y=y+v2.y, z=z+v2.z}; };
	Vector3D operator-=(Vector3D v2) { return Vector3D{x=x-v2.x, y=y-v2.y, z=z-v2.z}; };
	const Vector3D& operator/(float d) const { return Vector3D{x/d,y/d,z/d}; };
	float getLength() { return sqrt(x * x + y * y + z * z); };
	Vector3D rotate(Vector3D rotator);
};

