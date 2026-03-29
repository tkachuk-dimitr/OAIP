#include <iostream>
#include "array_lib.h" // Подключаем заголовок библиотеки

int main() {
    int size = 5;

    // Используем функции из пространства имен вашей библиотеки
    int* data = ArrayUtils::allocate_array(size);

    if (data != nullptr) {
        ArrayUtils::initialize_array(data, size);
        std::cout << "Array: ";
        ArrayUtils::print_array(data, size);

        std::cout << "Max: " << ArrayUtils::find_max(data, size) << std::endl;

        ArrayUtils::free_array(data);
    }

    return 0;
}
