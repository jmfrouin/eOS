//
// Created by Jean-Michel Frouin on 07/10/2024.
//
// Doc : https://jsandler18.github.io/extra/framebuffer.html

#ifndef SURFACE_H
#define SURFACE_H

#include <stack>
#include <SDL2/SDL.h>
#include <Core/Errors.h>
#include <Interface/Base/Rect.h>
#include "Color.h"

namespace Interface {

  class CSurface {
    public:
      CSurface();
      explicit CSurface(SDL_Window* window);
      ~CSurface();

      Core::EErrors Init();
      Core::EErrors Clear();
      Core::EErrors SetColor(int red, int green, int blue, int alpha);

      void SetWindow(SDL_Window* window);
      SDL_Renderer* GetRendered() { return mRenderer; }

    protected:
      void Initialize(int width, int height, int alignment = 2);
      void InitializeScanLines();
      void Line(int x1, int y1, int x2, int y2, TCOLOR color) const;

      bool PushRegion(const CRect&);

    private:
      std::stack<CRect> mRegions;
      TCOLOR* mPixelBuffer{};
      TCOLOR** mScanLines{};
      int mWidth{};
      int mHeight{};
      int mPitch{};
      int mAlignment{};
      SDL_Window* mWindow;
      SDL_Renderer* mRenderer;
  };
}


#endif //SURFACE_H
