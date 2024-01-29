#include "Color.h"
#include "WinApp.h"

#define WHITE 0x000000
#define BLACK 0xFFFFFF
#define RED 0x0000FF
#define GREEN 0x00FF00
#define BLUE 0xFF0000

HPEN Color::Pen = NULL;
HBRUSH Color::Brush = NULL;

void Color::SetWireframeColor(EColor color)
{
	

	switch (color)
	{
	case EColor::whiete:
		Pen = CreatePen(PS_SOLID, 1, WHITE);
		break;
		
	case EColor::black:
		Pen = CreatePen(PS_SOLID, 1, BLACK);
		break;

	case EColor::red:
		Pen = CreatePen(PS_SOLID, 1, RED);
		break;

	case EColor::green:
		Pen = CreatePen(PS_SOLID, 1, GREEN);
		break;

	case EColor::blue:
		Pen = CreatePen(PS_SOLID, 1, BLUE);
		break;

	default:
		Pen = CreatePen(PS_SOLID, 1, BLACK);
	}

	auto canvas = WinApp::GetCanvas();

	SelectObject(canvas.Device, Pen);
}

void Color::SetFaceColor(EColor color)
{
	switch (color)
	{
	case EColor::whiete:
		Brush = CreateSolidBrush(WHITE);
		break;

	case EColor::black:
		Brush = CreateSolidBrush(BLACK);
		break;

	case EColor::red:
		Brush = CreateSolidBrush(RED);
		break;

	case EColor::green:
		Brush = CreateSolidBrush(GREEN);
		break;

	case EColor::blue:
		Brush = CreateSolidBrush(BLUE);
		break;

	default:
		Brush = CreateSolidBrush(BLACK);
	}

	auto canvas = WinApp::GetCanvas();

	SelectObject(canvas.Device, Brush);
}