#include <Windows.h>
#include "PressKeyboard.h"

UINT PressKeyboard(WORD wKey, UINT nC0D1U2) {
	if(nC0D1U2 == 0) {
		PressKeyboard(wKey, 1);
		PressKeyboard(wKey, 2);
		return 0;
	}
	INPUT ipKeyboard[1];
	ZeroMemory(&ipKeyboard, sizeof(INPUT));
	ipKeyboard[0].type = INPUT_KEYBOARD;
	ipKeyboard[0].ki.wVk = wKey;
	if(nC0D1U2 == 2) {
		ipKeyboard[0].ki.dwFlags = KEYEVENTF_KEYUP;
	}
	SendInput(1, ipKeyboard, sizeof(INPUT));
	return 0;
}

UINT PressKeyboard(LPCWSTR lpWindowName, WORD wKey, UINT nC0D1U2) {
	return PressKeyboard(FindWindow(NULL, lpWindowName), wKey, nC0D1U2);
}

UINT PressKeyboard(HWND hWindow, WORD wKey, UINT nC0D1U2) {
	SwitchToThisWindow(hWindow, TRUE);
	return PressKeyboard(wKey, nC0D1U2);
}