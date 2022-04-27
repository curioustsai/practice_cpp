#include <stdlib.h>

#include <iostream>

constexpr int M = 5;
constexpr int N = 4;

void zeroMatrix(unsigned int **matrix, int m, int n) {
    bool *hitX = new bool[m]{false};
    bool *hitY = new bool[n]{false};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                hitX[i] = true;
                hitY[j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (hitX[i] || hitY[j]) { matrix[i][j] = 0; }
        }
    }

    delete[] hitX;
    delete[] hitY;
}

void printMatrix(unsigned int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { std::cout << matrix[i][j] << ",\t"; }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    unsigned int **matrix;
    matrix = (unsigned int **)new unsigned int *[M];
    for (int i = 0; i < M; i++) { matrix[i] = (unsigned int *)new unsigned int[N]; }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) { matrix[i][j] = rand() % 100; }
    }

    matrix[2][3] = 0;

    printMatrix(matrix, M, N);
    zeroMatrix(matrix, M, N);
    printMatrix(matrix, M, N);

    return 0;
}
