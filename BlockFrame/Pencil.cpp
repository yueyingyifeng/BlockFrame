#include "Pencil.h"

int Pencil::index(int x,int y) {
	return y * canvas->getX_max() + x;
}

int Pencil::index(Coordinate cdnt) {
	return cdnt.y * canvas->getX_max() + cdnt.x;
}
int Pencil::index(Coordinate* cdnt) {
	return cdnt->y * canvas->getX_max() + cdnt->x;
}
//-----------------------------------tool-----------------------------------//
void Pencil::Pixel(int x, int y)
{
	canvas->block[index(x, y)].set(pen);
}

void Pencil::Pixel(int x, int y, char c)
{
	canvas->block[index(x,y)].set(c);
}

void Pencil::Pixel(Coordinate cdnt)
{
	canvas->block[index(cdnt)].set(pen);
}

void Pencil::Pixel(Coordinate* cdnt)
{
	canvas->block[index(cdnt)].set(pen);
}

void Pencil::Pixel(Coordinate cdnt, char c)
{
	canvas->block[index(cdnt)].set(c);
}

void Pencil::Pixel(Coordinate* cdnt, char c)
{
	canvas->block[index(*cdnt)].set(c);
}

void Pencil::Line(Coordinate cdnta, Coordinate cdntb)
{
	//���ŵ����
	if (cdnta.equalY(cdntb)) {
		int length = cdnta.getX() - cdntb.getX();
		if (length >= 0) {
			for (int x{ length }; x > 0; x--) {
				Pixel(cdnta.x--, cdnta.y);
			}
		}
		else {
			for (int x{ length }; x < 0; x++) {
				Pixel(cdnta.x++, cdnta.y);
			}
		}
	}
	//���ŵ����
	if (cdnta.equalX(cdntb)) {
		int length = cdnta.getY() - cdntb.getY();
		if (length >= 0) {
			for (int y{ length }; y > 0; y--) {
				Pixel(cdnta.x, cdnta.y--);
			}
		}
		else {
			for (int y{ length }; y < 0; y++) {
				Pixel(cdnta.x, cdnta.y++);
			}
		}
	}
}

void Pencil::Line(Coordinate cdnta, Coordinate cdntb, char c)
{
	//���ŵ����
	if (cdnta.equalY(cdntb)) {
		int length = cdnta.getX() - cdntb.getX();
		if (length >= 0) {
			for (int x{ length }; x >= 0; x--) {
				Pixel(cdnta.x--,cdnta.y, c);
			}
		}
		else {
			for (int x{ length }; x <= 0; x++) {
				Pixel(cdnta.x++, cdnta.y, c);
			}
		}
	}
	//���ŵ����
	if (cdnta.equalX(cdntb)) {
		int length = cdnta.getY() - cdntb.getY();
		if (length >= 0) {
			for (int y{ length }; y >= 0; y--) {
				Pixel(cdnta.x, cdnta.y--, c);
			}
		}
		else {
			for (int y{ length }; y <= 0; y++) {
				Pixel(cdnta.x, cdnta.y++, c);
			}
		}
	}
}

void Pencil::Box(Coordinate cdnta, Coordinate cdntd)
{
	if (cdnta > Coordinate(canvas->getX_max(), canvas->getY_max()) ||
		cdntd > Coordinate(canvas->getX_max(), canvas->getY_max())) {

	}
	else {
		Line(cdnta, Coordinate(cdntd.x, cdnta.y), pen);//�ϱ߿�
		Line(Coordinate(cdntd.x, cdnta.y), cdntd, pen);//�ұ߿�
		Line(cdntd, Coordinate(cdnta.x, cdntd.y), pen);//�±߿�
		Line(Coordinate(cdnta.x, cdntd.y), cdnta, pen);//��߿�
	}
}

void Pencil::Box(Coordinate cdnta, Coordinate cdntd, char c)
{
	if ( cdnta > Coordinate(canvas->getX_max(), canvas->getY_max()) ||
		 cdntd > Coordinate(canvas->getX_max(), canvas->getY_max()) ) {

	}
	else {
		Line(cdnta, Coordinate(cdntd.x, cdnta.y), c);//�ϱ߿�
		Line(Coordinate(cdntd.x, cdnta.y), cdntd, c);//�ұ߿�
		Line(cdntd, Coordinate(cdnta.x, cdntd.y), c);//�±߿�
		Line(Coordinate(cdnta.x, cdntd.y), cdnta, c);//��߿�
	}
}

