#include <stdlib.h>

#include <iostream>

constexpr int N = 4;

// rotate image by 90 deg
void rotateMatrix(unsigned int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            std::swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

void printMatrix(unsigned int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << ",\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    unsigned int **matrix;
    matrix = (unsigned int **)new unsigned int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = (unsigned int *)new unsigned int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printMatrix(matrix, N);
    rotateMatrix(matrix, N);

    std::cout << std::endl;
    printMatrix(matrix, N);

    return 0;
}
