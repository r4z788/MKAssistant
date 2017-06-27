#include <Windows.h>
#include "GetPic.h"

HBITMAP GetPic() {
	//��ȡ���洰�ھ��
	HWND hWndDesktop = GetDesktopWindow();
	//��ȡ���洰��DC
	HDC hDCDesktop = GetWindowDC(hWndDesktop);
	RECT rectWindow;
	GetClientRect(hWndDesktop, &rectWindow);
	//��ȡ��ǰ���ڵ�λͼ  
	HDC hDCMemory = CreateCompatibleDC(hDCDesktop);
	HBITMAP hBitmapPic;
	hBitmapPic = CreateCompatibleBitmap(hDCDesktop, rectWindow.right, rectWindow.bottom);
	SelectObject(hDCMemory, hBitmapPic);
	BitBlt(hDCMemory, 0, 0, rectWindow.right, rectWindow.bottom, hDCDesktop, 0, 0, SRCCOPY);
	ReleaseDC(NULL, hDCDesktop);
	ReleaseDC(NULL, hDCMemory);
	DeleteDC(hDCDesktop);
	DeleteDC(hDCMemory);
	return hBitmapPic;
}

HBITMAP   GetPic(LPCWSTR lpWindowName) {
	return GetPic(FindWindow(NULL, lpWindowName));;
}

HBITMAP   GetPic(HWND hWindow) {
	HDC hDCWindow = GetWindowDC(hWindow);
	//��ȡ���ڵĿͻ�������  
	RECT rectWindow;
	GetClientRect(hWindow, &rectWindow);
	//��ȡ��ǰ���ڵ�λͼ  
	HDC hDCMemory = CreateCompatibleDC(hDCWindow);
	HBITMAP hBitmapPic;
	hBitmapPic = CreateCompatibleBitmap(hDCWindow, rectWindow.right, rectWindow.bottom);
	SelectObject(hDCMemory, hBitmapPic);
	BitBlt(hDCMemory, 0, 0, rectWindow.right, rectWindow.bottom, hDCWindow, 0, 0, SRCCOPY);
	ReleaseDC(NULL, hDCWindow);
	ReleaseDC(NULL, hDCMemory);
	DeleteDC(hDCWindow);
	DeleteDC(hDCMemory);
	return hBitmapPic;
}
