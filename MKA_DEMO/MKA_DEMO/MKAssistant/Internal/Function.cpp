#include <Windows.h>
#include <ctime>
#include "../Class/RGBINFO.h"

INT IF_RandError(UINT nErrorLimit) {
	srand(time(NULL));
	return rand() % (nErrorLimit * 2 + 1) - nErrorLimit;
}

RGBINFO IF_GetRGBInfo(BYTE *pbyPic, BYTE byPic, LONG lWidthBytes, LONG lX, LONG lY) {
	RGBINFO rgbPic;
	rgbPic.nR = pbyPic[lX * byPic + lY * lWidthBytes + 2];
	rgbPic.nG = pbyPic[lX * byPic + lY * lWidthBytes + 1];
	rgbPic.nB = pbyPic[lX * byPic + lY * lWidthBytes + 0];
	rgbPic.bValid = TRUE;
	return rgbPic;
}

UINT IF_GetMouseDownUp(UINT &nDown, UINT &nUp, UINT nL0M1R2Button, BOOL bDoubleClick) {
	switch(nL0M1R2Button) {
	case 0:
		nDown = bDoubleClick ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN;
		nUp = WM_LBUTTONUP;
		break;
	case 1:
		nDown = bDoubleClick ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN;
		nUp = WM_MBUTTONUP;
		break;
	case 2:
		nDown = bDoubleClick ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN;
		nUp = WM_RBUTTONUP;
		break;
	default:
		break;
	}
	return 0;
}