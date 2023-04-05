#include "MySDL.h"
#include <SDL_image.h>
#include <iostream>

void MySDL::init(Point<int> windowSize)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception((std::string("SDL could not initialize! SDL Error: ") + SDL_GetError()).c_str());
	}
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0))
	{
		printf("Warning: Couldnt set render scale qulity!");
	}

	//Create window
	sdl_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize.x, windowSize.y, SDL_WINDOW_SHOWN);
	if (sdl_window == NULL)
	{
		throw std::exception((std::string("Window could not be created! SDL Error: ") + SDL_GetError()).c_str());
	}
	//Create vsynced renderer for window
	sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
	if (sdl_renderer == NULL)
	{
		throw std::exception((std::string("Renderer could not be created! SDL Error: ") + SDL_GetError()).c_str());
	}
	//Initialize renderer color
	SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		throw std::exception((std::string("Renderer could not be created! SDL Error: ") + SDL_GetError()).c_str());
	}
}

void MySDL::close()
{
	// Free loaded images
	// gDotTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	sdl_window = NULL;
	sdl_renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

MySDL::MySDL(Point<int> windowSize)
{
	init(windowSize);
}

MySDL::~MySDL()
{
	close();
}

void MySDL::clearWindow()
{
	SDL_SetRenderDrawColor(this->sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(this->sdl_renderer);
}

void MySDL::renderWindow()
{
	SDL_RenderPresent(this->sdl_renderer);
}

