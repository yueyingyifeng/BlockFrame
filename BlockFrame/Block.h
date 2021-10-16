#pragma once
/*
* 保存最小单元——即单个字符
*/
class Block
{
	char c;
public:
	Block() {
		c = -1;
	}

	Block(char c) :c(c) {}
	
	char get() {
		return c;
	}

	void set(char c = ' ') {
		this->c = c;
	}
};

