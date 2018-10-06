#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
#pragma warning(disable: 4996) 
#ifdef _DEBUG 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> term(n, 0);
	vector<int> v0(30, -1);
	vector<vector<int>> tab(n, v0);
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		if (s) term[i]++;

		int let, state;
		for (int j = 0; j < t; j++) {
			char c;
			cin >> c >> state;
			let = int(c) - 'a';
			tab[i][let] = state;
		}
	}
	int m;
	cin >> m;
	cout << int(term[0] != 0) << '\n';
	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;
		int st = 0;
		bool res = 1;
		for (auto c : word) {
			int x = int(c) - 'a';
			if (tab[st][x] == -1) {
				res = 0;
				break;
			}
			st = tab[st][x];
		}
		if (!term[st]) res = 0;
		cout << int(res) << '\n';
	}
}