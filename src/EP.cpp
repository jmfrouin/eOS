#include <iostream>
#include <cmath>
#include <Core/Def.h>

#include "Interface/Base/Surface.h"

#include <Core/Log.h>

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const int MOVE_STEP = 10;
const double PI = 3.14159265358979323846;

struct Triangle {
#ifdef WITH_SDL2
    SDL_Point points[3];
#endif
};

SDL_Point calculateCenter(const Triangle& triangle) {
    int x = (triangle.points[0].x + triangle.points[1].x + triangle.points[2].x) / 3;
    int y = (triangle.points[0].y + triangle.points[1].y + triangle.points[2].y) / 3;
    return {x, y};
}

void rotateTriangle(Triangle& triangle, double angle) {
    SDL_Point center = calculateCenter(triangle);
    double radians = angle * PI / 180.0;
    for (int i = 0; i < 3; ++i) {
        int x = triangle.points[i].x - center.x;
        int y = triangle.points[i].y - center.y;
        triangle.points[i].x = center.x + static_cast<int>(x * cos(radians) - y * sin(radians));
        triangle.points[i].y = center.y + static_cast<int>(x * sin(radians) + y * cos(radians));
    }
}

void drawTriangle(SDL_Renderer* renderer, const Triangle& triangle) {
    SDL_RenderDrawLines(renderer, triangle.points, 3);
    SDL_RenderDrawLine(renderer, triangle.points[2].x, triangle.points[2].y, triangle.points[0].x, triangle.points[0].y);
}

void moveTriangle(Triangle& triangle, int dx, int dy) {
    for (int i = 0; i < 3; ++i) {
        triangle.points[i].x += dx;
        triangle.points[i].y += dy;
    }
}

int main() {
    Core::CLog::Log(__FILE__, __LINE__, "Application started");

#ifdef WITH_SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        Core::CLog::Log(__FILE__, __LINE__, "SDL_Init Error", SDL_GetError());
        return EXIT_FAILURE;
    }
#endif

    Interface::CSurface Surface;
    Core::CLog::Log(__FILE__, __LINE__, "Creation Surface");

#ifdef WITH_SDL2
    SDL_Window* window = SDL_CreateWindow(FULLNAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        Core::CLog::Log(__FILE__, __LINE__, "SDL_CreateWindow Error", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    Surface.SetWindow(window);
#endif

    //Surface.Init(3, 3);
    Surface.Init(WINDOW_WIDTH, WINDOW_HEIGHT);
    TCOLOR Color = 0xDEADCAFE;

    Triangle triangle = {{{40, 30}, {45, 35}, {35, 35}}};

    bool running = true;

#ifdef WITH_SDL2
    SDL_Event event;
#endif
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                Core::CLog::Log(__FILE__, __LINE__, "SDL_QUIT event received");
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                    {
                        moveTriangle(triangle, 0, -MOVE_STEP);
                        Core::CLog::Log(__FILE__, __LINE__, "Triangle moved up");
                        break;
                    }
                    case SDLK_DOWN:
                    {
                        moveTriangle(triangle, 0, MOVE_STEP);
                        Core::CLog::Log(__FILE__, __LINE__, "Triangle moved down");
                        break;
                    }
                    case SDLK_LEFT:
                    {
                        moveTriangle(triangle, -MOVE_STEP, 0);
                        rotateTriangle(triangle, -90);
                        Core::CLog::Log(__FILE__, __LINE__, "Triangle rotated left");
                        break;
                    }
                    case SDLK_RIGHT:
                    {
                        moveTriangle(triangle, MOVE_STEP, 0);
                        rotateTriangle(triangle, 90);
                        Core::CLog::Log(__FILE__, __LINE__, "Triangle rotated right");
                        break;
                    }
                }
            }
        }

        Surface.SetColor(0xff, 0xff, 0xff, 0xff);
        Surface.Clear();

        Surface.SetColor(0, 0, 0, 0xff);
        drawTriangle(Surface.GetRendered(), triangle);

#ifdef WITH_SDL2
        SDL_RenderPresent(Surface.GetRendered());
#endif
    }

#ifdef WITH_SDL2
    SDL_DestroyRenderer(Surface.GetRendered());
    SDL_DestroyWindow(window);
    SDL_Quit();
#endif

    Core::CLog::Log(__FILE__, __LINE__, "Application ended");
    return EXIT_SUCCESS;
}