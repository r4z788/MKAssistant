#include <Windows.h>
#include "../Class/POSITION.h"
#include "../Class/RGBINFO.h"
#include "../Internal/Function.h"

POSITION FindPic(HBITMAP hbmSmall, HBITMAP hbmLarge, UINT nStep) {
	HDC hDCSmall = CreateCompatibleDC(NULL);
	HDC hDCLarge = CreateCompatibleDC(NULL);
	SelectObject(hDCSmall, hbmSmall);
	SelectObject(hDCLarge, hbmLarge);
	BITMAP bmSmall;
	BITMAP bmLarge;
	GetObject(hbmSmall, sizeof(BITMAP), &bmSmall);
	GetObject(hbmLarge, sizeof(BITMAP), &bmLarge);
	BYTE bySmall = bmSmall.bmBitsPixel / 8;
	BYTE byLarge = bmLarge.bmBitsPixel / 8;
	BITMAPINFO biSmall;
	BITMAPINFO biLarge;
	biSmall.bmiHeader.biSize = sizeof(biSmall.bmiHeader);
	biLarge.bmiHeader.biSize = sizeof(biLarge.bmiHeader);
	biSmall.bmiHeader.biWidth = bmSmall.bmWidth;
	biLarge.bmiHeader.biWidth = bmLarge.bmWidth;
	biSmall.bmiHeader.biHeight = -bmSmall.bmHeight;
	biLarge.bmiHeader.biHeight = -bmLarge.bmHeight;
	biSmall.bmiHeader.biPlanes = 1;
	biLarge.bmiHeader.biPlanes = 1;
	biSmall.bmiHeader.biBitCount = bmSmall.bmBitsPixel;
	biLarge.bmiHeader.biBitCount = bmLarge.bmBitsPixel;
	biSmall.bmiHeader.biCompression = BI_RGB;
	biLarge.bmiHeader.biCompression = BI_RGB;
	biSmall.bmiHeader.biSizeImage = (bmSmall.bmWidth * biSmall.bmiHeader.biBitCount + 31) / 32 * 4 * bmSmall.bmHeight;
	biLarge.bmiHeader.biSizeImage = (bmLarge.bmWidth * biLarge.bmiHeader.biBitCount + 31) / 32 * 4 * bmLarge.bmHeight;
	BYTE* pbySmall = new BYTE[biSmall.bmiHeader.biSizeImage];
	BYTE* pbyLarge = new BYTE[biLarge.bmiHeader.biSizeImage];
	ZeroMemory(pbySmall, biSmall.bmiHeader.biSizeImage);
	ZeroMemory(pbyLarge, biLarge.bmiHeader.biSizeImage);
	GetDIBits(hDCSmall, hbmSmall, 0, bmSmall.bmHeight, pbySmall, &biSmall, DIB_RGB_COLORS);
	GetDIBits(hDCLarge, hbmLarge, 0, bmLarge.bmHeight, pbyLarge, &biLarge, DIB_RGB_COLORS);
	LONG lSmallWidth = bmSmall.bmWidth - nStep;
	LONG lLargeWidth = bmLarge.bmWidth - lSmallWidth - 1;
	LONG lSmallHeight = bmSmall.bmHeight - nStep;
	LONG lLargeHeigh = bmLarge.bmHeight - lSmallHeight - 1;
	POSITION cResult;
	RGBINFO rgbSmall = IF_GetRGBInfo(pbySmall, bySmall, bmSmall.bmWidthBytes, 0, 0);
	for(LONG lLargeX = 0; lLargeX <= lLargeWidth; lLargeX++) {
		for(LONG lLargeY = 0; lLargeY <= lLargeHeigh; lLargeY++) {
			RGBINFO rgbLarge = IF_GetRGBInfo(pbyLarge, byLarge, bmLarge.bmWidthBytes, lLargeX, lLargeY);
			if(rgbSmall == rgbLarge) {
				for(LONG lSmallX2 = 1; lSmallX2 <= lSmallWidth; lSmallX2 += nStep) {
					for(LONG lSmallY2 = 1; lSmallY2 <= lSmallHeight; lSmallY2 += nStep) {
						RGBINFO rgbSmall2 = IF_GetRGBInfo(pbySmall, bySmall, bmSmall.bmWidthBytes, lSmallX2, lSmallY2);
						RGBINFO rgbLarge2 = IF_GetRGBInfo(pbyLarge, byLarge, bmLarge.bmWidthBytes, lLargeX + lSmallX2, lLargeY + lSmallY2);
						if(rgbSmall2 != rgbLarge2) {
							break;
						}
						else if(lSmallX2 + nStep > lSmallWidth && lSmallY2 + nStep > lSmallHeight) {
							cResult.lX = lLargeX;
							cResult.lY = lLargeY;
							cResult.bValid = TRUE;
							DeleteDC(hDCSmall);
							DeleteDC(hDCLarge);
							delete[] pbySmall;
							delete[] pbyLarge;
							pbySmall = NULL;
							pbyLarge = NULL;
							return cResult;
						}
					}
				}
			}
		}
	}
	DeleteDC(hDCSmall);
	DeleteDC(hDCLarge);
	delete[] pbySmall;
	delete[] pbyLarge;
	pbySmall = NULL;
	pbyLarge = NULL;
	return cResult;
	POSITION aaa;
	return aaa;
}