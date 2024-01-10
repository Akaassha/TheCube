#include "WinApp.h"
#include "Canvas.h"
#include "Vector3D.h"
#include "Cube.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	WinApp app(instance);
	Canvas canvas(app.GetWindowHandle());

	//const Vector3D cube_location(150, 150, 0);
	//const int cube_side_size = 25;
	//Cube* cube = new Cube(cube_location, cube_side_size);

	//cube->Rotate(25.0f, Axis::Y);
	//cube->Rotate(25.0f, Axis::Z);
	//canvas.Draw(cube);

	app.Run();
}