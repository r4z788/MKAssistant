#include <Windows.h>
#include "GetPic.h"
#include "SavePic.h"

UINT SavePic(LPCWSTR lpFileName) {
	return SavePic(GetPic(), lpFileName);
}

UINT SavePic(LPCWSTR lpWindowName, LPCWSTR lpFileName) {
	return SavePic(GetPic(lpWindowName), lpFileName);
}

UINT SavePic(HWND hWindow, LPCWSTR lpFileName) {
	return SavePic(GetPic(hWindow), lpFileName);
}

UINT SavePic(HBITMAP hBitmap, LPCWSTR lpFileName) {
	HDC hDC = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL); //�豸������
	INT iBits = GetDeviceCaps(hDC, BITSPIXEL) * GetDeviceCaps(hDC, PLANES);//��ǰ��ʾ�ֱ�����ÿ��������ռ�ֽ���,����λͼ�ļ�ÿ��������ռ�ֽ���
	WORD wBitCount;//λͼ��ÿ��������ռ�ֽ���
	DWORD dwPaletteSize = 0;//�����ɫ���С	
	DWORD dwBmBitsSize;//λͼ�������ֽڴ�С	
	DWORD dwDIBSize;// λͼ�ļ���С	
	DWORD dwWritten;//д���ļ��ֽ���	
	BITMAP Bitmap;//λͼ�ṹ	
	BITMAPFILEHEADER bmfHdr;   //λͼ���Խṹ	
	BITMAPINFOHEADER bi;       //λͼ�ļ�ͷ�ṹ	
	LPBITMAPINFOHEADER lpbi;     //λͼ��Ϣͷ�ṹ     ָ��λͼ��Ϣͷ�ṹ	
	HANDLE fh;//�����ļ����	
	HANDLE hDib;//�����ڴ���	
	HANDLE hPal;//�����ڴ���	
	HANDLE hOldPal = NULL;//��ɫ���� 
	DeleteDC(hDC);
	if(iBits <= 1) {
		wBitCount = 1;
	}
	else if(iBits <= 4) {
		wBitCount = 4;
	}
	else if(iBits <= 8) {
		wBitCount = 8;
	}
	else if(iBits <= 24) {
		wBitCount = 24;
	}
	else if(iBits <= 32) {
		wBitCount = 24;
	}
	//�����ɫ���С  
	if(wBitCount <= 8) {
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD);
	}
	//����λͼ��Ϣͷ�ṹ  
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = wBitCount;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;
	dwBmBitsSize = ((Bitmap.bmWidth *wBitCount + 31) / 32) * 4 * Bitmap.bmHeight;
	//Ϊλͼ���ݷ����ڴ�  
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	if(lpbi == NULL) {
		return 1;
	}
	*lpbi = bi;
	// �����ɫ��
	hPal = GetStockObject(DEFAULT_PALETTE);
	if(hPal) {
		hDC = GetDC(NULL);
		hOldPal = ::SelectPalette(hDC, (HPALETTE)hPal, FALSE);
		RealizePalette(hDC);
	}
	// ��ȡ�õ�ɫ�����µ�����ֵ
	GetDIBits(
		hDC,
		hBitmap,
		0,
		(UINT)Bitmap.bmHeight,
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize,
		(LPBITMAPINFO)lpbi,
		DIB_RGB_COLORS
	);
	//�ָ���ɫ��
	if(hOldPal) {
		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
		RealizePalette(hDC);
		ReleaseDC(NULL, hDC);
	}
	//����λͼ�ļ�
	fh = CreateFile(
		lpFileName,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL
	);
	if(fh == INVALID_HANDLE_VALUE) {
		return 1;
	}
	// ����λͼ�ļ�ͷ
	bmfHdr.bfType = 0x4D42;  // "BM"  
	dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER) + dwPaletteSize;
	// д��λͼ�ļ�ͷ  
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	// д��λͼ�ļ���������
	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);
	//���
	GlobalUnlock(hDib);
	GlobalFree(hDib);
	CloseHandle(fh);
	return 0;
}
