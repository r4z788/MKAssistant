#pragma once
#include <Windows.h>

//�����������Ļָ��λ��
//��ϸ���ӳ�ָ��ʱ�����ָ����Χ�ڣ������Ļ��ָ��λ��
UINT PressMouse(
	INT nX,//�����x����
	INT nY,//�����y����
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);

//���������ָ�����ڵ�ָ��λ��
//��ϸ���ӳ�ָ��ʱ�����ָ����Χ�ڣ���̨���ָ������Ĵ��ڵ�ָ��λ��
UINT PressMouse(
	LPCWSTR lpWindowName,
	INT nX,
	INT nY,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);

//���������ָ�����ڵ�ָ��λ��
//��ϸ���ӳ�ָ��ʱ�����ָ����Χ�ڣ���̨���ָ������Ĵ��ڵ�ָ��λ��
UINT PressMouse(
	HWND hWindow,
	INT nX,
	INT nY,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);
