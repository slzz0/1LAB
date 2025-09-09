#pragma once

#include <iostream>

class Matrix {
   private:
    int** data;
    int cols_count;
    int rows_count;

    void allocate_memory(int rows, int cols);
    void free_memory();

   public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();

    void input_matrix();
    void print_matrix();
    void multiply_by_number(int number);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
};
