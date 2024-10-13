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

    void CSurface::Line(int x1, int y1, int x2, int y2, TCOLOR color) const {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = x1 < x2 ? 1 : -1;
        int sy = y1 < y2 ? 1 : -1;
        int err = dx - dy;
        int e2;

        for (;;) {
            mPixelBuffer[y1 * mWidth + x1] = color;
            if (x1 == x2 && y1 == y2) break;
            e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    void CSurface::SetWindow(SDL_Window *window) {
        mWindow = window;
    }

    Core::EErrors CSurface::Init() {
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

    Core::EErrors CSurface::SetColor(int red, int green, int blue, int alpha) {
        SDL_SetRenderDrawColor(mRenderer, red, green, blue, alpha);
        return Core::eNoError;
    }

    Core::EErrors CSurface::Clear() {
        SDL_RenderClear(mRenderer);
        return Core::eNoError;
    }
}