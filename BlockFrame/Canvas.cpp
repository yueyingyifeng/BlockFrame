#include "Canvas.h"
//初始化画布
void Canvas::init()
{
	Block *block = new Block[x_max*y_max];
	this->block = block;
	fill();
}
void Canvas::init(int x_max, int y_max)
{
	Block* block = new Block[x_max * y_max];
	this->block = block;
	setSize(x_max, y_max);
	fill();
}
//显示画布,上外边距，左外边距
void Canvas::show(int margin_top, int margin_left)
{
	//------上外边距-------//
	for (int n{}; n < margin_top; n++) {
		std::cout << std::endl;
	}
	int p{};
	for (int y{}; y < y_max; y++) {

		for (int n{}; n < margin_left; n++) {
			std::cout << Block(' ').get();
		}

		for (int x{}; x < x_max; x++) {
			std::cout << block[p++].get();
		}
		std::cout << std::endl;
	}
}
void Canvas::fill(char f)
{
	int p{};
	for (int y{}; y < y_max; y++) {
		for (int x{}; x < x_max; x++) {
			block[p++].set(f);
		}
	}
}
//设置大小
void Canvas::setSize(int x_max, int y_max)
{
	this->x_max = x_max;
	this->y_max = y_max;
}

std::string Canvas::retColorString() {
	Color fg_c(fg_color);
	Color bg_c(bg_color);
	std::string s{ "color" }, command{};
	return (s + " " + bg_c.getColor().c_str() + fg_c.getColor().c_str());
}

//设置背景颜色
void Canvas::setBgColor(color color)
{
	bg_color = color;
	system(retColorString().c_str());
}

//设置前景颜色
void Canvas::setFgColor(color color)
{
	fg_color = color;
	system(retColorString().c_str());
}