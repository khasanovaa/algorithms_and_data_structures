#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void wri(vector <int> v) {
	int n = v.size();
	printf("%d", v[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		printf("%.4d", v[i]);
	}
}

vector <int> umnd(vector <int> v1, int k) {
	vector <int> an(v1.size() + 9);
	for (int i = 0; i < v1.size(); i++) {
		an[i] += v1[i] * k;
		if (an[i] > 10000) {
			an[i + 1] += an[i] / 10000;
			an[i] = an[i] % 10000;
		}
	}
	for (int i = 0; i < an.size(); i++) {
		if (an[i] > 10000) {
			an[i + 1] += an[i] / 10000;
			an[i] = an[i] % 10000;
		}
	}
	int k0 = an.size() - 1;
	while (an.size() > 0 && an[k0] == 0) {
		an.pop_back();
		k0--;
	}
	if (an.size() == 0)
		an.push_back(0);
	return an;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(1);
	for (int i = 2; i <= n; i++) {
		v = umnd(v, i);
	}
	wri(v);
}