#include <Windows.h>
#include "WinApp.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	WinApp app(instance);
	WinApp::Run();
}