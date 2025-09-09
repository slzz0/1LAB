#include "../headers/matrix.h"

#include "../headers/utilits.h"

using namespace std;

Matrix::Matrix() : rows_count(0), cols_count(0), data(nullptr) {}
Matrix::Matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be a positive number");
    }
    allocate_memory(rows, cols);
}

Matrix::~Matrix() { free_memory(); }

void Matrix::allocate_memory(int rows, int cols) {
    rows_count = rows;
    cols_count = cols;

    data = new int*[rows_count];
    for (int i = 0; i < rows_count; i++) {
        data[i] = new int[cols_count];
    }
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            data[i][j] = 0;
        }
    }
}

void Matrix::free_memory() {
    if (data != nullptr) {
        for (int i = 0; i < rows_count; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

void Matrix::input_matrix() {
    if (data == nullptr) {
        cout << "Enter the number of rows in the matrix: ";
        rows_count = valid_int();
        cout << "Enter the number of columns in the matrix: ";
        cols_count = valid_int();

        if (rows_count <= 0 || cols_count <= 0) {
            throw std::invalid_argument("Matrix dimensions must be a positive number");
        }

        allocate_memory(rows_count, cols_count);
    }

    cout << "Enter matrix elements " << rows_count << "x" << cols_count << ":\n";
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            data[i][j] = valid_int();
        }
    }
}

void Matrix::print_matrix() {
    if (data == nullptr) {
        cout << "The matrix is not initialized (you must select 1-st option)" << endl;
        return;
    }
    cout << "Matrix " << rows_count << "x" << cols_count << ":\n";
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Matrix::multiply_by_number(int number) {
    if (data == nullptr) {
        cout << "The matrix is not initialized (you must select 1-st option)" << endl;
        return;
    }
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < cols_count; j++) {
            data[i][j] *= number;
        }
    }
    cout << "Matrix multiplied by " << number
         << " successfully! (to see the new matrix select 3-rd option)" << endl;
}
