#pragma pack(1)

#ifndef StructureBMP_H
#define StructureBMP_H

#include <stdint.h>
#include "Bitmap.h"

typedef struct {
    uint16_t signature;                  /// File Type (set as "BM")
    uint32_t fileSize;                   /// File Size in bytes (size = sizeof(BMPHeader) + width + height)
    uint16_t reserved1;                  /// Reserved (set as 0)
    uint16_t reserved2;                  /// Reserved (set as 0)
    uint32_t offset;                     /// File Offset to PixelArray (set as 54 - size of BMPHeader)
} BMPFileHeader;

typedef struct {
    uint32_t DIBHeaderSize;              /// Size of BMPFileHeader (set as 14 - size of BMPFileHeader)
    int32_t width;                       /// Bitmap width
    int32_t height;                      /// Bitmap height
    uint16_t planes;                     /// Planes (set as 1)
    uint16_t bitsPerPixel;               /// Bits per pixel (set as 1,4,8,16,24)
    uint32_t compression;                /// Compression Type (0 - without compression)
    uint32_t imageSize;                  /// Pixel array fileSize in bytes (set as 0)
    int32_t X_pixelsPerMeter;            /// Resolution X (set as 0)
    int32_t Y_pixelsPerMeter;            /// Resolution Y (set as 0)
    uint32_t ColorsInColorTable;         /// (set as 0)
    uint32_t ImportantColorCount;        /// (set as 0)
} BMPInfoHeader;

typedef struct BMPHeader {
    BMPFileHeader bmpFileHeader;
    BMPInfoHeader bmpInfoHeader;
} BMPHeader;

int CreateBMPFile(const char *restrict filename, Bitmap *bitmap);

#endif
