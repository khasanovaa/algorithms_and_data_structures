#include <iostream>
#include <vector>
using namespace std;
template<typename It, typename d>
d merge(It begin1, It end1, It begin2, It end2, d first) {
	while (begin1 != end1 && begin2 != end2) {
		if (*begin1 < *begin2) {
			*first = *begin1;
			begin1++;
		}
		else {
			*first = *begin2;
			begin2++;
		}
		first++;
	}
	while (begin2 != end2) {
		*first = *begin2;
		first++;
		begin2++;
	}
	while (begin1 != end1) {
		*first = *begin1;
		first++;
		begin1++;
	}
	return first;
}
template<typename it>
void msort(it first, it last) {
	if (last - first == 1) return;
	int m = (last - first) / 2;
	msort(first, first + m);
	msort(first + m, last);
	int *dm = new int[last - first];
	merge(first, first + m, first + m, last, dm);
	int i = 0;
	for (first; first != last; first++) {
		*first = dm[i];
		i++;
	}
	delete[] dm;
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n = 0;
	cin >> n;
	if (n == 0) return 0;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	msort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}