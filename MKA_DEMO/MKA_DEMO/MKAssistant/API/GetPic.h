#pragma once
#include<Windows.h>

//概括：获取全屏图像
//详细：获取全屏图像，并返回所获取图像的句柄
HBITMAP GetPic();

//概括：获取指定窗口图像
//详细：获取指定标题的窗口的图像，并返回所获取图像的句柄
HBITMAP GetPic(
	LPCWSTR lpWindowName
);

//概括：获取指定窗口图像
//详细：获取指定句柄的窗口的图像，并返回所获取图像的句柄
HBITMAP GetPic(
	HWND hWindow
);