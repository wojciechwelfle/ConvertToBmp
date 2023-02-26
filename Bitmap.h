#ifndef BMP_BITMAP_H
#define BMP_BITMAP_H

#include <stdint.h>

enum type {
    RGB = 1,
    MONOCHROME = 2
};

typedef struct Bitmap {
    uint8_t ***ptr;
    int32_t width;
    int32_t height;
} Bitmap;

int AllocateBitmap(Bitmap *bitmap, int32_t width, int32_t height);

void FreeBitmap(Bitmap *bitmap);

void GenerateRandomColors(Bitmap *bitmap, enum type);

void NegativeBitmap(Bitmap *bitmap);

void BinaryConversionBitmap(Bitmap *bitmap);

#endif
