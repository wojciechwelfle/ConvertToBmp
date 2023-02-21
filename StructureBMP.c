#pragma pack(1)

#include "StructureBMP.h"
#include <stdio.h>
#include <stdlib.h>

int FillBMPStruct(struct BMPHeader *bmpHeader, int width, int height);

int CreateBMPFile(const char *restrict filename, Bitmap *bitmap) {
    if (filename == NULL || bitmap->height < 1 || bitmap->width < 1) return EXIT_FAILURE;
    struct BMPHeader bmpHeader;
    FILE *file = fopen(filename, "wb");
    if (file == NULL) return 2;
    FillBMPStruct(&bmpHeader, bitmap->width, bitmap->height);
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);

    int paddingSize = ((4 - (3 * (&bmpHeader)->bmpInfoHeader.width) % 4) % 4);
    uint8_t padding[3] = {0, 0, 0};
    for (int row = 0; row < (&bmpHeader)->bmpInfoHeader.height; ++row) {
        for (int col = 0; col < (&bmpHeader)->bmpInfoHeader.width; ++col) {
            uint8_t R = *(*(*(bitmap->ptr + row) + col) + 0);
            uint8_t G = *(*(*(bitmap->ptr + row) + col) + 1);
            uint8_t B = *(*(*(bitmap->ptr + row) + col) + 2);
            fwrite(&R, sizeof(uint8_t), 1, file);
            fwrite(&G, sizeof(uint8_t), 1, file);
            fwrite(&B, sizeof(uint8_t), 1, file);
        }
        fwrite(&padding, sizeof(uint8_t), paddingSize, file);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

int FillBMPStruct(struct BMPHeader *bmpHeader, int width, int height) {
    if (bmpHeader == NULL || width < 1 || height < 1) return EXIT_FAILURE;

    int paddingSize = ((4 - (3 * width) % 4) % 4);

    /// fill BMP File Header
    bmpHeader->bmpFileHeader.signature = 0x4D42; /// "BM"
    bmpHeader->bmpFileHeader.fileSize = sizeof(BMPHeader) + width * height * 3 + paddingSize * width;
    bmpHeader->bmpFileHeader.reserved1 = 0;
    bmpHeader->bmpFileHeader.reserved2 = 0;
    bmpHeader->bmpFileHeader.offset = sizeof(BMPHeader);

    /// fill BMP Info Header
    bmpHeader->bmpInfoHeader.DIBHeaderSize = sizeof(BMPInfoHeader);
    bmpHeader->bmpInfoHeader.width = width;
    bmpHeader->bmpInfoHeader.height = height;
    bmpHeader->bmpInfoHeader.planes = 1;
    bmpHeader->bmpInfoHeader.bitsPerPixel = 24;
    bmpHeader->bmpInfoHeader.compression = 0;
    bmpHeader->bmpInfoHeader.imageSize = 0;
    bmpHeader->bmpInfoHeader.X_pixelsPerMeter = 0;
    bmpHeader->bmpInfoHeader.Y_pixelsPerMeter = 0;
    bmpHeader->bmpInfoHeader.ColorsInColorTable = 0;
    bmpHeader->bmpInfoHeader.ImportantColorCount = 0;

    return EXIT_SUCCESS;
}
