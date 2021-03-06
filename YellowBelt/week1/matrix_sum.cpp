
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix
{
private:
    int num_rows;
    int num_cols;

    int** matrix;

public:
    Matrix();
    Matrix(int num_rows, int num_cols);
    Matrix(const Matrix& m);
    ~Matrix();

    void Reset(int num_rows, int num_cols);
    void SetElement(int row, int col, int e);
    int At(int row, int col) const;
    int GetNumRows() const;
    int GetNumCols() const;

    friend istream& operator>>(istream& is, Matrix& m);
    friend ostream& operator<<(ostream& is, const Matrix& m);

    bool operator==(const Matrix& other);

    Matrix operator+(const Matrix& other);
};


Matrix::Matrix()
{
    num_rows = num_cols = 0;
}

Matrix::Matrix(int num_rows, int num_cols)
{
    if (num_rows < 0 || num_cols < 0)
    {
        throw out_of_range("");
    }

    this->num_rows = num_rows;
    this->num_cols = num_cols;

    matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new int[num_cols];
    }
}

Matrix::Matrix(const Matrix & m)
{
    num_rows = m.GetNumRows();
    num_cols = m.GetNumCols();

    matrix = new int*[num_rows];

    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new int[num_cols];
        for (int j = 0; j < num_cols; j++)
        {
            matrix[i][j] = m.At(i, j);
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < num_rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::Reset(int num_rows, int num_cols)
{
    if (num_rows < 0 || num_cols < 0)
    {
        throw out_of_range("");
    }

    this->num_rows = num_rows;
    this->num_cols = num_cols;

    matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new int[num_cols];
    }
}

void Matrix::SetElement(int row, int col, int e)
{
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols)
    {
        throw out_of_range("");
    }

    matrix[row][col] = e;
}

int Matrix::At(int row, int col) const
{
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols)
    {
        throw out_of_range("");
    }

    return matrix[row][col];
}

int Matrix::GetNumRows() const
{
    return num_rows;
}

int Matrix::GetNumCols() const
{
    return num_cols;
}

bool Matrix::operator==(const Matrix & other)
{
    if (num_rows != other.num_rows || num_cols != other.num_cols)
        return false;

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            if (matrix[i][j] != other.At(i, j))
                return false;
        }
    }

    return true;
}

Matrix Matrix::operator+(const Matrix & other)
{
    if (num_rows != other.num_rows || num_cols != other.num_cols)
        throw invalid_argument("");

    Matrix m(num_rows, num_cols);

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            m.SetElement(i, j, At(i, j) + other.At(i, j));
        }
    }

    return m;
}

istream& operator>>(istream& is, Matrix& m)
{
    int num_rows, num_cols, e;
    is >> num_rows >> num_cols;

    m.Reset(num_rows, num_cols);

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            is >> e;
            m.SetElement(i, j, e);
        }
    }

    return is;
}

ostream & operator<<(ostream & os, const Matrix & m)
{
    int num_rows = m.GetNumRows(), num_cols = m.GetNumCols();
    os << num_rows << " " << num_cols << "\n";
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            os << m.At(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}

int main() {
    Matrix one;
    Matrix two;
    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
