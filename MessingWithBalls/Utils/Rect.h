#pragma once
#include <SDL.h>

#include "Point.h"

struct Rect : public SDL_Rect {
    void setPosition(Point<int> pos) {
        this->x = pos.x;
        this->y = pos.y;
    };

    Point<int> getPosition() {
        return Point<int>(this->x, this->y);
    };

    void setSize(Point<int> size) {
        this->w = size.x;
        this->h = size.y;
    };

    Point<int> getSize() {
        return Point<int>(this->w, this->h);
    };
};