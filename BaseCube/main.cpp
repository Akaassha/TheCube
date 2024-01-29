#include "WinApp.h"
#include "Canvas.h"
#include "Vector3D.h"
#include "Cube.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	WinApp app(instance);
	Canvas canvas(app.GetWindowHandle());

	app.Run();
}