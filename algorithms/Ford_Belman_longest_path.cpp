#include <iostream>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		int x;
		for (int j = 0; j < n; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][k] + v[k][j] < v[i][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(v[i][j], ans);
		}
	}
	cout << ans;
}