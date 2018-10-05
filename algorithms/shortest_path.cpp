#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const unsigned long long int inf = 4 * 1e18;
	long long int n, k;
	cin >> n >> k;
	vector <long long int> d(n, inf);
	vector <vector <pair<long long int, long long int>>> tab(n);
	vector <long long int> p(n);
	map <pair<long long int, long long int>, long long int> u;
	long long int x, y, l;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> l;
		x--;
		y--;
		tab[x].push_back(make_pair(y, l));
		tab[y].push_back(make_pair(x, l));
	}
	cin >> x >> y;
	x--;
	y--;
	d[x] = 0;
	u[make_pair(0, x)]++;
	while (u.size()) {
		auto it = u.begin();
		long long int v = (it->first).second;
		u.erase(it);
		for (auto j : tab[v]) {
			if (d[v] + j.second < d[j.first]) {
				u.erase(make_pair(d[j.first], j.first));
				d[j.first] = d[v] + j.second;
				u[make_pair(d[j.first], j.first)];
			}
			p[j.first] = v;
		}
		if (v == y) break;
	}
	if (d[y] == inf) {
		cout << -1;
		return 0;
	}
	if (x == y) {
		cout << 0;
		return 0;
	}
	cout << d[y];
}