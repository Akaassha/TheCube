#include "Vector3D.h"

Vector3D Vector3D::rotate(Vector3D rotator)
{
	float a = rotator.x;
	float b = rotator.y;
	float y = rotator.z;
	Vector3D out;

	out.x = this->x * (cos(a) * cos(b)) + this->y * (cos(a) * sin(b) * sin(y) - sin(a) * cos(y)) + this->z * (cos(a) * sin(b) * cos(y) + sin(a) * sin(y));
	out.y = this->x * (sin(a) * cos(b)) + this->y * (sin(a) * sin(b) * sin(y) + cos(a) * cos(y)) + this->z * (sin(a) * sin(b) * cos(y) - cos(a) * sin(y));
	out.z = this->x * (-sin(b)) + this->y * (sin(a) * cos(b)) + this->z * (cos(a) * cos(b));

	return out;
}