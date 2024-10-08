//
// Created by Jean-Michel Frouin on 07/10/2024.
//

#include "Surface.h"
#include <iostream>

namespace Interface {
    CSurface::CSurface(SDL_Window* window):
    mWindow(window), mRenderer(nullptr)
    {

    }

    CSurface::CSurface():
    mWindow(nullptr), mRenderer(nullptr)
    {

    }

    CSurface::~CSurface()
    {

    }

    void CSurface::Initialize(int width, int height, int alignment)
    {
        fWidth = width;
        fHeight = height;
        fAlignment = alignment;
        fPitch = fWidth * 4;
        fPixelBuffer = new TCOLOR[fWidth * fHeight];
        InitializeScanLines();
    }

    void CSurface::InitializeScanLines()
    {
        if (!fScanLines)
        fScanLines = new TCOLOR*[fHeight];
        for (int i = 0; i < fHeight; i++) {
            fScanLines[i] = fPixelBuffer + i * fWidth;
        }
    }

    
void XSurface::InitializeScanLines()
{
  if (!fScanLines)
    fScanLines = (TCOLOR**)XMemory::Malloc(fHeight * sizeof(TCOLOR*));
  for(int sl=fPitch<0?(fHeight-1)*-fPitch:0, i=fHeight, j=0; --i>=0; sl+=fPitch, j++)
    fScanLines[j]=&fPixelBuffer[sl];
}

void XSurface::Initialize(int width, int height, int alignment)
{
  // do not free/alloc the same surface
  if ((fPixelBuffer != NULL) &&
      (width == fWidth) &&
      (height == fHeight) &&
      (alignment == fAlignment)) return;

  Close();
  fWidth = width > 0 ? width : 1;
  fHeight = height > 0 ? height : 1;
  // Alignment MUST be a multiple of 2
  fAlignment = alignment;
  fPitch = (width + (alignment-1)) & -alignment;
  fPixelBuffer = (TCOLOR*)XMemory::Malloc(fHeight * (fPitch<0?-fPitch:fPitch) * sizeof(TCOLOR));
  PushRegion(XRect(0, 0, fWidth, fHeight));
}

    void CSurface::SetWindow(SDL_Window* window)
    {
        mWindow = window;
    }

    Core::EErrors CSurface::Init()
    {
        mRenderer = SDL_CreateRenderer(mWindow, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!mRenderer) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(mWindow);
            SDL_Quit();
            return Core::eAccessDenied;
        }
        return Core::eNoError;
    }

    Core::EErrors CSurface::SetColor(int red, int green, int blue, int alpha)
    {
        SDL_SetRenderDrawColor(mRenderer, red, green, blue, alpha);
        return Core::eNoError;
    }


    Core::EErrors CSurface::Clear()
    {
        SDL_RenderClear(mRenderer);
        return Core::eNoError;
    }




}