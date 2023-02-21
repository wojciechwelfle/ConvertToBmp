#ifndef BMP_BITMAP_H
#define BMP_BITMAP_H

#include <stdint.h>

typedef struct Bitmap {
    uint8_t ***ptr;
    int32_t width;
    int32_t height;
} Bitmap;

int AllocateBitmap(Bitmap *bitmap, int32_t width, int32_t height);

void FreeBitmap(Bitmap *bitmap);

#endif
