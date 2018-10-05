#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
long long int minn(long long int a, long long int b) {
	if (a < b) return a;
	return b;
}
long long int foo(vector<vector<long long int>>& v, long long int ll, long long int rr) {
	if (rr - ll == 2) {
		return (v[ll][0] - v[ll + 1][0]) * (v[ll][0] - v[ll + 1][0]) +
			(v[ll + 1][1] - v[ll][1]) * (v[ll + 1][1] - v[ll][1]);
	}
	if (rr - ll == 3) {
		long long int a =
			(v[ll][0] - v[ll + 1][0]) * (v[ll][0] - v[ll + 1][0]) +
			(v[ll + 1][1] - v[ll][1]) * (v[ll + 1][1] - v[ll][1]);
		long long int b =
			(v[ll + 2][0] - v[ll + 1][0]) * (v[ll + 2][0] - v[ll + 1][0]) +
			(v[ll + 1][1] - v[ll + 2][1]) * (v[ll + 1][1] - v[ll + 2][1]);
		long long int c =
			(v[ll + 2][0] - v[ll][0]) * (v[ll + 2][0] - v[ll][0]) +
			(v[ll][1] - v[ll + 2][1]) * (v[ll][1] - v[ll + 2][1]);
		return minn(minn(a, b), c);
	}
	long long int h = minn(foo(v, ll, ll + (rr - ll) / 2), foo(v, ll + (rr - ll) / 2, rr));
	int m = ll + (rr - ll) / 2;
	vector <vector<long long int>> b;
	int i = m;
	while (i < rr && abs(v[m][0] - v[i][0]) < sqrt(h)) {
		vector<long long int> v0;
		v0.push_back(v[i][1]);
		v0.push_back(v[i][0]);
		b.push_back(v0);
		i++;
	}
	i = m - 1;
	while (i >= ll && abs(v[m][0] - v[i][0]) < sqrt(h)) {
		vector<long long int> v0;
		v0.push_back(v[i][1]);
		v0.push_back(v[i][0]);
		b.push_back(v0);
		i--;
	}
	sort(b.begin(), b.end());
	for (i = 0; i < b.size(); i++) {
		int j = i + 1;
		vector <vector<long long int>> c;
		while (j < b.size() && b[j][0] - b[i][0] < sqrt(h)) {
			c.push_back(b[j]);
			j++;
		}
		for (j = 0; j < c.size(); j++) {
			h = minn(h, (b[i][0] - c[j][0]) * (b[i][0] - c[j][0])
				+ (b[i][1] - c[j][1]) * (b[i][1] - c[j][1]));
		}
	}
	return h;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int n;
	cin >> n;
	long long int x, y;
	vector <vector<long long int>> v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vector <long long int> v0;
		v0.push_back(x);
		v0.push_back(y);
		v.push_back(v0);
	}
	sort(v.begin(), v.end());
	long long int h = foo(v, 0, n);
	double ans = sqrt(h);
	printf("%.10f", ans);
}