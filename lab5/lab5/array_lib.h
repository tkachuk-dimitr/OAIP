#pragma once

#ifdef ARRAYLIB_EXPORTS
#define ARRAY_API __declspec(dllexport)
#else
#define ARRAY_API __declspec(dllimport)
#endif

namespace ArrayUtils {
    extern "C" ARRAY_API int* allocate_array(int size);
    extern "C" ARRAY_API void initialize_array(int* arr, int size);
    extern "C" ARRAY_API void print_array(int* arr, int size);
    extern "C" ARRAY_API int find_max(int* arr, int size);
    extern "C" ARRAY_API void free_array(int* arr);
}
