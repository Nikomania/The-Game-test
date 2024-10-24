#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("Uepa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  // SDL_Surface* surface = SDL_LoadBMP("../gojo.bmp");
  // SDL_Texture* gojo = SDL_CreateTextureFromSurface(renderer, surface);
  // SDL_FreeSurface(surface);

  SDL_Texture * gojo = IMG_LoadTexture(renderer, "../gojo.jpeg"); 

  SDL_Rect rect, rect2;

  rect.x = 20;
  rect.y = 20;
  // rect.w = surface->w;
  // rect.h = surface->h;
  rect.w = 760;
  rect.h = 760;

  rect2.x = 300;
  rect2.y = 300;
  rect2.w = 100;
  rect2.h = 100;

  bool isDone = false;
  // int times_moved = 0;
  while (!isDone)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          isDone = true;
          // SDL_Log("Program quit after %i ticks", event.quit.timestamp);
          break;
        case SDL_MOUSEBUTTONDOWN:
          rect2.x -= 20;
          break;
        // case SDL_MOUSEMOTION:
        //   SDL_Log("Moused moved %d times\n", ++times_moved);
        //   break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, gojo, NULL, &rect);
    SDL_SetRenderDrawColor(renderer, 150, 20, 20, 255);
    SDL_RenderDrawRect(renderer, &rect2);
    // SDL_RenderFillRect(renderer, &rect2);
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(gojo);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}