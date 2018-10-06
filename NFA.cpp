#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<deque>
#include<set>
using namespace std;
struct state {
	bool term;
	vector<int> eps;
	vector<vector<int>> tab;
};

vector<state> read() {
	int n;
	cin >> n;
	vector<state> states(n);
	for (int i = 0; i < n; ++i) {
		cin >> states[i].term;
		int e;
		cin >> e;
		states[i].eps.resize(e);
		for (int j = 0; j < e; ++j) {
			cin >> states[i].eps[j];
		}
		int t;
		cin >> t;
		states[i].tab.resize(26);
		char let;
		int next;
		int letint;
		for (int j = 0; j < t; j++) {
			cin >> let >> next;
			letint = int(let) - 'a';
			states[i].tab[letint].push_back(next);
		}
	}
	return states;
}

vector<int> epsilon(vector<int>& current, vector<state>& states) {
	vector<int> used(states.size());
	for (int i = 0; i < current.size(); i++) {
		used[current[i]] = 1;
	}
	for (int i = 0; i < current.size(); i++) {
		for (int sost : states[current[i]].eps) {
			if (!used[sost]) {
				used[sost] = 1;
				current.push_back(sost);
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < used.size(); i++) {
		if (used[i]) ans.push_back(i);
	}
	return ans;
}

bool algo(string& word, vector<state>& states) {
	int n = states.size();
	vector<int> current;
	vector<bool> used(n);
	current.push_back(0);
	current = epsilon(current, states);
	for (auto c : word) {
		vector<int> next_step;
		for (int ver : current) {
			for (int sost : states[ver].tab[c - 'a']) {
				if (!used[sost]) {
					used[sost] = 1;
					next_step.push_back(sost);
				}
			}
		}
		current = epsilon(next_step, states);
		if (!current.size()) return false;
		used.clear();
		used.resize(n);
	}
	for (int i = 0; i < current.size(); i++) {
		if (states[current[i]].term) return true;
	}
	return false;
}
int main() {
#pragma warning(disable: 4996) 
#ifdef _DEBUG 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<state> states = read();
	int m;
	cin >> m;
	string empty = "";
	cout << int(algo(empty, states)) << '\n';
	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;
		cout << int(algo(word, states)) << '\n';
	}
}