#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct point {
	int place;
	int num;
	int left;
	int right;
	int parrent;
	int colour;
};
int mainroot = 0;
void stabil(vector<point>& tree, int x);
void dedleft(vector<point>& tree, point& ded, point& papa, point& p) {
	if (ded.right != -1 && tree[ded.right].colour == 0) {
		papa.colour = 1;
		if (ded.right != -1) tree[ded.right].colour = 1;
		ded.colour = 0;
		tree[papa.place] = papa;
		tree[ded.place] = ded;
		tree[p.place] = p;
		if (ded.parrent == -1) tree[ded.place].colour = 1;
		if (ded.parrent != -1 && tree[ded.parrent].colour == 0) stabil(tree, ded.place);
		return;
	}
	else {
		if (p.place == papa.right) {
			ded.left = p.place;
			p.parrent = ded.place;
			papa.right = p.left;
			if (p.left != -1) tree[p.left].parrent = papa.place;
			p.left = papa.place;
			papa.parrent = p.place;
			tree[papa.place] = papa;
			tree[ded.place] = ded;
			tree[p.place] = p;
			point x = p;
			p = papa;
			papa = x;
		}
		if (ded.place == mainroot) mainroot = papa.place;
		ded.left = papa.right;
		if (papa.right != -1) tree[papa.right].parrent = ded.place;
		papa.right = ded.place;
		papa.parrent = ded.parrent;
		if (ded.parrent != -1) {
			if (ded.place == tree[ded.parrent].right) tree[ded.parrent].right = papa.place;
			if (ded.place == tree[ded.parrent].left) tree[ded.parrent].left = papa.place;
		}
		ded.parrent = papa.place;
		papa.colour = 1;
		ded.colour = 0;
		tree[papa.place] = papa;
		tree[ded.place] = ded;
		tree[p.place] = p;
		return;
	}
	return;
}
void dedright(vector<point>& tree, point& ded, point& papa, point& p) {
	if (ded.left != -1 && tree[ded.left].colour == 0) {
		papa.colour = 1;
		if (ded.left != -1) tree[ded.left].colour = 1;
		ded.colour = 0;
		tree[papa.place] = papa;
		tree[ded.place] = ded;
		tree[p.place] = p;
		if (ded.parrent == -1) tree[ded.place].colour = 1;
		if (ded.parrent != -1 && tree[ded.parrent].colour == 0) stabil(tree, ded.place);
		return;
	}
	else {
		if (p.place == papa.left) {
			ded.right = p.place;
			p.parrent = ded.place;
			papa.left = p.right;
			if (p.right != -1) tree[p.right].parrent = papa.place;
			p.right = papa.place;
			papa.parrent = p.place;
			tree[papa.place] = papa;
			tree[ded.place] = ded;
			tree[p.place] = p;
			point x = p;
			p = papa;
			papa = x;
		}
		if (ded.place == mainroot) mainroot = papa.place;
		ded.right = papa.left;
		if (papa.left != -1) tree[papa.left].parrent = ded.place;
		papa.left = ded.place;
		papa.parrent = ded.parrent;
		if (ded.parrent != -1) {
			if (ded.place == tree[ded.parrent].right) tree[ded.parrent].right = papa.place;
			if (ded.place == tree[ded.parrent].left) tree[ded.parrent].left = papa.place;
		}
		ded.parrent = papa.place;
		papa.colour = 1;
		ded.colour = 0;
		tree[papa.place] = papa;
		tree[ded.place] = ded;
		tree[p.place] = p;
		return;
	}
}
void stabil(vector<point>& tree, int x) {
	if (x == mainroot) {
		tree[x].colour = 1;
		return;
	}
	point p = tree[x];
	if (tree[p.parrent].colour == 1) return;
	point papa = tree[p.parrent];
	point ded = tree[papa.parrent];
	if (ded.left == papa.place) {
		dedleft(tree, ded, papa, p);
	}
	else {
		dedright(tree, ded, papa, p);
	}
}
void insert(vector<point>& tree, int x) {
	point p;
	if (tree.size() == 0) {
		p.left = -1;
		p.right = -1;
		p.parrent = -1;
		p.num = x;
		p.colour = 1;
		p.place = 0;
		tree.push_back(p);
	}
	else {
		bool b = 0;
		p.num = x;
		int i = mainroot;
		while (1) {
			int j;
			if (x < tree[i].num) {
				j = tree[i].left;
				if (j == -1) {
					p.parrent = i;
					p.right = -1;
					p.left = -1;
					tree[i].left = tree.size();
					break;
				}
				i = j;
			}
			if (x > tree[i].num) {
				j = tree[i].right;
				if (j == -1) {
					p.parrent = i;
					p.right = -1;
					p.left = -1;
					tree[i].right = tree.size();
					break;
				}
				i = j;
			}
			if (x == tree[i].num) {
				b = 1;
				break;
			}
		}
		if (!b) {
			p.colour = 0;
			p.place = tree.size();
			tree.push_back(p);
			stabil(tree, tree.size() - 1);
		}
	}
}
bool quest(vector<point>& tree, int root, int x) {
	if (tree.size() == 0) return 0;
	int i = mainroot;
	while (i != -1) {
		if (tree[i].num == x) return 1;
		if (tree[i].num < x) {
			i = tree[i].right;
		}
		else {
			i = tree[i].left;
		}
	}
	return 0;
}
void write(vector<point>& tree) {
	cout << tree.size() << '\n';
	for (auto p : tree) {
		cout << p.num << ' ';
		if (p.left == -1) {
			cout << "null ";
		}
		else {
			cout << tree[p.left].num << ' ';
		}
		if (p.right == -1) {
			cout << "null ";
		}
		else {
			cout << tree[p.right].num << ' ';
		}
		cout << (p.colour ? "B\n" : "R\n");
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	vector <point> tree;
	int n;
	cin >> n;
	int op, x;
	for (int i = 0; i < n; i++) {
		cin >> op >> x;
		if (op) {
			bool ans = quest(tree, mainroot, x);
			cout << (ans ? "Yes\n" : "No\n");
		}
		else {
			insert(tree, x);
		}
	}
	write(tree);
	return 0;
}