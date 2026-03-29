#include <iostream>
#include <string>
using namespace std;
string books[100];
static int totalBooks = 0;
void addBook() {
    string bookName;
    int bookId;

    cout << "\n=== Добавление книги ===" << endl;
    cout << "Введите название книги: ";
    cin >> bookName;
    books[totalBooks] = bookName;
    bookId = totalBooks + 1;

    totalBooks++;

    cout << "Книга добавлена! ID: " << bookId << endl;
}
void viewBooks() {
    cout << "\n=== Список книг ===" << endl;

    if (totalBooks == 0) {
        cout << "Библиотека пуста!" << endl;
        return;
    }
    register int i;

    for (i = 0; i < totalBooks; i++) {
        cout << "ID " << (i + 1) << ": " << books[i] << endl;
    }

    cout << "Всего книг: " << totalBooks << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        cout << "\n=== БИБЛИОТЕКА ===" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Показать все книги" << endl;
        cout << "3. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            viewBooks();
            break;
        case 3:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 3);

    return 0;
}