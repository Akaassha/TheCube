#include "Vector3D.h"
#include <cmath>

float Vector3D::GetLength() const
{
	return std::sqrt(x*x + y*y + z*z);
}

Vector3D Vector3D::GetRotatedVector(float angle, Axis axis)
{
	switch (axis)
	{
		case Axis::X:
		{
			int new_x = x * cos(angle) - y * sin(angle);
			int new_y = x * sin(angle) + y * cos(angle);
			return Vector3D(new_x, new_y, z);
		}

		case Axis::Y:
		{
			int new_x =  x * cos(angle) + z * sin(angle);
			int new_z = -x * sin(angle) + z * cos(angle);
			return Vector3D(new_x, y, new_z);
		}

		case Axis::Z:
		{
			int new_y = y * cos(angle) - z * sin(angle);
			int new_z = y * sin(angle) + z * cos(angle);
			return Vector3D(x, new_y, new_z);
		}
	}
}

