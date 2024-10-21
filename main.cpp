// #include "SDL2/SDL.h"
// #include "SDL2/SDL_image.h"
// #include "SDL2/SDL_mixer.h"
// #include "SDL2/SDL_ttf.h"
 
// int main (int argc, char** argv) {
 
//     /* Inicializa todas as bibliotecas */
//     SDL_Init(SDL_INIT_EVERYTHING);
//     IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
//     Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
//     TTF_Init();
 
//     /* Fecha todas */
//     TTF_Quit();
//     Mix_Quit();
//     IMG_Quit();
//     SDL_Quit();
 
//     return 0;
// }

#include <SDL2/SDL.h>
#include <iostream>

class SDLWindow {
    SDL_Window* window;
    public:
    SDLWindow(const char* title) : window(SDL_CreateWindow(title, 0, 0, 800, 600, SDL_WINDOW_SHOWN)) {}

    ~SDLWindow() {
        SDL_DestroyWindow(window);
    }
};

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDLWindow mywindow("My window");
    SDL_Delay(5000);

    SDL_Quit();

    return 0;
}