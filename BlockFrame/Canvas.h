#pragma once
#include <functional>
#include "Painting.h"

namespace BlockFrame {
	class Canvas {
	protected:
		virtual bool frame(std::function<void(Painting* p)> callback) = 0;
	};
}
