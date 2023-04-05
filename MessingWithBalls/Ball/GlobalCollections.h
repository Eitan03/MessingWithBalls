#pragma once
#include <vector>

#include "../MySDL/MyTexture.h"

#include "../Utils/Color.h"
#include "../Utils/Rect.h"

#include "Ball.h"

extern std::vector<Point<int>> ballsPosition;
extern std::vector<Point<int>> ballsSize;
extern std::vector<Point<int>> ballsSpeed;

extern std::vector<Ball> balls;

Ball* createBall(Point<int> pos, Point<int> size);

void moveBalls();

void updateGravityAndFriction();

void drawBalls(MyTexture* ballTexture);