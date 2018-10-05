#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;
void sorted(vector<string>& v) {
	sort(v.begin(), v.end());
	return;
}

void split(int one, int two, int num) {
	string name1 = to_string(one) + ".txt";
	string name2 = to_string(two) + ".txt";
	string name_file = to_string(num) + ".txt";
	ifstream stream1;
	stream1.open(name1);
	ifstream stream2;
	stream2.open(name2);
	ofstream out;
	out.open(name_file);

	string line1, line2;
	getline(stream1, line1);
	getline(stream2, line2);
	while (1) {
		if (stream1.eof()) {
			while (!stream2.eof() && line2 < line1) {
				out << line2 + '\n';
				getline(stream2, line2);
			}
			if (line1 < line2)
				out << line1 << '\n' << line2;
			else
				out << line2 << '\n' << line1;
			while (!stream2.eof()) {
				out << '\n';
				getline(stream2, line2);
				out << line2;
			}
			return;
		}
		if (stream2.eof()) {
			while (!stream1.eof() && line1 < line2) {
				out << line1 + '\n';
				getline(stream1, line1);
			}
			if (line1 < line2)
				out << line1 << '\n' << line2;
			else
				out << line2 << '\n' << line1;
			while (!stream1.eof()) {
				out << '\n';
				getline(stream1, line1);
				out << line1;
			}
			return;
		}
		if (line1 < line2) {
			out << line1 + '\n';
			getline(stream1, line1);
		}
		else {
			out << line2 + '\n';
			getline(stream2, line2);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m;
	ifstream formemory;
	formemory.open("memory.txt");
	formemory >> m;
	formemory.close();
	if (m > 5) {
		m = m / 2;
	}

	vector <string> lines;
	string s = "";
	fstream stream;
	int num = 0;
	while (getline(cin, s)) {
		lines.push_back(s);
		if (lines.size() == m) {
			string name = to_string(num) + ".txt";
			stream.open(name, ios_base::app);
			sorted(lines);
			stream << lines[0];
			for (int i = 1; i < m; i++) {
				stream << '\n' << lines[i];
			}
			num++;
			lines.clear();
			stream.close();
		}
	}
	if (lines.size() != 0) {
		string name = to_string(num) + ".txt";
		stream.open(name, ios_base::app);
		sorted(lines);
		stream << lines[0];
		for (int i = 1; i < lines.size(); i++) {
			stream << '\n' << lines[i];
		}
		num++;
		lines.clear();
		stream.close();
	}

	int one, two;
	int numcopy = num;
	for (int i = 0; i < numcopy - 1; i++) {
		one = 2 * i;
		two = one + 1;
		split(one, two, num);
		num++;
	}
	string namee = to_string(num - 1) + ".txt";
	stream.open(namee, ios_base::in);
	while (getline(stream, s)) {
		cout << s << '\n';
	}
	stream.close();
	for (int i = 0; i < num; i++) {
		string t = to_string(i) + ".txt";
		const char * f = t.c_str();
		remove(f);
	}
}