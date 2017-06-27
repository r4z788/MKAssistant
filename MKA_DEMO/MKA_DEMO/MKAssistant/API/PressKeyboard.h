#pragma once
#include <Windows.h>

//概括：按键盘
//详细：以指定形式直接按键盘
UINT PressKeyboard(
	WORD wKey,//键盘按键，按键值由<WinUser.h>设定
	UINT nC0D1U2 = 0//按下并抬起（Click）：0，仅按下（Down）：1，仅抬起（Up）：2
);

//概括：在指定窗口中按键盘
//详细：在指定标题的窗口中以指定形式前台按键盘
UINT PressKeyboard(
	LPCWSTR lpWindowName,
	WORD wKey,
	UINT nC0D1U2 = 0
);

//概括：在指定窗口中按键盘
//详细：在指定句柄的窗口中以指定形式前台按键盘
UINT PressKeyboard(
	HWND hWindow,
	WORD wKey,
	UINT nC0D1U2 = 0
);