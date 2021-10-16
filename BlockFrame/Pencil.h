#pragma once
#include"Canvas.h"
#include"Coordinate.h"
/*
* 载入画布并在其上面绘画
*/
class Pencil
{
	//画布的备份
	Canvas* canvas;
	//默认字符
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

	//-----工具-----//

	//不推荐-放一个块 x,y
	void Pixel(int x, int y);
	//不推荐-放置一个块 x,y,所要放的字符
	void Pixel(int x, int y, char c);

	//放置一个块 坐标(x,y)
	void Pixel(Coordinate cdnt);
	void Pixel(Coordinate* cdnt);
	//放置一个块 坐标(x,y),所要放的字符
	void Pixel(Coordinate cdnt, char c);
	void Pixel(Coordinate* cdnt, char c);

	//放置一条线 坐标a(x,y),坐标b(x,y)
	void Line(Coordinate cdnta, Coordinate cdntb);
	//放置一条线 坐标a(x,y),坐标b(x,y),所要放的字符
	void Line(Coordinate cdnta, Coordinate cdntb, char c);

	//放置一个方框 坐标a(x,y),坐标d(x,y)
	void Box(Coordinate cdnta, Coordinate cdntd);
	//放置一个方框 坐标a(x,y),坐标d(x,y),所要放的字符
	void Box(Coordinate cdnta, Coordinate cdntd, char c);
};