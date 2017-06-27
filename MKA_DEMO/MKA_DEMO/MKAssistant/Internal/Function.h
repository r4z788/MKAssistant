#pragma once
#include "../Class/RGBINFO.h"

INT IF_RandError(
	UINT nErrorLimit = 0//误差范围
);

//获取指定图片指定位置的RGBINFO数据
RGBINFO IF_GetRGBInfo(
	BYTE *pbyPic,
	BYTE byPic,
	LONG lWidthBytes,
	LONG lX,
	LONG lY
);

//根据鼠标键（左键/中键/右键）和是否双击，选用对应的WM消息
UINT IF_GetMouseDownUp(
	UINT &nDown,
	UINT &nUp,
	UINT nL0M1R2Button = 0,
	BOOL bDoubleClick = FALSE
);
