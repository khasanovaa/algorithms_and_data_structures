#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
vector <int> timein;
vector <int> ret;
int times = 0;
void dfs(vector<vector<int>>& tab, int v, int last, vector<int>& u) {
	u[v] = 1;
	times++;
	timein[v] = times;
	ret[v] = times;
	for (auto i : tab[v]) {
		if (i != last && u[i] == 1) {
			ret[v] = min(ret[v], timein[i]);
		}
		if (u[i] == 0) {
			dfs(tab, i, v, u);
			ret[v] = min(ret[v], ret[i]);
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	ret.resize(n);
	timein.resize(n);
	vector <vector<int>> tab(n);
	vector <int> u(n);
	vector<pair<int, int>> mp;
	map <pair<int, int>, int> e;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		mp.push_back(make_pair(x, y));
		e[make_pair(x, y)]++;
		e[make_pair(y, x)]++;
		tab[x].push_back(y);
		tab[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		if (u[i] == 0) {
			dfs(tab, i, -1, u);
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		if ((timein[mp[i].first] < ret[mp[i].second] || timein[mp[i].second] < ret[mp[i].first])
			&& (e[mp[i]] < 2 || e[make_pair(mp[i].second, mp[i].first)] < 2))
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << ' ';
	}
}