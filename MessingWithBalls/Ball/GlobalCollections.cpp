#include "GlobalCollections.h"
#include "Ball.h"
#include "../MySDL/MySDL.h"

std::vector<Point<int>> ballsPosition = std::vector<Point<int>>{};
std::vector<Point<int>> ballsSize = std::vector<Point<int>>{};
std::vector<Point<int>> ballsSpeed = std::vector<Point<int>>{};

std::vector<Ball> balls = std::vector<Ball>{};

Ball* createBall(Point<int> pos, Point<int> size)
{
	int idx = balls.size();

	ballsPosition.push_back(pos);
	ballsSize.push_back(size);

	ballsSpeed.push_back({0, 0});

	balls.push_back(Ball{ idx });

	return &(balls[idx]);
}

void moveBalls()
{
	for (int i = 0; i < balls.size(); i++) {
		
		ballsPosition[i] += ballsSpeed[i];
	}
}


#define GRAVITY 10
#define FRICTION 0.1
void updateGravityAndFriction()
{
	for (auto speed : ballsSpeed) {
		speed.y -= GRAVITY;
		speed.x *= (1 - FRICTION);
		speed.y *= (1 - FRICTION);
	}
}

void drawBalls(MyTexture* ballTexture)
{
	for (int i = 0; i < balls.size(); i++) {
		ballTexture->render(ballsSize[i], ballsPosition[i]);
	}
}
