cmake_minimum_required(VERSION 3.24)
project(ConvertToBmp C)

set(CMAKE_C_STANDARD 11)

add_executable(ConvertToBmp
        main.c StructureBMP.h StructureBMP.c Bitmap.h Bitmap.c)
