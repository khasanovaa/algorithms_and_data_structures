#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
int first1(int c) {
	int num = 0;
	while (c > 0) {
		c = c >> 1;
		num++;
	}
	return num;
}

string antiutf(vector <int> v) {
	int k = 0;
	string ans;
	for (auto n : v) {
		int f = first1(n);
		vector <int> v0;
		int num = 1;
		if (n < 127) {
			ans.push_back(n);
		}
		else {
			while (f + num + 1 > 8) {
				v0.push_back((1 << 7) | (n & ((1 << 6) - 1)));
				n >>= 6;
				f -= 6;
				num++;
			}
			int byte = ((1 << num) - 1) << (8 - num);
			byte |= n;
			v0.push_back(byte);
			for (int i = v0.size() - 1; i >= 0; i--) {
				ans.push_back(v0[i]);
			}
		}
	}
	return ans;
}
int main() {
	vector <int> v;
	int i;
	while (cin >> i) {
		v.push_back(i);
	}
	cout << antiutf(v);
}