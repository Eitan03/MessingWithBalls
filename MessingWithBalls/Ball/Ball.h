#pragma once
#include <vector>

#include "../Utils/Rect.h"

class Ball {
public:
	Ball(int idx): idx { idx } {};

	void setSpeed(Point<int> speed);
	void addSpeed(Point<int> speed);

	void setPosition(Point<int> pos);

	void setSize(Point<int> size);
private:
	int idx;
};

