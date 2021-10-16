#pragma once
/*
* 记录坐标，x与y
* ps:其实Coordinate的通用简写应该是Coord。。。而非cdnt。。。
* pps：不过。。。写都写了，就将就以下把
*/

class Coordinate
{
public:
	int x, y;
	Coordinate(int x, int y) :x(x), y(y) {};
	Coordinate() { x = 0, y = 0 ; }

	//不推荐 获取x
	int getX() { return x; }
	//不推荐 获取y
	int getY() { return y; }
	//坐标与坐标的运算
	//Coordinate operator =(Coordinate cdnt);
	Coordinate operator +(Coordinate& cdnt);
	Coordinate operator -(Coordinate& cdnt);

	//坐标与自然数的运算
	Coordinate operator+(int num);

	//判断两坐标全等
	bool operator==(const Coordinate cdnt);
	//判断整体大于
	bool operator>(Coordinate cdnt);
	//判断整体小于
	bool operator<(Coordinate cdnt);
	//判断x相等
	bool equalX(Coordinate cdnt);
	//判断y相等
	bool equalY(Coordinate cdnt);
	



	//求与x,y,xm的最大值对应的索引p
	static int index(int x, int y, int xm);
	//求与坐标和x的最大值对应的索引p
	static int index(Coordinate cdnt, int xm);
};

typedef Coordinate coord;

