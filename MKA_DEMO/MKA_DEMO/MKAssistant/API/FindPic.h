#pragma once
#include <Windows.h>
#include "../Class/POSITION.h"

//�������Ӵ�ͼ������Сͼ
//��ϸ����ָ��������ָ����ͼ������ָ��Сͼ��������Сͼ�ڴ�ͼ�е�����
POSITION FindPic(
	HBITMAP hbmSmall,//Сͼ���
	HBITMAP hbmLarge,//��ͼ���
	UINT nStep = 1
);