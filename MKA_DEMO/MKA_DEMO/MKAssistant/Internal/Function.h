#pragma once
#include "../Class/RGBINFO.h"

INT IF_RandError(
	UINT nErrorLimit = 0//��Χ
);

//��ȡָ��ͼƬָ��λ�õ�RGBINFO����
RGBINFO IF_GetRGBInfo(
	BYTE *pbyPic,
	BYTE byPic,
	LONG lWidthBytes,
	LONG lX,
	LONG lY
);

//�������������/�м�/�Ҽ������Ƿ�˫����ѡ�ö�Ӧ��WM��Ϣ
UINT IF_GetMouseDownUp(
	UINT &nDown,
	UINT &nUp,
	UINT nL0M1R2Button = 0,
	BOOL bDoubleClick = FALSE
);
