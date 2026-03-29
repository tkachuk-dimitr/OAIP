#include "pch.h" // ЭТА СТРОКА ДОЛЖНА БЫТЬ ПЕРВОЙ
#include "array_lib.h"
#include <iostream>

namespace ArrayUtils {

    int* allocate_array(int size) {
        if (size <= 0) return nullptr;
        return new (std::nothrow) int[size];
    }

    void initialize_array(int* arr, int size) {
        if (arr == nullptr) return;
        for (int i = 0; i < size; i++) {
            arr[i] = i * 10;
        }
    }

    void print_array(int* arr, int size) {
        if (arr == nullptr) return;
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int find_max(int* arr, int size) {
        if (arr == nullptr || size <= 0) return 0;
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }

    void free_array(int* arr) {
        delete[] arr;
    }

} 
