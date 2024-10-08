#ifndef _COLOR_H_
#define _COLOR_H_

// Component bit length
#define RBITS 5
#define GBITS 6
#define BBITS 5
// Component shift level
#define RSHIFT ((BBITS)+(GBITS))
#define GSHIFT (BBITS)
#define BSHIFT 0
// Component unshifted masks
#define RUSMASK ((1<<(RBITS))-1)
#define GUSMASK ((1<<(GBITS))-1)
#define BUSMASK ((1<<(BBITS))-1)
// Component shifted masks
#define RSMASK ((RUSMASK)<<(RSHIFT))
#define GSMASK ((GUSMASK)<<(GSHIFT))
#define BSMASK ((BUSMASK)<<(BSHIFT))

#define _PRGB_(c) ((int)((c)&0xFFFFFF))
#define COLOR(c) (TCOLOR)( ((_PRGB_(c) >> (16-RSHIFT+(8-RBITS))) & RSMASK) |\
                           ((_PRGB_(c) >> ( 8-GSHIFT+(8-GBITS))) & GSMASK) |\
                           ((_PRGB_(c) >> ( 0-BSHIFT+(8-BBITS))) & BSMASK) )

// Pixel size
typedef unsigned short TCOLOR;

// Pixel functions
#define PixelMemcpy  XMemory::Memcpy16
#define PixelMemcpyi XMemory::Memcpy16i
#define PixelMemset  XMemory::Memset16

#define CONVERT2RGB(c) ((c & RSMASK) << (24-(RBITS+GBITS+BBITS))) + ((c & GSMASK) << (16-(GBITS+BBITS))) + ((c & BSMASK) << ( 8-BBITS))

#define ALPHA_BITS 5
#define ALPHA_LEVEL (1 << (ALPHA_BITS))
#define ALPHA_SHIFT (RSHIFT)
#define ALPHA_UMASK ((ALPHA_LEVEL) - 1)
#define ALPHA_SMASK ((ALPHA_UMASK) << (ALPHA_SHIFT))

#endif
