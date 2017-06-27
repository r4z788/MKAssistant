#pragma once
#include <Windows.h>

//概括：从屏幕中找图并点击
//详细：从屏幕中找到指定图片，并在延迟指定时间后用鼠标点击指定位置
UINT ClickPic(
	HBITMAP hbmSmall,//需要被找到的图片的句柄
	INT nAddX = 0,//找到图片后，需要点击的位置的坐标与左上角坐标（0,0）的x坐标偏移量
	INT nAddY = 0,//找到图片后，需要点击的位置的坐标与左上角坐标（0,0）的y坐标偏移量
	UINT nStep = 1,//搜索图片的步长（步长越长，速度越快，误差越大）
	UINT nErrorLimit = 0,//设定点击的误差范围，在点击时生成随机误差，使点击时不会总是精确地点在同一点上，防止被反外挂机制关注
	BOOL bDoubleClick = FALSE,//是否双击
	UINT nL0M1R2Button = 0,//鼠标左键（Left）：0，中键（Middle）：1，右键（Right）：2
	DWORD dwSpan = 0//延迟指定毫秒后点击
);

//概括：从指定窗口中找图并点击
//详细：从指定标题的窗口中找到指定图片，并在延迟指定时间后用鼠标后台点击指定位置
UINT ClickPic(
	LPCWSTR lpWindowName,//指定窗口的标题
	HBITMAP hbmSmall,
	INT nAddX = 0,
	INT nAddY = 0,
	UINT nStep = 1,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);

//概括：从指定窗口中找图并点击
//详细：从指定句柄的窗口中找到指定图片，并在延迟指定时间后用鼠标后台点击指定位置
UINT ClickPic(
	HWND hWindow,//指定窗口的句柄
	HBITMAP hbmSmall,
	INT nAddX = 0,
	INT nAddY = 0,
	UINT nStep = 1,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);