#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <string> v(n);
	cout << "Initial array:\n";
	int size;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i != n - 1) {
			cout << v[i] << ", ";
		}
		else {
			cout << v[i] << '\n';
			size = v[i].size();
		}
	}
	cout << "**********\n";
	vector <vector<string>> buc(25);
	for (int i = 0; i < size; i++) {
		cout << "Phase " << i + 1 << '\n';
		int raz = size - 1 - i;
		for (auto j : v) {
			buc[j[raz] - '0'].push_back(j);
		}
		for (int j = 0; j < 10; j++) {
			cout << "Bucket " << j << ": ";
			if (buc[j].size() == 0) {
				cout << "empty\n";
			}
			else {
				for (int k = 0; k < buc[j].size(); k++) {
					if (k == buc[j].size() - 1) {
						cout << buc[j][k] << '\n';
					}
					else {
						cout << buc[j][k] << ", ";
					}
				}
			}
		}
		cout << "**********\n";
		v.clear();
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < buc[j].size(); k++) {
				v.push_back(buc[j][k]);
			}
		}
		buc.clear();
		buc.resize(25);
	}
	cout << "Sorted array:\n";
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			cout << v[i];
		}
		else {
			cout << v[i] << ", ";
		}
	}
	return 0;
}