#pragma once
#include <Windows.h>
#include <vector>
#include "Block.h"
#include "Vector2D.h"

namespace BlockFrame {
	// 设置前景色和背景色
	inline void SetColor(Color foreground = Color::White, Color background = Color::Black) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD color = static_cast<WORD>(foreground) | (static_cast<WORD>(background) << 4);
		SetConsoleTextAttribute(hConsole, color);
	}
	//设置光标位置
	inline void SetCursorPosition(Vector2D v) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { static_cast<SHORT>(v.x), static_cast<SHORT>(v.y) };
		SetConsoleCursorPosition(hConsole, pos);
	}

	class Painting {
		using blocks = std::vector<Block>;

		blocks buffer;
		const Vector2D origin;
		size_t MAX_X;
		size_t MAX_Y;

	public:

		Painting(size_t MAX_X, size_t MAX_Y, Vector2D origin) : origin(origin), MAX_X(MAX_X), MAX_Y(MAX_Y) {
			buffer.resize(MAX_X * MAX_Y);
		}

		bool isOutOfRange(Vector2D v) const;
		void setSize(size_t MAX_X, size_t MAX_Y);

		void paint() const;
		
		
		void pixel(Vector2D v, char c = ' ');
		void line(Vector2D v1, Vector2D v2, char c = ' ');


		size_t posOfBlocks(Vector2D v) const;
	};
}