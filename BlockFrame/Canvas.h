#pragma once
#include<iostream>
#include"Block.h"
#include"Color.h"
/*
* 利用Block构成一幅画布
*/
class Canvas
{
	
	//画布的前景和背景颜色
	color fg_color{ color::White }, bg_color{ color::Black };
	//返回颜色字符串供set Fg/Bg Color使用
	std::string retColorString();
protected:
	//画布的最大值
	int x_max, y_max;
public:
	Canvas(int x_max = 0, int y_max = 0) :x_max(x_max), y_max(y_max) { init(); }
		
	//保存的块
	Block* block;
	//初始化画布
	void init();
	//初始化画布,并设置最大x和最大y值
	void init(int x_max,int y_max);
	//显示画布
	void show(int margin_top = 0, int margin_left = 0);
	//填充整个画布
	void fill(char f = ' ');
	//设置画布最大x和最大y值
	void setSize(int x_max, int y_max);
	//设置控制台背景颜色
	void setBgColor(color color);
	//设置控制台前景颜色
	void setFgColor(color color);
	//获取画布最大x值
	int getX_max() { return x_max; }
	//获取画布最大y值
	int getY_max() { return y_max; }
};

