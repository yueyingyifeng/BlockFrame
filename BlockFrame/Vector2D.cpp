#include "Vector2D.h"

namespace BlockFrame {
    Vector2D::Vector2D(size_t x, size_t y) : x(x), y(y) {}

    bool Vector2D::operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    bool Vector2D::operator!=(const Vector2D& other) const {
        return !(*this == other);
    }
    Vector2D Vector2D::operator+(const Vector2D& other) const
    {
        return { this->x + other.x , this->y + other.y };
    }
    Vector2D Vector2D::operator-(const Vector2D& other) const
    {
        return { this->x - other.x , this->y - other.y };
    }
    Vector2D& Vector2D::operator+=(const Vector2D& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2D& Vector2D::operator-=(const Vector2D& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
}

