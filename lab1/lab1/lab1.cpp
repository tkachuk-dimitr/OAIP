#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void create(const char* filename) {
    FILE* f = fopen(filename, "w");

    int N = 3;
    fprintf(f, "%d\n", N);

    double matrix[3][3] = {
        {1.1, 2.2, 3.3},
        {4.4, 5.5, 6.6},
        {7.7, 8.8, 9.9}
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(f, "%.1f ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("Файл %s создан.\n", filename);
}

void extract_column() {
    char in_name[] = "matrix_in.txt";
    char out_name[] = "matrix_out.txt";
    int N, k;
    double val;
    FILE* fin, * fout;

    fin = fopen(in_name, "r");
    fscanf(fin, "%d", &N);

    printf("Размерность матрицы: %d x %d\n", N, N);
    printf("Введите номер столбца k (от 1 до %d): ", N);
    scanf("%d", &k);

    fout = fopen(out_name, "w");
    fprintf(fout, "%d\n", N);

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            fscanf(fin, "%lf", &val);
            if (j == k) {
                fprintf(fout, "%.1f\n", val);
            }
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Столбец %d успешно записан в файл %s\n", k, out_name);
}

int main() {
    setlocale(LC_ALL, "Russian");
    create("matrix_in.txt");
    extract_column();
    return 0;
}