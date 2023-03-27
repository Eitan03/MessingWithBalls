#include "MyTexture.h"
#include <SDL_image.h>

MyTexture::MyTexture(std::string path, MySDL* mySDL)
{
	this->mySDL = mySDL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		throw std::exception((std::string("Unable to load image") + path + "!SDL_image Error : " + IMG_GetError()).c_str());
	}

	//Color key image
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	//Create texture from surface pixels
	this->sdl_texture = SDL_CreateTextureFromSurface(mySDL->sdl_renderer, loadedSurface);
	if (this->sdl_texture == NULL)
	{
		std::string err = (std::string("Unable to create texture from ") + path + "!SDL Error : " + SDL_GetError()).c_str();
		throw std::exception(err.c_str());
	}

	//Get image dimensions
	this->width = loadedSurface->w;
	this->height = loadedSurface->h;

	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
}

MyTexture::~MyTexture()
{
	//Free texture if it exists
	if (this->sdl_texture != NULL)
	{
		SDL_DestroyTexture(this->sdl_texture);
		this->sdl_texture = NULL;
		this->width = 0;
		this->height = 0;
	}
}

void MyTexture::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, this->width, this->height };

	SDL_RenderCopy(this->mySDL->sdl_renderer, this->sdl_texture, NULL, &renderQuad);
}
