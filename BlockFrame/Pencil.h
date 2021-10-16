#pragma once
#include"Canvas.h"
#include"Coordinate.h"
/*
* ���뻭������������滭
*/
class Pencil
{
	//�����ı���
	Canvas* canvas;
	//Ĭ���ַ�
	char pen{ ' ' };

	int index(int x, int y);
	int index(Coordinate cdnt);
	int index(Coordinate* cdnt);
public:
	Pencil() { canvas = nullptr; }
	Pencil(Canvas& canvas) {
		this->canvas = &canvas;
	}
	Pencil(Canvas& canvas, char c){ 
		this->canvas = &canvas; 
		this->pen = c; 
	}

	//-----����-----//

	//���Ƽ�-��һ���� x,y
	void Pixel(int x, int y);
	//���Ƽ�-����һ���� x,y,��Ҫ�ŵ��ַ�
	void Pixel(int x, int y, char c);

	//����һ���� ����(x,y)
	void Pixel(Coordinate cdnt);
	void Pixel(Coordinate* cdnt);
	//����һ���� ����(x,y),��Ҫ�ŵ��ַ�
	void Pixel(Coordinate cdnt, char c);
	void Pixel(Coordinate* cdnt, char c);

	//����һ���� ����a(x,y),����b(x,y)
	void Line(Coordinate cdnta, Coordinate cdntb);
	//����һ���� ����a(x,y),����b(x,y),��Ҫ�ŵ��ַ�
	void Line(Coordinate cdnta, Coordinate cdntb, char c);

	//����һ������ ����a(x,y),����d(x,y)
	void Box(Coordinate cdnta, Coordinate cdntd);
	//����һ������ ����a(x,y),����d(x,y),��Ҫ�ŵ��ַ�
	void Box(Coordinate cdnta, Coordinate cdntd, char c);
};