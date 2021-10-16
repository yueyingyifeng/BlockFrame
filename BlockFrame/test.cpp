#include"BlockFrame.h"

int main() {
	Canvas canvas(10, 10);
	Pencil p(canvas);
	p.Pixel(coord(1, 1), 'h');
	p.Pixel(coord(1, 2), 'z');
	p.Pixel(coord(2, 1), 'c');

	canvas.show();
}