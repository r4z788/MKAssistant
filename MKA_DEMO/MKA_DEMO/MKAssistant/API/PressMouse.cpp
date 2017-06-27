#include <Windows.h>
#include "../Internal/Function.h"
#include "PressMouse.h"

UINT PressMouse(INT nX, INT nY, UINT nErrorLimit, BOOL bDoubleClick, UINT nL0M1R2Button, DWORD dwSpan) {
	UINT nDown, nUp;
	IF_GetMouseDownUp(nDown, nUp, nL0M1R2Button, bDoubleClick);
	INT nError = IF_RandError(nErrorLimit);

	SetCursorPos(nX + nError, nY + nError);
	mouse_event(nDown, 0, 0, 0, 0);
	Sleep(dwSpan);
	mouse_event(nUp, 0, 0, 0, 0);
	return 0;
}

UINT PressMouse(LPCWSTR lpWindowName, INT nX, INT nY, UINT nErrorLimit, BOOL bDoubleClick, UINT nL0M1R2Button, DWORD dwSpan) {
	return PressMouse(FindWindow(NULL, lpWindowName), nX, nY, nErrorLimit, dwSpan, nL0M1R2Button, bDoubleClick);
}

UINT PressMouse(HWND hWindow, INT nX, INT nY, UINT nErrorLimit, BOOL bDoubleClick, UINT nL0M1R2Button, DWORD dwSpan) {
	UINT nDown, nUp;
	IF_GetMouseDownUp(nDown, nUp, nL0M1R2Button, bDoubleClick);
	INT nError = IF_RandError(nErrorLimit);

	SendMessage(hWindow, nDown, NULL, MAKELPARAM(nX + nError, nY + nError));
	Sleep(dwSpan);
	SendMessage(hWindow, nUp, NULL, MAKELPARAM(nX + nError, nY + nError));
	return 0;
}
