#include "BlockBuffer.h"

namespace BlockFrame {
	BlockBuffer::BlockBuffer(std::vector<std::string> strings)
	{
		auto min = std::min_element(strings.begin(), strings.end(),
			[](auto a, auto b) { return a.size() < b.size(); })->size();
		
		for (int y{}; y < strings.size(); y++)
			for (int x{}; x < min; x++)
				buffer.emplace_back(strings[y][x]);
	}
}


