#include<iostream>
#include<cstdio>
#include<math.h>
#include<numeric>
using namespace std;
int gcd(int n, int m) {
	if (m == 0) {
		return n;
	}
	return gcd(m, n % m);
}
class Rational {
private:
	int n, m;

public:
	Rational(int nn = 0, int mm = 1)
		: n(nn)
		, m(mm) {
		int d = gcd(abs(n), abs(m));
		n /= d;
		m /= d;
		if (n * m < 0) {
			n = -abs(n);
			m = abs(m);
		}
		if (n < 0 && m < 0) {
			n = abs(n);
			m = abs(m);
		}
	}
	int numerator() const {
		return n;
	}
	int denominator() const {
		return m;
	}
	int nu() const {
		return n;
	}
	int de() const {
		return m;
	}
	friend Rational operator + (const Rational& a, const Rational& b);
	friend Rational operator - (const Rational& a, const Rational& b);
	Rational operator -() {
		return Rational(-n, m);
	}
	Rational operator +() {
		return Rational(n, m);
	}
	Rational& operator ++() {
		return (*this = *this + 1);
	}
	Rational& operator --() {
		return *this = *this - 1;
	}
	Rational operator ++(int) {
		auto t = *this;
		++(*this);
		return t;
	}
	Rational operator --(int) {
		auto t = *this;
		--(*this);
		return t;
	}
};
Rational operator + (const Rational& a, const Rational& b) {
	return Rational(a.nu() * b.de() + b.nu() * a.de(), a.de() * b.de());
}
Rational operator - (const Rational& a, const Rational& b) {
	return Rational(a.nu() * b.de() - b.nu() * a.de(), a.de() * b.de());
}
Rational operator * (const Rational& a, const Rational& b) {
	return Rational(a.nu() * b.nu(), a.de() * b.de());
}
Rational operator / (const Rational& a, const Rational& b) {
	return Rational(a.nu() *b.de(), a.de() * b.nu());
}
bool operator == (const Rational& a, const Rational& b) {
	return a.de() == b.de() && a.nu() == b.nu();
}
bool operator != (Rational a, Rational b) {
	return !(a == b);
}
Rational& operator += (Rational& a, const Rational& b) {
	return a = a + b;
}
Rational& operator -= (Rational& a, const Rational& b) {
	return a = a - b;
}
Rational& operator *= (Rational& a, const Rational& b) {
	return a = a * b;
}
Rational& operator /= (Rational& a, const Rational& b) {
	return a = a / b;
}