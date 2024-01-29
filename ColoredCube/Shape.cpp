#include "Shape.h"
#include "WinApp.h"

void Shape::Move(Vector3D offset)
{
	location += offset;
}

void Shape::Rotate(Vector3D rotator)
{
	rotation += rotator;
}

void Shape::SetScale(Vector3D newScale)
{
	scale = newScale;
}

void Shape::SetFrameColor(EColor newColor)
{
	wireframeColor = newColor;
}

void Shape::SetSurfaceColor(EColor newColor)
{
	surfaceColor = newColor;
}
