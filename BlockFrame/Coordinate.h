#pragma once
/*
* ��¼���꣬x��y
* ps:��ʵCoordinate��ͨ�ü�дӦ����Coord����������cdnt������
* pps������������д��д�ˣ��ͽ������°�
*/

class Coordinate
{
public:
	int x, y;
	Coordinate(int x, int y) :x(x), y(y) {};
	Coordinate() { x = 0, y = 0 ; }

	//���Ƽ� ��ȡx
	int getX() { return x; }
	//���Ƽ� ��ȡy
	int getY() { return y; }
	//���������������
	//Coordinate operator =(Coordinate cdnt);
	Coordinate operator +(Coordinate& cdnt);
	Coordinate operator -(Coordinate& cdnt);

	//��������Ȼ��������
	Coordinate operator+(int num);

	//�ж�������ȫ��
	bool operator==(const Coordinate cdnt);
	//�ж��������
	bool operator>(Coordinate cdnt);
	//�ж�����С��
	bool operator<(Coordinate cdnt);
	//�ж�x���
	bool equalX(Coordinate cdnt);
	//�ж�y���
	bool equalY(Coordinate cdnt);
	



	//����x,y,xm�����ֵ��Ӧ������p
	static int index(int x, int y, int xm);
	//���������x�����ֵ��Ӧ������p
	static int index(Coordinate cdnt, int xm);
};

typedef Coordinate coord;

