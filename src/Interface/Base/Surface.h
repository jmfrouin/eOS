//
// Created by Jean-Michel Frouin on 07/10/2024.
//

#ifndef SURFACE_H
#define SURFACE_H

#include <SDL2/SDL.h>

#include <Core/Errors.h>

namespace Interface {

  class CSurface {
    public:
      CSurface();
      CSurface(SDL_Window* window);
      ~CSurface();

      Core::EErrors Init();
      Core::EErrors Clear();
      Core::EErrors SetColor(int red, int green, int blue, int alpha);

      void SetWindow(SDL_Window* window);
      SDL_Renderer* GetRendered() { return mRenderer; }

    private:
      SDL_Window* mWindow;
      SDL_Renderer* mRenderer;
  };
}


#endif //SURFACE_H
