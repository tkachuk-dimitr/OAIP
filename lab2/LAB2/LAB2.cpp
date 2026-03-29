#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int cmp(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return 0;
        i++;
    }
    return s1[i] == s2[i];
}

int main() {
    setlocale(LC_ALL, "Russian");

    FILE* f1 = fopen("FILE1.txt", "r");
    FILE* f2 = fopen("FILE2.txt", "w");

    if (f1 == NULL || f2 == NULL) {
        fprintf(stderr, "Ошибка файла!\n");
        return 1;
    }

    char line[1000], words[50][100];
    int maxA = 0, bestWord = 0, wordNum = 0;

    fprintf(stdout, "Обработка файла...\n");

    while (fgets(line, 1000, f1)) {
        int wc = 0, i = 0, j = 0;
        while (line[i] != '\0') {
            while (line[i] == ' ' || line[i] == '\n') i++;
            if (line[i] == '\0') break;

            j = 0;
            while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0') {
                words[wc][j++] = line[i++];
            }
            words[wc][j] = '\0';
            wc++;
        }

        int hasDup = 0;
        for (i = 0; i < wc; i++) {
            for (j = i + 1; j < wc; j++) {
                if (cmp(words[i], words[j])) hasDup = 1;
            }
        }

        if (hasDup) {
            fputs(line, f2);
            fprintf(stdout, "Скопировано: %s", line);
    
            for (i = 0; i < wc; i++) {
                wordNum++;
                int a = 0;
                for (j = 0; words[i][j] != '\0'; j++) {
                    if (words[i][j] == 'а' || words[i][j] == 'a') a++;
                }
                if (a > maxA) {
                    maxA = a;
                    bestWord = wordNum;
                }
            }
        }
    }

    fclose(f1);
    fclose(f2);

    fprintf(stdout, "\nСлово №%d имеет больше всего 'а' (%d шт.)\n", bestWord, maxA);

    return 0;
}