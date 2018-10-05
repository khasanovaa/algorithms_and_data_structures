#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
using namespace std;

template <typename T>
class Matrix {
private:
	size_t lines, columns;
	vector<T> mat;

public:
	Matrix<T>(const vector<std::vector<T>>& v) {
		lines = v.size();
		columns = v[0].size();
		for (size_t i = 0; i < lines; i++) {
			for (size_t j = 0; j < columns; j++) {
				mat.push_back(v[i][j]);
			}
		}
	}
	pair <size_t, size_t> size() const {
		return make_pair(lines, columns);
	}

	friend ostream& operator << (ostream& out, const Matrix<T>& m) {
		for (size_t i = 0; i < m.lines; i++) {
			for (size_t j = 0; j < m.columns; j++) {
				out << m.mat[i * m.columns + j];
				if (j != m.columns - 1) {
					out << '\t';
				}
			}
			if (i != m.lines - 1) {
				out << '\n';
			}
		}
		return out;
	}

	Matrix<T>& operator += (const Matrix& a) {
		for (size_t i = 0; i < mat.size(); i++) {
			mat[i] += a.mat[i];
		}
		return *this;
	}
	Matrix<T> operator + (const Matrix& a) const {
		Matrix <T> c = *this;
		c += a;
		return c;
	}

	template <typename Q>
	Matrix<T> operator *= (const Q& n) {
		for (size_t i = 0; i < mat.size(); i++) {
			mat[i] *= n;
		}
		return *this;
	}
	vector<vector<T>> vec() const {
		size_t k = 0;
		vector <T> v0(columns);
		vector <vector<T>> v(lines, v0);
		for (size_t i = 0; i < lines; i++) {
			for (size_t j = 0; j < columns; j++) {
				v[i][j] = mat[k];
				k++;
			}
		}
		return v;
	}
	Matrix<T> transpose() {
		size_t k = 0;
		vector <T> v0(columns);
		vector <vector<T>> v(lines, v0);
		for (size_t i = 0; i < lines; i++) {
			for (size_t j = 0; j < columns; j++) {
				v[i][j] = mat[k];
				k++;
			}
		}
		vector <T> vv0(lines);
		vector <vector<T>> vv(columns, vv0);
		for (size_t i = 0; i < columns; i++) {
			for (size_t j = 0; j < lines; j++) {
				vv[i][j] = v[j][i];
			}
		}
		return *this = Matrix<T>(vv);
	}

	Matrix<T> transposed() const {
		Matrix<T> c = *this;
		return c.transpose();
	}
	Matrix<T> operator *= (const Matrix <T>& a) {
		Matrix<T> c = *this;
		vector<vector<T>> vm = c.vec();
		vector<vector<T>> va = a.vec();
		vector<T> v0(vm.size());
		vector<vector<T>> v(vm.size(), v0);
		for (size_t i = 0; i < vm.size(); i++) {
			for (size_t j = 0; j < va[0].size(); j++) {
				int sum = 0;
				for (size_t k = 0; k < vm[0].size(); k++) {
					sum += vm[i][k] * va[k][j];
				}
				v[i][j] = sum;
			}
		}
		return *this = Matrix<T>(v);
	}
	Matrix<T> operator * (const Matrix<T>& a) const {
		Matrix c = *this;
		return c *= a;
	}
	auto begin() const {
		return mat.begin();
	}

	auto end() const {
		return mat.end();
	}
};

template <typename Q, typename T>
Matrix<T> operator * (const Q& n, const Matrix<T>& a) {
	Matrix <T> c = a;
	return c *= n;
}

template <typename Q, typename T>
Matrix<T> operator * (const Matrix<T>& a, const Q& n) {
	Matrix <T> c = a;
	return c *= n;
}