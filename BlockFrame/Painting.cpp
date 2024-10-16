#include "Painting.h"

namespace BlockFrame {
    bool Painting::isOutOfRange(Vector2D v) const
    {
        return v.x < 0 || v.y < 0 || v.x >= MAX_X || v.y >= MAX_Y;
    }
    void Painting::setSize(size_t MAX_X, size_t MAX_Y)
    {
        this->MAX_X = MAX_X;
        this->MAX_Y = MAX_Y;
    }
    void Painting::paint() const
    {
        for (int i{}; i < MAX_Y; i++) {
            for (int j{}; j < MAX_X; j++) {
                auto currentPos = Vector2D(j, i);
                auto& block = buffer[posOfBlocks(currentPos)];
                SetColor(block.foreGround, block.backGounrd);
				SetCursorPosition(origin + currentPos);
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &(buffer[posOfBlocks(currentPos)].c), 1, NULL, NULL);
            }
            WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        }
    }

    void Painting::pixel(Vector2D v, char c)
	{
		if (isOutOfRange(v))
            throw "out of painting range!";

        buffer[posOfBlocks(v)] = c;
	}
    // 分段直线算法( 没错，我给明明的 XD )
	void Painting::line(Vector2D v1, Vector2D v2, char c)
	{
		if (isOutOfRange(v2) || isOutOfRange(v1))
			throw "out of painting range!";
		size_t dy = static_cast<size_t>(abs((long)v2.y - (long)v1.y)) + 1;
		size_t dx = static_cast<size_t>(abs((long)v2.x - (long)v1.x)) + 1;

		size_t steps = dx > dy ? dx / dy : dy / dx;

		int ix = v2.x == v1.x ? 0 : v2.x > v1.x ? 1 : -1;
		int iy = v2.y == v1.y ? 0 : v2.y > v1.y ? 1 : -1;

        if(dx > dy)
		    for (int i{}; i < dx; i++, v1.x += ix) {
			    if (i != 0 && i % steps == 0 && v1.y != v2.y)
				    v1.y += iy;
			    pixel(Vector2D(v1.x, v1.y), c);
		    }
        else
			for (int i{}; i < dy; i++, v1.y += iy) {
				if (i != 0 && i % steps == 0 && v1.x != v2.x)
					v1.x += ix;
				pixel(Vector2D(v1.x, v1.y), c);
			}
	}
    size_t Painting::posOfBlocks(Vector2D v) const
    {
        return v.x + v.y * MAX_X;
    }
}