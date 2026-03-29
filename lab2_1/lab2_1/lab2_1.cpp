#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int len(const char* s) { int i = 0; while (s[i]) i++; return i; }
void write(const char* s, const char* f) {
    ofstream out(f);
    out << s;
    out.close();
}

void read(char* s, int n, const char* f) {
    ifstream in(f);
    int i = 0; char c;
    while (in.get(c) && i < n - 1) s[i++] = c;
    s[i] = 0;
    in.close();
}

int main() {
    system("chcp 1251 > nul");

    char buf[256], p1[256], p2[256]; int k;

    cout << "Строка: "; cin.getline(buf, 256);
    cout << "K: "; cin >> k;

    write(buf, "data.txt");
    read(buf, 256, "data.txt");

    int l = len(buf), i = 0, j;
    if (k > l) k = l;

    for (; i < k; i++) p1[i] = buf[i];
    p1[i] = 0;

    for (j = 0; i < l; i++, j++) p2[j] = buf[i];
    p2[j] = 0;

    cout << "1: " << p1 << endl;
    cout << "2: " << p2 << endl;
    return 0;
}