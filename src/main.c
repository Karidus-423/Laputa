// Create a window using SDL
//

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

int main(int argc, char *args[]) {
  SDL_Window *window = NULL;
  SDL_Surface *surface = NULL;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL not initiated. SDL ERROR: %s\n", SDL_GetError());
  }

  window = SDL_CreateWindow("La Puta", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (window == NULL) {
    SDL_Log("SDL window not created. SDL ERROR: %s\n", SDL_GetError());
  }

  surface = SDL_GetWindowSurface(window);
  SDL_FillSurfaceRect(surface, NULL,
                      SDL_MapSurfaceRGB(surface, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window);

  // Hack to get window to stay up
  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT)
        quit = true;
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
