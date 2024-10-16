#include "Painting.h"

namespace BlockFrame {
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
        buffer[posOfBlocks(v)] = c;
	}

    void Painting::line(Vector2D v1, Vector2D v2, char c)
    {
        size_t dy = static_cast<size_t>(abs((long)v2.y - (long)v1.y)); // 计算y方向的差
        size_t dx = static_cast<size_t>(abs((long)v2.x - (long)v1.x)); // 计算x方向的差

        // 计算分段数
        size_t steps = dy > 0 ? dy : 1; // 如果dy大于0，则分成dy段，否则至少1段
        float xIncrement = static_cast<float>(dx) / steps; // 每步x增加的量
        float yIncrement = static_cast<float>(dy) / steps; // 每步y增加的量

        // 初始化当前点
        float x = v1.x;
        float y = v1.y;

        // 循环绘制每个段
        for (size_t i = 0; i <= steps; i++) {
            pixel(Vector2D(static_cast<int>(round(x)), static_cast<int>(round(y))), c); // 绘制像素

            x += xIncrement; // 更新x
            y += yIncrement; // 更新y
        }
    }
    size_t Painting::posOfBlocks(Vector2D v) const
    {
        return v.x + v.y * MAX_X;
    }
}