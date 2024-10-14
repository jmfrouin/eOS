//
// Created by Jean-Michel Frouin on 07/10/2024.
//

#include "Surface.h"
#include <iostream>

namespace Interface {
    CSurface::CSurface(SDL_Window *window) :
            mWindow(window), mRenderer(nullptr) {

    }

    CSurface::CSurface() :
    mWindow(nullptr), mRenderer(nullptr) {
        mWidth = mHeight = mPitch = mAlignment = -1;
        mPixelBuffer = nullptr;
        mScanLines = nullptr;
    }

    CSurface::~CSurface()
    = default;

    void CSurface::Initialize(int width, int height, int alignment) {
        mWidth = width;
        mHeight = height;
        mAlignment = alignment;
        mPitch = mWidth * 4;
        mPixelBuffer = new TCOLOR[mWidth * mHeight];
    }

    void CSurface::DrawHLine(int x1, int x2, int y, TCOLOR color) const {
        for (int x = x1; x <= x2; ++x) {
            mPixelBuffer[y * mWidth + x] = color;
        }
    }

    void CSurface::DrawVLine(int x, int y1, int y2, TCOLOR color) const {
        for (int y = y1; y <= y2; ++y) {
            mPixelBuffer[y * mWidth + x] = color;
        }
    }

    void CSurface::SetWindow(SDL_Window *window) {
        mWindow = window;
    }

    Core::EErrors CSurface::Init(int width, int height,int alignment) {
        mRenderer = SDL_CreateRenderer(mWindow, -1,
                                       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!mRenderer) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(mWindow);
            SDL_Quit();
            return Core::eAccessDenied;
        }
        Initialize(width, height, alignment);
        return Core::eNoError;
    }

    Core::EErrors CSurface::SetColor(int red, int green, int blue, int alpha) {
        SDL_SetRenderDrawColor(mRenderer, red, green, blue, alpha);
        return Core::eNoError;
    }

    Core::EErrors CSurface::Clear() {
        SDL_RenderClear(mRenderer);
        return Core::eNoError;
    }
}