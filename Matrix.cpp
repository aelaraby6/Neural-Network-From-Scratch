#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(int r,  int c) : rows(r), cols(c) {
    if (rows <= 0 || cols <= 0)
        throw invalid_argument("Matrix dimensions must be positive and not zero");

    data.resize(rows, std::vector<float>(cols, 0.0f));
}

Matrix::Matrix(const vector<vector<float>>& d, const int r, const int c) {
    if (d.size() != r || d[0].size() != c)
        throw invalid_argument("Invalid Matrix dimensions");

    rows = r;
    cols = c;
    data = d;
}

/*Matrix::Matrix(const vector<float>& d, const int r, const int c) {
    if (d.size() != r || c != 0)
        throw invalid_argument("vector is empty");

    *this = toMatrix(d);
}*/

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols), data(other.data) {}

Matrix Matrix::identity(int size) {
    Matrix identityMatrix(size, size);
    for (int i = 0; i < size; i++) {
        identityMatrix.data[i][i] = 1.0f;
    }
    return identityMatrix;
}

Matrix Matrix::zeroMatrix(int r, int c) {
    return Matrix(r, c);
}

Matrix Matrix::toMatrix(const vector<float>& vec, bool asRow) {
    if (vec.empty())
        throw invalid_argument("vector is empty");

    int rows = asRow ? 1 : vec.size();
    int cols = asRow ? vec.size() : 1;

    Matrix m(rows, cols);

    for (int i = 0; i < vec.size(); i++) {
        if (asRow)
            m.data[0][i] = vec[i]; // row vector
        else
            m.data[i][0] = vec[i]; // column vector
    }

    return m;
}


vector<float> Matrix::toVector() const {
    vector<float> vec;
    for (int i = 0; i < rows; i++) {
        vec.push_back(data[i][0]);
    }

    return vec;
}

Matrix Matrix::operator+(Matrix const& obj) {
    /*if (rows != obj.rows || cols != obj.cols)
        throw std::invalid_argument("Matrix dimensions must match for addition");*/

    Matrix m(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = data[i][j] + obj.data[i][j];
        }
    }

    return m;
}

Matrix Matrix::operator-(Matrix const& obj) {
    if (rows != obj.rows || cols != obj.cols)
        throw std::invalid_argument("Matrix dimensions must match for subtraction");

    Matrix m(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = data[i][j] - obj.data[i][j];
        }
    }

    return m;
}

Matrix Matrix::operator*(Matrix const& obj) {
    if (cols != obj.rows)
        throw std::invalid_argument("cols num of first matrix is not equal to rows num of second matrix");

    Matrix result(rows, obj.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            float summ = 0.0f;
            for (int x = 0; x < cols; x++) {
                summ += (data[i][x] * obj.data[x][j]);
            }
            result.data[i][j] = summ;
        }
    }

    return result;
}

Matrix& Matrix::operator+=(const Matrix& obj) {
    if (rows != obj.rows || cols != obj.cols)
        throw std::invalid_argument("Matrix dimensions must match for addition");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] += obj.data[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& obj) {
    if (rows != obj.rows || cols != obj.cols)
        throw std::invalid_argument("Matrix dimensions must match for subtraction");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] -= obj.data[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& obj) {
    if (cols != obj.rows)
        throw std::invalid_argument("Number of columns of the first matrix must be equal to number of rows of the second matrix");

    Matrix result(rows, obj.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            float summ = 0.0f;
            for (int x = 0; x < cols; x++) {
                summ += (data[i][x] * obj.data[x][j]);
            }
            result.data[i][j] = summ;
        }
    }

    rows = result.rows;
    cols = result.cols;
    data = result.data;

    return *this;
}

Matrix Matrix::operator*(float scalar) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*=(float scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    this->rows = other.rows;
    this->cols = other.cols;
    this->data = other.data;

    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        return false;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (data[i][j] != other.data[i][j])
                return false;

    return true;
}

Matrix Matrix::transpose() const {
    Matrix transposed(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed.data[j][i] = data[i][j];
        }
    }

    return transposed;
}

float& Matrix::in(int i, int j) {
    return data[i][j];
}

float Matrix::at(int i, int j)const {
    return data[i][j];
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}


ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
