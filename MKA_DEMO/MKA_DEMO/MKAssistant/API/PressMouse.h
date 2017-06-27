#pragma once
#include <Windows.h>

//概括：点击屏幕指定位置
//详细：延迟指定时间后，在指定误差范围内，点击屏幕的指定位置
UINT PressMouse(
	INT nX,
	INT nY,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);

//概括：点击指定窗口的指定位置
//详细：延迟指定时间后，在指定误差范围内，后台点击指定标题的窗口的指定位置
UINT PressMouse(
	LPCWSTR lpWindowName,
	INT nX,
	INT nY,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);

//概括：点击指定窗口的指定位置
//详细：延迟指定时间后，在指定误差范围内，后台点击指定句柄的窗口的指定位置
UINT PressMouse(
	HWND hWindow,
	INT nX,
	INT nY,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);
