#ifndef SURFACE_H
#define SURFACE_H

#include <cstdlib>  // Pour malloc et free
#include <cstdint>  // Pour uint32_t
#include <stdexcept> // Pour gestion des exceptions
#include <SDL2/SDL.h> // Inclure la bibliothèque SDL

namespace Interface {

    // Définition du type TCOLOR pour représenter une couleur
    using TCOLOR = uint32_t;

    class CSurface {
    private:
        int mWidth;           // Largeur de la surface
        int mHeight;          // Hauteur de la surface
        TCOLOR* mPixelBuffer; // Buffer de pixels (TCOLOR)
        TCOLOR** mScanlines;  // Tableau de scanlines (TCOLOR**)

    public:
        // Constructeur par défaut
        CSurface();

        // Constructeur avec paramètres
        CSurface(int width, int height);

        // Destructeur pour libérer la mémoire
        ~CSurface();

        // Alloue la mémoire pour le buffer de pixels
        void AllocatePixelBuffer();

        // Libère la mémoire du buffer de pixels
        void FreePixelBuffer();

        // Alloue la mémoire pour les scanlines
        void AllocateScanlines();

        // Libère la mémoire des scanlines
        void FreeScanlines();

        // Getter pour mWidth
        int GetWidth() const;

        // Setter pour mWidth
        void SetWidth(int width);

        // Getter pour mHeight
        int GetHeight() const;

        // Setter pour mHeight
        void SetHeight(int height);

        // Accéder à un pixel à une position donnée (x, y)
        TCOLOR GetPixel(int x, int y) const;

        // Modifier un pixel à une position donnée (x, y)
        void SetPixel(int x, int y, TCOLOR color);

        // Accéder à une scanline entière
        TCOLOR* GetScanline(int y) const;

        // Modifier une scanline entière
        void SetScanline(int y, const TCOLOR* scanline);

        // Affichage des dimensions
        void PrintDimensions() const;

        // Blit la surface dans une texture SDL
        SDL_Texture* CreateTexture(SDL_Renderer* renderer);

        // Met à jour la texture avec les pixels
        void UpdateTexture(SDL_Texture* texture);
    };

}

#endif // SURFACE_H