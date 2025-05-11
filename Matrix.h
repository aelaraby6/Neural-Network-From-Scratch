#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
private:
	int rows, cols;
	vector<vector<float>> data;

public:

	Matrix();

	Matrix( int r, int c);

	// 2D matrix
	Matrix(const vector<vector<float>>& d, const int r, const int c);

	// 1D matrix
	/*Matrix(const vector<float>& d, const int r, const int c);*/

	// copy constructor
	Matrix(const Matrix& other);

	// identity matrix
	static Matrix identity(int size);

	// zero matrix
	static Matrix zeroMatrix(int r, int c);

	// to transform vector to matrix 
	static Matrix toMatrix(const vector<float>& vec, bool asRow = false);


	// to transform matrix (column matrix) to vector
	vector<float> toVector() const;

	// Matrix Operations
	Matrix operator+(Matrix const& obj);
	Matrix operator-(Matrix const& obj);
	Matrix operator*(Matrix const& obj);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix operator*(float scalar);
	Matrix operator*=(float scalar);
	Matrix& operator=(const Matrix& other);
	bool operator==(const Matrix& other) const;

	Matrix transpose() const;

	float& in(int i, int j);
	float at(int i, int j) const;

	int getRows() const;
	int getCols() const;

	// print matrix
	friend ostream& operator<<(ostream& os, const Matrix& m);
};
