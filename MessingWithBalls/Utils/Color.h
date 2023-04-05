#pragma once
#include <SDL.h>

struct Color : SDL_Color {
	bool operator==(const Color& other) {
		return
			(this->r == other.r) &&
			(this->g == other.g) &&
			(this->b == other.b) &&
			(this->a == other.a);
	}
};
