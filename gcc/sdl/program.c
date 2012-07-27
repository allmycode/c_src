#include <stdio.h>
#include "SDL.h"

int main(int argc, char *argv[]) {
  SDL_Surface *screen;
  SDL_Surface *image;
  SDL_Rect rect;
  SDL_Event event;
  SDL_Event tmp_event;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr ,"Unable to inintialize Video: %s\n", SDL_GetError());
    return -1;
  }


  screen = SDL_SetVideoMode(800, 600, 16, SDL_SWSURFACE | SDL_FULLSCREEN);
  if (screen == NULL) {
    fprintf(stderr, "Unable to set video mode %s\n", SDL_GetError());
    return -1;
  }

  image = SDL_LoadBMP("duke.bmp");
  if (image == NULL) {
    fprintf(stderr, "Uanble to load picture %s\n", SDL_GetError());
    return -1;
  }

  rect.x = 0;
  rect.y = 0;
  rect.w = 800;
  rect.h = 600;

  while(SDL_WaitEvent(&event)) {
    switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        printf("User Hit ESC, quitting...\n");
        tmp_event.type = SDL_QUIT;
        SDL_PushEvent(&tmp_event); break;
      default:
        break;
      }
      break;
    case SDL_QUIT:
      printf("...\n");
      exit(0);
      break;
    default:
      break;
    }

    if (SDL_MUSTLOCK(screen))
      SDL_LockSurface(screen);

    SDL_BlitSurface(image, NULL, screen, &rect);

    if (SDL_MUSTLOCK(screen))
      SDL_UnlockSurface(screen);
    
    SDL_UpdateRect(screen, 0, 0, 0, 0);
  }
  
  return 0;
}
