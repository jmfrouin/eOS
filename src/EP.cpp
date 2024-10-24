#include <SDL2/SDL.h>
#include <Interface/Base/Surface.h>
#include <Core/Def.h>
#include <iostream>

#define WIDTH 1024
#define HEIGHT 768


int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Échec de l'initialisation de SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Créer une fenêtre
    SDL_Window* window = SDL_CreateWindow(FULLNAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Échec de la création de la fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Créer un renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Échec de la création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Création d'une surface
    Interface::CSurface surface(WIDTH, HEIGHT);
    surface.PrintDimensions(); // Affichage des dimensions

    // Définir la couleur d'une scanline
    Interface::TCOLOR green = 0x00FF00; // Couleur verte
    Interface::TCOLOR scanline[WIDTH]; // Création d'une scanline
    std::fill_n(scanline, WIDTH, green); // Remplir la scanline de vert
    surface.SetScanline(100, scanline); // Définir la scanline à la ligne 100

    for(int i=0; i<WIDTH; i++) {
        scanline[i] = 0xFF0000; // Rouge
    }

    for (int i = 0; i < HEIGHT; i+=5) {
        for(int k=0; k<WIDTH; k+=9) {
            surface.SetPixel(k, i, 0x0000FF); // Bleu
        }
    }
    surface.SetScanline(200, scanline); // Définir la scanline à la ligne 100
    // Créer une texture SDL et mettre à jour avec les pixels
    SDL_Texture* texture = surface.CreateTexture(renderer);
    surface.UpdateTexture(texture);

    // Boucle principale pour afficher la fenêtre
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Effacer l'écran
        SDL_RenderClear(renderer);

        // Rendre la texture
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

        // Afficher le rendu
        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}