#pragma once
#include <Windows.h>

//����������Ļ����ͼ�����
//��ϸ������Ļ���ҵ�ָ��ͼƬ�������ӳ�ָ��ʱ����������ָ��λ��
UINT ClickPic(
	HBITMAP hbmSmall,//��Ҫ���ҵ���ͼƬ�ľ��
	INT nAddX = 0,//�ҵ�ͼƬ����Ҫ�����λ�õ����������Ͻ����꣨0,0����x����ƫ����
	INT nAddY = 0,//�ҵ�ͼƬ����Ҫ�����λ�õ����������Ͻ����꣨0,0����y����ƫ����
	UINT nStep = 1,//����ͼƬ�Ĳ���������Խ�����ٶ�Խ�죬���Խ��
	UINT nErrorLimit = 0,//�趨�������Χ���ڵ��ʱ���������ʹ���ʱ�������Ǿ�ȷ�ص���ͬһ���ϣ���ֹ������һ��ƹ�ע
	BOOL bDoubleClick = FALSE,//�Ƿ�˫��
	UINT nL0M1R2Button = 0,//��������Left����0���м���Middle����1���Ҽ���Right����2
	DWORD dwSpan = 0//�ӳ�ָ���������
);

//��������ָ����������ͼ�����
//��ϸ����ָ������Ĵ������ҵ�ָ��ͼƬ�������ӳ�ָ��ʱ���������̨���ָ��λ��
UINT ClickPic(
	LPCWSTR lpWindowName,//ָ�����ڵı���
	HBITMAP hbmSmall,
	INT nAddX = 0,
	INT nAddY = 0,
	UINT nStep = 1,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);

//��������ָ����������ͼ�����
//��ϸ����ָ������Ĵ������ҵ�ָ��ͼƬ�������ӳ�ָ��ʱ���������̨���ָ��λ��
UINT ClickPic(
	HWND hWindow,//ָ�����ڵľ��
	HBITMAP hbmSmall,
	INT nAddX = 0,
	INT nAddY = 0,
	UINT nStep = 1,
	UINT nErrorLimit = 0,
	BOOL bDoubleClick = FALSE,
	UINT nL0M1R2Button = 0,
	DWORD dwSpan = 0
);