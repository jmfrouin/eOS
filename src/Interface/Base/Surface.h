//
// Created by Jean-Michel Frouin on 07/10/2024.
//

#ifndef SURFACE_H
#define SURFACE_H

#include <stack>
#include <SDL2/SDL.h>
#include <Core/Errors.h>
#include <Interface/Base/Rect.h>
#include <Core/Color.h>

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

    protected:
      virtual void Initialize(int width, int height, int alignment = 2);
      void InitializeScanLines();

    private:
      std::stack<CRect> fRegions;
      TCOLOR* fPixelBuffer{};
      TCOLOR** fScanLines{};
      int fWidth{};
      int fHeight{};
      int fPitch{};
      int fAlignment{};
      SDL_Window* mWindow;
      SDL_Renderer* mRenderer;
  };
}


#endif //SURFACE_H
