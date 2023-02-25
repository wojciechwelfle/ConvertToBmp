#include <stdlib.h>

#pragma pack(1)

#include "Bitmap.h"
#include "StructureBMP.h"

int main() {
    Bitmap bmp;
    int32_t width = 50, height = 50;
    int err = AllocateBitmap(&bmp, width, height);

    if(err != 0) {
        FreeBitmap(&bmp);
        exit(1);
    }

    GenerateRandomColors(&bmp, RGB);

    CreateBMPFile("test.bmp", &bmp);
    FreeBitmap(&bmp);
    return 0;
}