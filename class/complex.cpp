#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
class Complex {
private:
	double re;
	double im;

public:
	explicit Complex(double rre = 0, double iim = 0)
		: re(rre)
		, im(iim)
	{}
	double Im() const {
		return im;
	}
	double Re() const {
		return re;
	}
	Complex& operator += (const Complex& a) {
		im += a.im;
		re += a.re;
		return *this;
	}
	Complex& operator -= (const Complex& a) {
		im -= a.im;
		re -= a.re;
		return *this;
	}
	Complex operator *= (const Complex& a) {
		double newIm = a.im * re + a.re * im;
		re = re * a.re - im * a.im;
		im = newIm;
		return *this;
	}
	Complex operator /= (const Complex& a) {
		double newRe = (im * a.im + re * a.re) / (a.im * a.im + a.re * a.re);
		im = (im * a.re - re * a.im) / (a.im * a.im + a.re * a.re);
		re = newRe;
		return *this;
	}
	Complex operator + () const {
		return *this;
	}
	Complex operator - () const {
		return Complex(-re, -im);
	}
	bool operator == (Complex a) const {
		return (im == a.im && re == a.re);
	}
	bool operator != (Complex a) const {
		return (im != a.im || re != a.re);
	}
};
Complex operator + (Complex a, const double& b) {
	return a += Complex(b);
}
Complex operator + (const double& a, Complex b) {
	return Complex(a) += b;
}
Complex operator + (Complex a, const Complex& b) {
	return a += b;
}

Complex operator - (Complex a, const Complex& b) {
	return a -= b;
}
Complex operator - (Complex a, const double& b) {
	return a -= Complex(b);
}
Complex operator - (const double& a, Complex b) {
	return Complex(a) -= b;
}

Complex operator * (Complex a, const double& b) {
	return a *= Complex(b);
}
Complex operator * (const double& a, Complex b) {
	return Complex(a) *= b;
}
Complex operator * (Complex a, const Complex& b) {
	return a *= b;
}

Complex operator / (Complex a, const double& b) {
	return a /= Complex(b);
}
Complex operator / (const double& a, Complex b) {
	return Complex(a) /= b;
}
Complex operator / (Complex a, const Complex& b) {
	return a /= b;
}
double abs(Complex a) {
	return sqrt(a.Re() * a.Re() + a.Im() * a.Im());
}
