#pragma once
#include <Windows.h>

//概括：获取全屏图像并保存
//详细：获取全屏图像，并在指定位置以指定名称保存
 UINT SavePic(
	LPCWSTR lpFileName//保存文件的位置/名称
);

//概括：获取指定窗口图像并保存
//详细：获取指定标题的窗口的图像，并在指定位置以指定名称保存
 UINT SavePic(
	LPCWSTR lpWindowName,
	LPCWSTR lpFileName
);

//概括：获取指定窗口图像并保存
//详细：获取指定句柄的窗口的图像，并在指定位置以指定名称保存
 UINT SavePic(
	HWND hWindow,
	LPCWSTR lpFileName
);

//概括：保存指定图像
//详细：将指定句柄的图像在指定位置以指定名称保存
 UINT SavePic(
	HBITMAP hBitmap,
	LPCWSTR lpFileName
);