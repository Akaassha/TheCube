#include "Vector3D.h"
#include <cmath>

float Vector3D::GetLength() const
{
	return std::sqrt(x*x + y*y + z*z);
}

Vector3D Vector3D::GetRotatedVector(Vector3D rotator)
{
	float a = rotator.x;
	float b = rotator.y;
	float y = rotator.z;
	Vector3D out;

	out.x = this->x * (cos(a) * cos(b)) + this->y * (cos(a) * sin(b) * sin(y) - sin(a) * cos(y)) + this->z * (cos(a) * sin(b) * cos(y) + sin(a) * sin(y));
	out.y = this->x * (sin(a) * cos(b)) + this->y * (sin(a) * sin(b) * sin(y) + cos(a) * cos(y)) + this->z * (sin(a) * sin(b) * cos(y) - cos(a) * sin(y));
	out.z = this->x * (-sin(b)) + this->y* (sin(a) * cos(b)) + this->z *(cos(a) * cos(b));

	return out;
	
	//switch (axis)
	//{
	//	case Axis::X:
	//	{
	//		int new_x = x * cos(angle) - y * sin(angle);
	//		int new_y = x * sin(angle) + y * cos(angle);
	//		return Vector3D(new_x, new_y, z);
	//	}

	//	case Axis::Y:
	//	{
	//		int new_x =  x * cos(angle) + z * sin(angle);
	//		int new_z = -x * sin(angle) + z * cos(angle);
	//		return Vector3D(new_x, y, new_z);
	//	}

	//	case Axis::Z:
	//	{
	//		int new_y = y * cos(angle) - z * sin(angle);
	//		int new_z = y * sin(angle) + z * cos(angle);
	//		return Vector3D(x, new_y, new_z);
	//	}
	//}


}

