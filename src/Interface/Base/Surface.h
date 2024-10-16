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
      void Close();
      ~CSurface();

      Core::EErrors Init(int width, int height, int alignment = 2);
      Core::EErrors Clear();
      Core::EErrors SetColor(int red, int green, int blue, int alpha);

      void SetWindow(SDL_Window* window);
      SDL_Renderer* GetRendered() { return mRenderer; }

    protected:
      void Initialize(int width, int height, int alignment);
      void InitializeScanLines();

    public:
      void DrawHLine(int x1, int x2, int y, TCOLOR color) const;
      void DrawVLine(int x, int y1, int y2, TCOLOR color) const;

    private:
      std::stack<CRect> mRegions; // Stack of regions to be drawn
      TCOLOR* mPixelBuffer{}; // Pointer to the start of the pixel data
      TCOLOR** mScanLines{}; // Array of pointers to the start of each row of pixels
      int mDepth{}; // Depth is the number of bytes per pixel
      int mWidth{}; // Width is the number of columns of pixels
      int mHeight{}; // Height is the number of rows of pixels
      int mPitch{}; // Pitch is the number of bytes in a row of pixels
      int mAlignment{}; // Alignment is the number of bytes in a row of pixels
      SDL_Window* mWindow; // Pointer to the window
      SDL_Renderer* mRenderer; // Pointer to the renderer
  };
}


#endif //SURFACE_H
