#include <SDL.h>
#include <iostream>

#include "./MySDL/MySDL.h"
#include "./MySDL/MyTexture.h"

int main(int argc, char* args[])
{
    
    MySDL mySDL= MySDL();
    
    MyTexture ball = MyTexture(std::string("D:\\Projects\\C++\\MessingWithBalls\\MessingWithBalls\\assests\\Ball.png"), &mySDL);



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
        ball.render(0, 0);
        mySDL.renderWindow();
    }

    return 0;
}
