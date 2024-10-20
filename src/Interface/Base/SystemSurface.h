//
// Created by Jean-Michel Frouin on 20/10/2024.
//

#ifndef EOS_SYSTEMSURFACE_H
#define EOS_SYSTEMSURFACE_H

#include "Surface.h"

namespace Interface {

    class CSystemSurface : public CSurface {
    public:
        CSystemSurface();
        virtual ~CSystemSurface() = 0;
        void SystemBlit(IGC& dst, int dx, int dy, int sx, int sy, int w, int h);
        virtual void Initialize(int width, int height, int alignment = 4);
        virtual void Close();
        void LockHeap() {}
        void UnlockHeap() {}

    protected:
        Bitmap mBuffer;
        int* mScreenBuffer;
    };

} // UI

#endif //EOS_SYSTEMSURFACE_H
