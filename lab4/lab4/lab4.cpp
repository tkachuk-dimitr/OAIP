#include <iostream>
#include <climits> 

using namespace std;

#define DIVISOR 6          
#define IS_DIVISIBLE(x) ((x) % DIVISOR == 0) // Макро-функция проверки
#define MSG_NOT_FOUND "Нет чисел, делящихся на 2 и 6!" // Сообщение об ошибке
#define MSG_FOUND "Наименьшее подходящее число: " // Сообщение об успехе



int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество чисел (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер массива должен быть больше 0!" << endl;
        return 1;
    }

    int* arr = new int[n]; 

    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

#ifdef DEBUG_MODE
        cout << "[DEBUG] Элемент [" << i << "] = " << arr[i] << endl;
#endif
    }


    int minVal = INT_MAX; // Начальное значение (максимально возможное)
    bool found = false;   // Флаг наличия подходящего числа

    for (int i = 0; i < n; i++) {
        if (IS_DIVISIBLE(arr[i])) {
            if (arr[i] < minVal) {
                minVal = arr[i];
                found = true;
            }
        }
    }

    
    cout << "\n=== Результат ===" << endl;
    if (found) {
        cout << MSG_FOUND << minVal << endl;
    }
    else {
        cout << MSG_NOT_FOUND << endl;
    }

    delete[] arr; // Удаление динамического массива
    arr = nullptr; // Защита от висячего указателя

    return 0;
}