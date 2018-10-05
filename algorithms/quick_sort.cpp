#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
pair<int, int> part(vector<int>& v, int x, int l, int r) {
	vector<int> vm;
	vector<int> vb;
	int vr = 0;
	for (int i = l; i < r; i++) {
		if (v[i] < x) vm.push_back(v[i]);
		if (v[i] > x) vb.push_back(v[i]);
		if (v[i] == x) vr++;
	}
	for (int i = 0; i < vm.size(); i++) {
		v[l + i] = vm[i];
	}
	for (int i = 0; i < vr; i++) {
		v[l + vm.size() + i] = x;
	}
	for (int i = 0; i < vb.size(); i++) {
		v[l + vm.size() + vr + i] = vb[i];
	}
	pair<int, int> p;
	p.first = l + vm.size();
	p.second = l + vm.size() + vr;
	return p;
}

void QuickSort(vector<int>& v, int l, int r) {
	if (r - l < 2) return;
	auto p = part(v, v[l + rand() % (r - l)], l, r);
	QuickSort(v, l, p.first);
	QuickSort(v, p.second, r);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int x;
	vector <int> v(n);
	if (n == 0) return 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v[i] = x;
	}
	QuickSort(v, 0, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}