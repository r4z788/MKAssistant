#pragma once
#include <Windows.h>

//������������
//��ϸ����ָ����ʽֱ�Ӱ�����
UINT PressKeyboard(
	WORD wKey,//���̰���������ֵ��<WinUser.h>�趨
	UINT nC0D1U2 = 0//���²�̧��Click����0�������£�Down����1����̧��Up����2
);

//��������ָ�������а�����
//��ϸ����ָ������Ĵ�������ָ����ʽǰ̨������
UINT PressKeyboard(
	LPCWSTR lpWindowName,
	WORD wKey,
	UINT nC0D1U2 = 0
);

//��������ָ�������а�����
//��ϸ����ָ������Ĵ�������ָ����ʽǰ̨������
UINT PressKeyboard(
	HWND hWindow,
	WORD wKey,
	UINT nC0D1U2 = 0
);