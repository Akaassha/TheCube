#pragma once
#include <Windows.h>

enum class EColor
{
	whiete,
	black,
	red,
	green,
	blue
};

class Color
{
	static HPEN Pen;
	static HBRUSH Brush;

public:
	static void SetWireframeColor(EColor color);
	static void SetFaceColor(EColor color);
	
};
