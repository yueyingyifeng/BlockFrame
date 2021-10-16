#pragma once
#include<string>
/*
* 保存颜色——与Windows Cmd控制台有关
*/
enum class color {
	Black,
	Blue,
	Green,
	LightGreen,//淡绿
	Red,
	Purple,
	Yellow,
	White,
	Grey,
	LightBlue,
	BrightGreen,//黄绿
};

class Color {
public:
	color c;
	std::string s_color;
	Color(color c) {
		this->c = c;
		switch (c)
		{
		case color::Black:
			s_color = '0';
			break;
		case color::Blue:
			s_color = '1';
			break;
		case color::Green:
			s_color = '2';
			break;
		case color::LightGreen:
			s_color = '3';
			break;
		case color::Red:
			s_color = '4';
			break;
		case color::Purple:
			s_color = '5';
			break;
		case color::Yellow:
			s_color = '6';
			break;
		case color::White:
			s_color = '7';
			break;
		case color::Grey:
			s_color = '8';
			break;
		case color::LightBlue:
			s_color = '9';
			break;
		case color::BrightGreen:
			s_color = 'A';
			break;
		default:
			std::cout << "not this siwtch!" << std::endl;
			break;
		}
	}
	//获取颜色代码，返回的是枚举类型
	color getcolor_e() {
		return c; 
	}
	//获取颜色代码，返回的是字符串
	std::string getColor() {
		return s_color;
	}
};