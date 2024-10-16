#pragma once
#include "Graphic.h"

namespace BlockFrame {
	class Canvas : public Graphic {
	public:
		Canvas(size_t MAX_X, size_t MAX_Y, Vector2D origin = Vector2D()) : Graphic(MAX_X, MAX_Y, origin) {}
		void update(void (*callback)(Painting* p)) override final;
	};
}
