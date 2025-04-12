#pragma once
#include "Vector2D.h"
namespace BlockFrame {
	class Painting {
	public:
		virtual void pixel(Vector2D v, const char& c) = 0;
		virtual void line(Vector2D v1, Vector2D v2, const char& c) = 0;
	};
}