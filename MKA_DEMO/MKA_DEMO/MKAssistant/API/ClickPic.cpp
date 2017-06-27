#include <Windows.h>
#include "../Class/POSITION.h"
#include "ClickPic.h"
#include "FindPic.h"
#include "GetPic.h"
#include "PressMouse.h"

UINT ClickPic(HBITMAP hbmSmall, INT nAddX, INT nAddY, UINT nStep, UINT nErrorLimit, BOOL bDoubleClick, UINT nL0M1R2Button, DWORD dwSpan) {
	HBITMAP hbmDesktop = GetPic();
	POSITION cPic = FindPic(hbmSmall, hbmDesktop, nStep);
	if(cPic.bValid == FALSE) {
		return 1;
	}
	return PressMouse(cPic.lX + nAddX, cPic.lY + nAddY, nErrorLimit, bDoubleClick, nL0M1R2Button, dwSpan);
}

UINT ClickPic(LPCWSTR lpWindowName, HBITMAP hbmSmall, INT nAddX, INT nAddY, UINT nStep, UINT nErrorLimit, BOOL bDoubleClick, UINT nL0M1R2Button, DWORD dwSpan) {
	return ClickPic(FindWindow(NULL, lpWindowName), hbmSmall, nAddX, nAddY, nStep, nErrorLimit, bDoubleClick, nL0M1R2Button, dwSpan);
}

UINT ClickPic(HWND hWindow, HBITMAP hbmSmall, INT nAddX, INT nAddY, UINT nStep, UINT nErrorLimit, BOOL bDoubleClick, UINT nL0M1R2Button, DWORD dwSpan) {
	HBITMAP hbmLarge = GetPic(hWindow);
	POSITION cPic = FindPic(hbmSmall, hbmLarge, nStep);
	if(cPic.bValid == FALSE) {
		return 1;
	}
	return PressMouse(hWindow, cPic.lX + nAddX, cPic.lY + nAddY, nErrorLimit, bDoubleClick, nL0M1R2Button, dwSpan);
}
