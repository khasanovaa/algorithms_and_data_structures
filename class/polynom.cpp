#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename T>
class Polynomial {
private:
	map <int, T> coef;
public:
	Polynomial<T>(const vector<T>& inp) {
		coef.clear();
		for (size_t i = 0; i < inp.size(); i++) {
			if (inp[i] != 0) {
				coef[i] = inp[i];
			}
		}
	}

	Polynomial<T>(T t = T()) {
		coef.clear();
		if (t != T(0)) {
			coef[0] = t;
		}
	}

	template<typename It>
	Polynomial(It beginn, It endn) {
		coef.clear();
		int i = 0;
		while (beginn != endn) {
			if (*beginn != 0) {
				coef[i] = *beginn;
			}
			beginn++;
			i++;
		}
	}

	T operator [] (const int& deg) const {
		auto copy = *this;
		return copy.coef[deg];
	}

	T operator () (const T& dot) const {
		T powdot = T(1);
		T res = T(0);
		auto copy = *this;
		for (size_t i = 0; i <= (copy).Degree(); i++) {
			res += powdot * copy.coef[i];
			powdot *= dot;
		}
		return res;
	}

	size_t Degree() const {
		if (coef.size() == 0)
			return -1;
		auto it = coef.end();
		it--;
		return it->first;
	}

	typename map<int, T>::const_iterator begin() const {
		return coef.begin();
	}

	typename map<int, T>::const_iterator end() const {
		return coef.end();
	}

	template<typename smth>
	bool operator == (const smth& two) const {
		auto copy = *this;
		auto other = Polynomial(two);
		if (other.Degree() != copy.Degree()) {
			return false;
		}
		for (auto i : copy.coef) {
			int deg = i.first;
			if (copy.coef[deg] != other.coef[deg])
				return false;
		}
		return true;
	}

	template<typename smth>
	bool operator != (const smth& two) const {
		auto other = Polynomial(two);
		return !(*this == other);
	}

	template<typename smth>
	Polynomial<T> operator + (const smth two) const {
		auto copy = *this;
		auto other = Polynomial(two);
		int d1 = copy.Degree();
		int d2 = other.Degree();
		vector<T> ans(max(d1, d2) + 1);
		for (size_t i = 0; i < ans.size(); i++) {
			if (i <= copy.Degree()) ans[i] += copy.coef[i];
			if (i <= other.Degree()) ans[i] += other.coef[i];
		}
		return Polynomial<T>(ans);
	}

	template<typename smth>
	Polynomial<T> operator - (const smth& two) const {
		auto copy = *this;
		auto other = Polynomial(two);
		int d1 = copy.Degree();
		int d2 = other.Degree();
		vector<T> ans(max(d1, d2) + 1);
		for (size_t i = 0; i < ans.size(); i++) {
			if (i <= d1)
				ans[i] += copy.coef[i];
			if (i <= d2)
				ans[i] -= other.coef[i];
		}
		return Polynomial<T>(ans);
	}

	template<typename smth>
	Polynomial<T> operator * (const smth& two) const {
		auto copy = *this;
		auto other = Polynomial(two);
		int d1 = copy.Degree();
		int d2 = other.Degree();
		vector<T> ans(d1 + d2 + 1);
		for (int i = 0; i <= d1; i++) {
			for (int j = 0; j <= d2; j++) {
				ans[i + j] += copy.coef[i] * other.coef[j];
			}
		}
		return Polynomial<T>(ans);
	}

	Polynomial<T> operator / (const Polynomial<T>& other1) const {
		auto other = other1;
		Polynomial<T> ans(T(0));
		Polynomial<T> r = *this;
		while (int(r.Degree()) >= int(other.Degree())) {
			auto d = r.Degree() - other.Degree();
			vector<T> monom(d + 1);
			monom[d] = r.coef[r.Degree()] / other.coef[other.Degree()];
			Polynomial<T> mon(monom);
			auto prom = mon * other;
			r = r - (prom);
			ans = ans + mon;
		}
		return ans;
	}

	Polynomial<T> operator % (const Polynomial<T> other) const {
		return *this - (*this / other) * other;
	}

	Polynomial<T> operator , (const Polynomial<T> other) const {
		Polynomial<T> second = *this;
		Polynomial<T> first = other;
		if (coef.size() >= other.coef.size()) {
			first = *this;
			second = other;
		}
		while (second.coef.size() != 0) {
			Polynomial<T> r = first % second;
			first = second;
			second = r;
		}
		return first / first.coef[first.Degree()];
	}

	template<typename smth>
	Polynomial<T>& operator += (const smth& two) {
		return *this = *this + two;
	}

	template<typename smth>
	Polynomial<T>& operator -= (const smth& two) {
		return *this = *this - two;
	}

	template<typename smth>
	Polynomial<T>& operator *= (const smth& two) {
		return *this = *this * two;
	}

	friend ostream& operator << (ostream& out, const Polynomial<T>& copy) {
		auto p = copy;
		if (p.Degree() == -1) {
			out << 0;
			return out;
		}
		if (p.Degree() == 0) {
			out << p.coef[0];
			return out;
		}
		for (int i = int(p.Degree()); i >= 0; i--) {
			if (p.coef[i] != T(0)) {
				if (i == 0) {
					if (p.coef[i] > T(0) && i != int(p.Degree())) out << '+';
					out << p.coef[i];
				}
				else {
					if (p.coef[i] > T(0) && i != int(p.Degree())) out << '+';
					if (p.coef[i] == T(-1)) out << '-';
					if (p.coef[i] != T(-1) && p.coef[i] != T(1)) out << p.coef[i];
					if (p.coef[i] != T(-1) && p.coef[i] != T(1) && i != 0) out << "*";
					if (i != 0) out << 'x';
					if (i > 1) out << "^" << i;
				}
			}
		}
		return out;
	}
	Polynomial operator & (const Polynomial& other) const {
		auto copy = *this;
		Polynomial<T> g = Polynomial<T>(T(1));
		Polynomial<T> f = Polynomial<T>(T(0));
		for (size_t i = 0; i <= copy.Degree(); i++) {
			f += g * copy.coef[i];
			g *= other;
		}
		return f;
	}
};
template<typename T>
bool operator != (const T& t, const Polynomial<T>& p) {
	return p != Polynomial<T>(t);
}

template<typename T>
bool operator == (const T& t, const Polynomial<T>& p) {
	return p == Polynomial<T>(t);
}

template<typename T>
Polynomial<T> operator + (const T& t, const Polynomial<T>& p) {
	return p + Polynomial<T>(t);
}

template<typename T>
Polynomial<T> operator - (const T& t, const Polynomial<T>& p) {
	return Polynomial<T>(t) - p;
}

template<typename T>
Polynomial<T> operator * (const T& t, const Polynomial<T>& p) {
	return p * Polynomial<T>(t);
}