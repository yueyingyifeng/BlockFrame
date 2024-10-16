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
        size_t dy = static_cast<size_t>(abs((long)v2.y - (long)v1.y)); // ����y����Ĳ�
        size_t dx = static_cast<size_t>(abs((long)v2.x - (long)v1.x)); // ����x����Ĳ�

        // ����ֶ���
        size_t steps = dy > 0 ? dy : 1; // ���dy����0����ֳ�dy�Σ���������1��
        float xIncrement = static_cast<float>(dx) / steps; // ÿ��x���ӵ���
        float yIncrement = static_cast<float>(dy) / steps; // ÿ��y���ӵ���

        // ��ʼ����ǰ��
        float x = v1.x;
        float y = v1.y;

        // ѭ������ÿ����
        for (size_t i = 0; i <= steps; i++) {
            pixel(Vector2D(static_cast<int>(round(x)), static_cast<int>(round(y))), c); // ��������

            x += xIncrement; // ����x
            y += yIncrement; // ����y
        }
    }
    size_t Painting::posOfBlocks(Vector2D v) const
    {
        return v.x + v.y * MAX_X;
    }
}