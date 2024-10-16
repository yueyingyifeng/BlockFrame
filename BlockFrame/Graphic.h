#pragma once
#include <Windows.h>
#include "Painting.h"
namespace BlockFrame {

    class Graphic {
    protected:
        Painting* p;
	public:
        Graphic(size_t MAX_X, size_t MAX_Y, Vector2D origin = Vector2D()){
            p = new Painting(MAX_X, MAX_Y, origin);
        }
        virtual ~Graphic() {
            //delete p;
        }
        virtual void update(void (*callback)(Painting* p)) = 0;
	};
}