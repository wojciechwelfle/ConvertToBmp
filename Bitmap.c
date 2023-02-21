#include "Bitmap.h"
#include <stdlib.h>

#define COLORS_RGB 3

int AllocateBitmap(Bitmap *bitmap, int32_t width, int32_t height) {
    if (bitmap == NULL || width < 1 || height < 1) return 1;
    bitmap->height = height;
    bitmap->width = width;
    bitmap->ptr = (uint8_t ***) calloc(bitmap->height, sizeof(uint8_t **));
    if (bitmap->ptr == NULL) return 2;
    for (int row = 0; row < bitmap->height; ++row) {
        *(bitmap->ptr + row) = (uint8_t **) calloc(bitmap->width, sizeof(uint8_t *));
        if (*(bitmap->ptr + row) == NULL) return FreeBitmap(bitmap), 2;
        for (int col = 0; col < bitmap->width; ++col) {
            *(*(bitmap->ptr + row) + col) = (uint8_t *) calloc(COLORS_RGB, sizeof(uint8_t));
            if (*(*(bitmap->ptr + row) + col) == NULL) return FreeBitmap(bitmap), 2;
        }
    }
    return 0;
}

