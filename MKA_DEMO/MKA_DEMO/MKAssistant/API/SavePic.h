#pragma once
#include <Windows.h>

//��������ȡȫ��ͼ�񲢱���
//��ϸ����ȡȫ��ͼ�񣬲���ָ��λ����ָ�����Ʊ���
 UINT SavePic(
	LPCWSTR lpFileName//�����ļ���λ��/����
);

//��������ȡָ������ͼ�񲢱���
//��ϸ����ȡָ������Ĵ��ڵ�ͼ�񣬲���ָ��λ����ָ�����Ʊ���
 UINT SavePic(
	LPCWSTR lpWindowName,
	LPCWSTR lpFileName
);

//��������ȡָ������ͼ�񲢱���
//��ϸ����ȡָ������Ĵ��ڵ�ͼ�񣬲���ָ��λ����ָ�����Ʊ���
 UINT SavePic(
	HWND hWindow,
	LPCWSTR lpFileName
);

//����������ָ��ͼ��
//��ϸ����ָ�������ͼ����ָ��λ����ָ�����Ʊ���
 UINT SavePic(
	HBITMAP hBitmap,
	LPCWSTR lpFileName
);