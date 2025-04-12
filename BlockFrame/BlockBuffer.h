#pragma once
#include <vector>
#include "Block.h"
namespace BlockFrame {
	using Blocks = std::vector<Block>;
	class BlockBuffer {
	public:
		Blocks buffer;
		BlockBuffer() {};
		BlockBuffer(std::vector<std::string> strings);
	};
}