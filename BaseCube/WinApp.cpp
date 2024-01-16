#include "WinApp.h"
#include "Vector3D.h"
#include "Cube.h"
#include "Line.h"
#include "Canvas.h"

static HWND WindowHandle;
static WNDCLASS WindowClass;
static HINSTANCE WindowInstance;
const LPCWSTR WIN_CLASS_NAME = TEXT("WIN_CLASS");
const LPCWSTR APP_TITLE = TEXT("APP_TITLE");
const DWORD WINDOWED_STYLE = WS_POPUP | WS_CAPTION;

WinApp::WinApp(HINSTANCE instance)
{
	WindowInstance = instance;

	make_window_class(WindowClass);
	RegisterClass(&WindowClass);
	make_handle_to_window(WindowHandle);

	ShowWindow(WindowHandle, SW_SHOWNORMAL);
}

void WinApp::make_window_class(WNDCLASS& winClass)
{
	winClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hInstance = WindowInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = WIN_CLASS_NAME;
	winClass.lpfnWndProc = &WinProc;
}

void WinApp::make_handle_to_window(HWND& HanleToWindow)
{
	HanleToWindow = CreateWindow(
		WIN_CLASS_NAME,             /*Class name*/
		APP_TITLE,       /*Window Title*/
		WINDOWED_STYLE,                /*Window Style*/
		0,                 /*X Starting pos*/
		0,                 /*Y Starting Pos*/
		600,				/*Width*/
		400,				/*Height*/
		0,                      /*Parent Window*/
		0,                      /*Menu*/
		WindowInstance,    /*HInstance*/
		0                       /*Lparam This will be available in WM_CREATE*/
	);
}

void WinApp::Run()
{
	const Vector3D cube_location(150, 150, 0);
	const int cube_side_size = 25;

	Cube* cube = new Cube(cube_location, cube_side_size);
	Cube* cube1 = new Cube(Vector3D(250, 150, 0), cube_side_size);
	Cube* cube2 = new Cube(Vector3D(350, 150, 0), cube_side_size);
	Canvas canvas(GetWindowHandle());

	//cube->Rotate(25.0f, Axis::Y);
	//cube->Rotate(25.0f, Axis::Z);
	//canvas.Draw(cube);

	//Line line(Vector3D{10, 10, 10}, Vector3D{100, 100, 100});
	//line.Draw(canvas);

	while (true)
	{
		InvalidateRect(GetWindowHandle(), NULL, TRUE);
		//line.Rotate(Vector3D{1, 1, 1});
		//line.Draw(canvas);

		cube->Rotate(Vector3D{ 0, 0.1, 0.1 });
		cube->SetScale(Vector3D{ 100, 100, 100 });
		cube1->Rotate(Vector3D{ 0, 0.1, 0.1 });
		cube2->Rotate(Vector3D{ 0, 0.1, 0.1 });

		canvas.Draw(cube);
		canvas.Draw(cube1);
		canvas.Draw(cube2);

		Sleep(50);


		ProcessMessages();
	}
}

HWND& WinApp::GetWindowHandle()
{
	return WindowHandle;
}

void WinApp::ProcessMessages(void)
{
	MSG msg;
	while (PeekMessage(&msg, WindowHandle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WinApp::WinProc(HWND win, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	default:
		return DefWindowProc(win, msg, wp, lp);
	}

	return 0;
}