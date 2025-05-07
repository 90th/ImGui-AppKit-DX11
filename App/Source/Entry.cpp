#include <Windows.h>
#include "Render.h"
int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
	Render::Loop();
	return 0;
}