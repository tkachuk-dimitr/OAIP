#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void create_input_ints(const char* filename) {
    FILE* f = fopen(filename, "w");
    int data[] = { 10, 5, 10, 3, 5, 8, 3, 1, 1, 10 };
    int size = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < size; i++) {
        fprintf(f, "%d ", data[i]);
    }

    fclose(f);
    printf("Файл %s создан.\n", filename);
}

bool is_duplicate(int* unique, int count, int value) {
    for (int i = 0; i < count; i++) {
        if (unique[i] == value) {
            return true;
        }
    }
    return false;
}

void remove_duplicates() {
    char in_name[] = "input_f.txt";
    char out_name[] = "output_f.txt";
    FILE* fin, * fout;
    int num;

    int* unique_nums = NULL;
    int unique_count = 0;
    int capacity = 10;

    unique_nums = (int*)malloc(capacity * sizeof(int));

    fin = fopen(in_name, "r");
    fout = fopen(out_name, "w");

    while (fscanf(fin, "%d", &num) == 1) {
        if (!is_duplicate(unique_nums, unique_count, num)) {
            fprintf(fout, "%d ", num);

            if (unique_count >= capacity) {
                capacity *= 2;
                int* temp = (int*)realloc(unique_nums, capacity * sizeof(int));
                unique_nums = temp;
            }
            unique_nums[unique_count++] = num;
        }
    }

    fclose(fin);
    fclose(fout);
    free(unique_nums);
    printf("Файл без дубликатов записан в %s\n", out_name);
}

int main() {
    setlocale(LC_ALL, "Russian");
    create_input_ints("input_f.txt");
    remove_duplicates();
    return 0;
}