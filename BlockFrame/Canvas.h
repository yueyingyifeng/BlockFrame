#pragma once
#include<iostream>
#include"Block.h"
#include"Color.h"
/*
* ����Block����һ������
*/
class Canvas
{
	
	//������ǰ���ͱ�����ɫ
	color fg_color{ color::White }, bg_color{ color::Black };
	//������ɫ�ַ�����set Fg/Bg Colorʹ��
	std::string retColorString();
protected:
	//���������ֵ
	int x_max, y_max;
public:
	Canvas(int x_max = 0, int y_max = 0) :x_max(x_max), y_max(y_max) { init(); }
		
	//����Ŀ�
	Block* block;
	//��ʼ������
	void init();
	//��ʼ������,���������x�����yֵ
	void init(int x_max,int y_max);
	//��ʾ����
	void show(int margin_top = 0, int margin_left = 0);
	//�����������
	void fill(char f = ' ');
	//���û������x�����yֵ
	void setSize(int x_max, int y_max);
	//���ÿ���̨������ɫ
	void setBgColor(color color);
	//���ÿ���̨ǰ����ɫ
	void setFgColor(color color);
	//��ȡ�������xֵ
	int getX_max() { return x_max; }
	//��ȡ�������yֵ
	int getY_max() { return y_max; }
};

