#pragma once
/*
* ������С��Ԫ�����������ַ�
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

