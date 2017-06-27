#include <ShellScalingAPI.h>
#include <tchar.h>
#include <Windows.h>
#include "MKAssistant\MKAssistant.h"
#pragma comment(lib,"Shcore.lib")

INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, INT iCmdShow) {
	SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
	SavePic(L"MKA_DEMO",L"a.jpg");
	return 0;
}