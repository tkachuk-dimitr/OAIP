#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = 5;
    static double sum = 0;
    static int count = 0;

    int* ptr = arr;

    for (int i = 0; i < size; i++) {
        sum += *ptr; 
        ptr++;        
    }

    count = size;
    double average = sum / count;

 
    cout << "Массив: ";
    ptr = arr; 
    for (int i = 0; i < size; i++) {
        cout << *ptr << " ";
        ptr++;
    }

    cout << "\nСумма: " << sum << endl;
    cout << "Среднее: " << average << endl;

    return 0;
}