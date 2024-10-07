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