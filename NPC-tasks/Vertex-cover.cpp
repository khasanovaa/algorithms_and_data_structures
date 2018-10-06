#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
void read(int m, vector<unordered_set<int>>& tab) {
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		tab[x].insert(y);
		tab[y].insert(x);
	}
}

void ends(vector<unordered_set<int>>& tab, vector<int>& select, int n, int& k) {
	int flag = 1;
	while (flag) {
		flag = 0;
		vector<int> newselect(n);
		for (int i = 0; i < n; i++) {
			if (tab[i].size() > k) {
				flag = 1;
				select[i] = 1;
				newselect[i] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			if (tab[i].size() == 1) {
				int x = *tab[i].begin();
				flag = 1;
				if (tab[x].size() == 1) {
					select[min(i, x)] = 1;
					newselect[min(i, x)] = 1;
				}
				else {
					select[x] = 1;
					newselect[x] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (tab[i].size() == 2 && !select[i]) {
				auto it = tab[i].begin();
				int x = *it;
				it++;
				int y = *it;
				if (tab[y].size() >= 2 && tab[x].size() >= 2) {
					newselect[x] = 1;
					newselect[y] = 1;
					select[x] = 1;
					select[y] = 1;
					flag = 1;
				}
			}
		}


		int sum = 0;
		for (int v = 0; v < newselect.size(); v++) {
			if (newselect[v]) {
				sum++;
				for (auto w : tab[v]) {
					tab[w].erase(v);
				}
				tab[v].clear();
			}
		}
		k -= sum;
	}
}

void no() {
	cout << "No";
}

void yes(vector<int>& ans, int k) {
	cout << "Yes\n";
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i]) k--;
	}
	int ii = 0;
	while (k) {
		if (!ans[ii]) {
			k--;
			ans[ii] = 1;
		}
		ii++;
	}


	for (int i = 0; i < ans.size(); i++) {
		if (ans[i]) {
			cout << i + 1 << ' ';
		}
	}
}
void selectout(vector<int>& select, vector<int>& result) {
	for (int i = 0; i < select.size(); i++) {
		if (select[i]) {
			result.push_back(i);
		}
	}
}

vector<int> makecand(vector<unordered_set<int>>& tab, vector<int>& select, int n) {
	vector<int> cand;
	for (int i = 0; i < n; i++) {
		if (!select[i] && tab[i].size()) {
			cand.push_back(i);
		}
	}
	return cand;
}

bool check(vector<int> attempt, vector<pair<int, int>>& edges) {
	for (auto j : edges) {
		if (!attempt[j.first] && !attempt[j.second]) {
			return false;
		}
	}
	return true;
}

vector<pair<int, int>> makeEdges(vector<unordered_set<int>>& tab, int n) {
	vector<pair<int, int>> edges;
	for (int i = 0; i < n; i++) {
		for (auto j : tab[i]) {
			if (i < j) {
				auto p = make_pair(i, j);
				edges.push_back(p);
			}
		}
	}
	return edges;
}
vector<int> algo(int k, vector<pair<int, int>>& edges, vector<unordered_set<int>>& tab,
	vector<int> cand, vector<int> select) {

	vector<int> d(cand.size());
	for (int i = d.size() - k; i < d.size(); i++) {
		d[i] = 1;
	}

	vector<int> d0 = d;
	do {
		vector<int> attempt = select;
		for (int j = 0; j < d.size(); j++) {
			if (d[j]) attempt[cand[j]] = 1;
		}

		if (check(attempt, edges)) return attempt;

		next_permutation(d.begin(), d.end());
	} while (d != d0);
	vector<int> ans;
	return ans;
}


bool opt(vector<unordered_set<int>>& tab, int n, vector<int>& kk) {
	int v = -1;
	for (int i = 0; i < n; i++) {
		if (tab[i].size()) {
			v = i;
			break;
		}
	}
	if (v == -1)
		return false;
	int u = *(tab[v].begin());
	for (auto i : tab[v]) {
		tab[i].erase(v);
	}
	for (auto i : tab[u]) {
		tab[i].erase(u);
	}
	tab[u].clear();
	tab[v].clear();
	kk.push_back(u);
	kk.push_back(v);
	return true;
}

int main() {
#pragma warning(disable: 4996) 
#ifdef _DEBUG 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	int K = k;
	vector<unordered_set<int>> tab(n);
	read(m, tab);

	vector<int> select(n);
	ends(tab, select, n, k);

	vector<int> result;
	selectout(select, result);
	if (k < 0) {
		no();
		return 0;
	}

	auto tab1 = tab;
	vector<int> cand;
	while (opt(tab1, n, cand)) { int x; }
	if (cand.size() > 2 * k) {
		no();
		return 0;
	}

	vector<pair<int, int>> edges = makeEdges(tab, n);
	if (!edges.size()) {
		yes(select, K);
		return 0;
	}
	if (k == 0) {
		if (check(select, edges)) yes(select, K);
		else no();
		return 0;
	}
	vector<int> ans = algo(k, edges, tab, cand, select);
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i])
			result.push_back(i);
	}
	vector<int> res1(n);
	for (auto i : result) {
		res1[i] = 1;
	}

	if (check(res1, edges)) {
		yes(res1, K);
	}
	else no();
}