#include <SDL.h>
#include <iostream>

#include "./MySDL/MySDL.h"
#include "./MySDL/MyTexture.h"

#include "Ball/GlobalCollections.h"

int main(int argc, char* args[])
{
    Point<int> screenSize = { 1280, 960 };
    MySDL mySDL = MySDL(screenSize);
    
    MyTexture ballTexture = MyTexture(std::string("assests\\Ball.png"), &mySDL);
    
    createBall(screenSize / 2, { 128, 128 });
    createBall({0, 0}, {128, 128});


    //Hack to get window to stay up
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) { quit = true; }
        }
        mySDL.clearWindow();
        drawBalls(&ballTexture);
        mySDL.renderWindow();
    }

    return 0;
}
