#pragma once
#include <cmath>
namespace BlockFrame {
	class Vector2D {
	public:
		size_t x = 0, y = 0;
		Vector2D() : x(0), y(0) {}
		Vector2D(size_t x, size_t y);

		bool operator==(const Vector2D& other) const;
		bool operator!=(const Vector2D& other) const;
		Vector2D operator+(const Vector2D& other) const;
		Vector2D operator-(const Vector2D& other) const;
		Vector2D& operator+=(const Vector2D& other);
		Vector2D& operator-=(const Vector2D& other);




	};
}