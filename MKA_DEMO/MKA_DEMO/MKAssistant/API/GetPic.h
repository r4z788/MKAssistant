#pragma once
#include<Windows.h>

//��������ȡȫ��ͼ��
//��ϸ����ȡȫ��ͼ�񣬲���������ȡͼ��ľ��
HBITMAP GetPic();

//��������ȡָ������ͼ��
//��ϸ����ȡָ������Ĵ��ڵ�ͼ�񣬲���������ȡͼ��ľ��
HBITMAP GetPic(
	LPCWSTR lpWindowName
);

//��������ȡָ������ͼ��
//��ϸ����ȡָ������Ĵ��ڵ�ͼ�񣬲���������ȡͼ��ľ��
HBITMAP GetPic(
	HWND hWindow
);