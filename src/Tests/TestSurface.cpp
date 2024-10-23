//
// Created by Jean-Michel Frouin on 23/10/2024.
//
#include <gtest/gtest.h>
#include "Surface.h"

namespace Interface {

    // Test fixture for CSurface
    class CSurfaceTest : public ::testing::Test {
    protected:
        CSurface* surface;

        void SetUp() override {
            surface = new CSurface(10, 10); // Initialize with a 10x10 surface
        }

        void TearDown() override {
            delete surface;
        }
    };

    // Test default constructor
    TEST_F(CSurfaceTest, DefaultConstructor) {
        CSurface defaultSurface;
        EXPECT_EQ(defaultSurface.GetWidth(), 0);
        EXPECT_EQ(defaultSurface.GetHeight(), 0);
    }

    // Test parameterized constructor
    TEST_F(CSurfaceTest, ParameterizedConstructor) {
        EXPECT_EQ(surface->GetWidth(), 10);
        EXPECT_EQ(surface->GetHeight(), 10);
    }

    // Test SetWidth and GetWidth
    TEST_F(CSurfaceTest, SetGetWidth) {
        surface->SetWidth(20);
        EXPECT_EQ(surface->GetWidth(), 20);
    }

    // Test SetHeight and GetHeight
    TEST_F(CSurfaceTest, SetGetHeight) {
        surface->SetHeight(20);
        EXPECT_EQ(surface->GetHeight(), 20);
    }

    // Test GetPixel and SetPixel
    TEST_F(CSurfaceTest, GetSetPixel) {
        TCOLOR color = 0xFF00FF00; // ARGB format
        surface->SetPixel(5, 5, color);
        EXPECT_EQ(surface->GetPixel(5, 5), color);
    }

    // Test GetScanline and SetScanline
    TEST_F(CSurfaceTest, GetSetScanline) {
        TCOLOR scanline[10] = {0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF};
        surface->SetScanline(0, scanline);
        TCOLOR* retrievedScanline = surface->GetScanline(0);
        for (int i = 0; i < 10; ++i) {
            EXPECT_EQ(retrievedScanline[i], scanline[i]);
        }
    }

    // Test CreateTexture and UpdateTexture
    TEST_F(CSurfaceTest, CreateUpdateTexture) {
        SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 10, 10, SDL_WINDOW_HIDDEN);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_Texture* texture = surface->CreateTexture(renderer);
        ASSERT_NE(texture, nullptr);
        surface->UpdateTexture(texture);
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }
}