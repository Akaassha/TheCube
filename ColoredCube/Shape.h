#pragma once
#include "Vector3D.h"
#include "WinApp.h"
#include "Color.h"
#include "Canvas.h"

class Shape
{
protected:
	Shape() : canvas{ WinApp::GetCanvas() } {};
	const class Canvas canvas;

	Vector3D location;
	Vector3D rotation;
	Vector3D scale;
	EColor wireframeColor;
	EColor surfaceColor;

public:
	virtual void Draw() = 0;
	virtual void Move(Vector3D offset);
	virtual void Rotate(Vector3D rotator);
	virtual void SetScale(Vector3D newScale);

	void SetFrameColor(EColor newColor);
	void SetSurfaceColor(EColor newColor);
};

