#include "Ball.h"

extern std::vector<Point<int>> ballsPosition;
extern std::vector<Point<int>> ballsSize;
extern std::vector<Point<int>> ballsSpeed;

extern std::vector<Ball> balls;

void Ball::setSpeed(Point<int> speed)
{
	
	ballsSpeed[this->idx] = speed;
}

void Ball::addSpeed(Point<int> speed)
{
	ballsSpeed[this->idx] += speed;
}

void Ball::setPosition(Point<int> pos)
{
	ballsPosition[idx] = pos;
}

void Ball::setSize(Point<int> size)
{
	ballsSize[idx] = size;
}
