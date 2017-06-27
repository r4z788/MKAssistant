#pragma once
#include <Windows.h>
#include "../Class/POSITION.h"

//概括：从大图中搜索小图
//详细：以指定步长从指定大图中搜索指定小图，并返回小图在大图中的坐标
POSITION FindPic(
	HBITMAP hbmSmall,//小图句柄
	HBITMAP hbmLarge,//大图句柄
	UINT nStep = 1
);