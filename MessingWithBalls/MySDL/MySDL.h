#pragma once
#include <SDL.h>

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

class MyTexture;

class MySDL
{
	friend class MyTexture;
public:

	MySDL();
	~MySDL();


	void clearWindow();
	void renderWindow();
private:
	void init();
	void close();

	SDL_Window* sdl_window;
	SDL_Renderer* sdl_renderer;
};

