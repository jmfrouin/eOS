//
// Created by Jean-Michel Frouin on 20/10/2024.
//

#include "SystemSurface.h"
#include <Core/Memory.h>

namespace Interface {
    CSystemSurface() : CSurface() {
        mBuffer = 0;
    }

    void CSystemSurface::Initialize(int width, int height, int alignment) {
        // do not free/alloc the same surface
        if (mPixelBuffer && mWidth == width && height == mHeight && alignment == mAlignment)
            return;

        Close();

        mWidth = width;
        mHeight = height;
        mAlignment = alignment;

        mPixelBuffer = (TCOLOR*)Core::CMemory::Malloc(mWidth * mHeight * sizeof(TCOLOR));
        Core::CMemory::Set(mPixelBuffer, 0xffffffff, mWidth * mHeight * sizeof(TCOLOR));

        fScreenBuffer = (int*)Core::CMemory::Malloc(mWidth * mHeight * sizeof(int));
        fBuffer = XCreateImage(gDisplay, CopyFromParent, 24, ZPixmap,0 ,(char*)fScreenBuffer, mWidth, mHeight, 8, 0);

        fPitch = mWidth;
    }

    void CSystemSurface::Close()
    {
        CSurface::Close();
        if(mPixelBuffer)
        {
            delete mPixelBuffer;
            mPixelBuffer  = nullptr;
        }
        if(mBuffer)
        {
            XDestroyImage(mBuffer);
            mBuffer       = nullptr;
            fScreenBuffer = NULL;
        }
        mBuffer = nullptr;
    }

    CSystemSurface::CSystemSurface() {

    }
} // UI