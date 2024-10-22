#include "Surface.h"
#include <iostream>

namespace Interface {

    // Constructeur par défaut
    CSurface::CSurface() : mWidth(0), mHeight(0), mPixelBuffer(nullptr), mScanlines(nullptr) {}

    // Constructeur avec paramètres
    CSurface::CSurface(int width, int height) : mWidth(width), mHeight(height), mPixelBuffer(nullptr), mScanlines(nullptr) {
        AllocatePixelBuffer();
        AllocateScanlines();
    }

    // Destructeur pour libérer la mémoire
    CSurface::~CSurface() {
        FreePixelBuffer();  // Libère la mémoire du buffer
        FreeScanlines();    // Libère la mémoire des scanlines
    }

    // Alloue la mémoire pour le buffer de pixels
    void CSurface::AllocatePixelBuffer() {
        FreePixelBuffer();  // Libère d'abord l'ancienne mémoire s'il y en a une
        mPixelBuffer = static_cast<TCOLOR*>(malloc(mWidth * mHeight * sizeof(TCOLOR)));
        if (!mPixelBuffer) {
            throw std::runtime_error("Échec de l'allocation mémoire pour le buffer de pixels");
        }
    }

    // Libère la mémoire du buffer de pixels
    void CSurface::FreePixelBuffer() {
        if (mPixelBuffer != nullptr) {
            free(mPixelBuffer);
            mPixelBuffer = nullptr;
        }
    }

    // Alloue la mémoire pour les scanlines
    void CSurface::AllocateScanlines() {
        FreeScanlines();  // Libère d'abord l'ancienne mémoire s'il y en a une
        mScanlines = static_cast<TCOLOR**>(malloc(mHeight * sizeof(TCOLOR*)));
        if (!mScanlines) {
            throw std::runtime_error("Échec de l'allocation mémoire pour les scanlines");
        }
        for (int y = 0; y < mHeight; ++y) {
            mScanlines[y] = &mPixelBuffer[y * mWidth]; // Pointer vers la bonne position dans mPixelBuffer
        }
    }

    // Libère la mémoire des scanlines
    void CSurface::FreeScanlines() {
        if (mScanlines != nullptr) {
            free(mScanlines); // On ne libère pas chaque scanline car elles pointent vers mPixelBuffer
            mScanlines = nullptr;
        }
    }

    // Getter pour mWidth
    int CSurface::GetWidth() const {
        return mWidth;
    }

    // Setter pour mWidth
    void CSurface::SetWidth(int width) {
        mWidth = width;
        AllocatePixelBuffer();  // Réalloue le buffer lors d'un changement de taille
        AllocateScanlines();    // Réalloue les scanlines
    }

    // Getter pour mHeight
    int CSurface::GetHeight() const {
        return mHeight;
    }

    // Setter pour mHeight
    void CSurface::SetHeight(int height) {
        mHeight = height;
        AllocatePixelBuffer();  // Réalloue le buffer lors d'un changement de taille
        AllocateScanlines();    // Réalloue les scanlines
    }

    // Accéder à un pixel à une position donnée (x, y)
    TCOLOR CSurface::GetPixel(int x, int y) const {
        if (x >= 0 && x < mWidth && y >= 0 && y < mHeight) {
            return mPixelBuffer[y * mWidth + x]; // Accès par buffer
        } else {
            throw std::out_of_range("Coordonnées hors de la surface !");
        }
    }

    // Modifier un pixel à une position donnée (x, y)
    void CSurface::SetPixel(int x, int y, TCOLOR color) {
        if (x >= 0 && x < mWidth && y >= 0 && y < mHeight) {
            mPixelBuffer[y * mWidth + x] = color; // Modification par buffer
        } else {
            throw std::out_of_range("Coordonnées hors de la surface !");
        }
    }

    // Accéder à une scanline entière
    TCOLOR* CSurface::GetScanline(int y) const {
        if (y < 0 || y >= mHeight) {
            throw std::out_of_range("Scanline hors de la surface !");
        }
        return mScanlines[y]; // Retourne la scanline
    }

    // Modifier une scanline entière
    void CSurface::SetScanline(int y, const TCOLOR* scanline) {
        if (y < 0 || y >= mHeight) {
            throw std::out_of_range("Scanline hors de la surface !");
        }
        for (int x = 0; x < mWidth; ++x) {
            mScanlines[y][x] = scanline[x]; // Modification par scanline
        }
    }

    // Affichage des dimensions
    void CSurface::PrintDimensions() const {
        std::cout << "Width: " << mWidth << ", Height: " << mHeight << std::endl;
    }

    // Blit la surface dans une texture SDL
    SDL_Texture* CSurface::CreateTexture(SDL_Renderer* renderer) {
        SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, mWidth, mHeight);
        if (!texture) {
            throw std::runtime_error("Échec de la création de la texture SDL");
        }
        return texture;
    }

    // Met à jour la texture avec les pixels
    void CSurface::UpdateTexture(SDL_Texture* texture) {
        SDL_UpdateTexture(texture, nullptr, mPixelBuffer, mWidth * sizeof(TCOLOR));
    }

}