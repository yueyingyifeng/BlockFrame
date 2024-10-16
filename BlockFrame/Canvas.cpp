#include "Canvas.h"

namespace BlockFrame {
	void Canvas::update(void(*callback)(Painting* p))
	{
		callback(p);
		p->paint();
	}
}
