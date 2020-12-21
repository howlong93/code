#include <bits/stdc++.h>

using namespace std;

struct Treap {
	int key, pri;
	struct Treap *l, *r;
	Treap (int _key): key (_key), pri(rand()), l(nullptr), r(nullptr){}
};

int depth = 0;

Treap* merge (Treap *a, Treap *b) {
	if (!a || !b) return a?a:b;
	if (a -> pri > b -> pri) {
		a -> r = merge (a -> r, b);
		return a;
	}
	else {
		b -> l = merge (a, b -> l);
		return b;
	}
}

void split (Treap *t, int x, Treap *&a, Treap *&b) {
	if (!t) {
		a = b = nullptr;
		return;
	}

	if (t -> key <= x) {
		a = t;
		split (t -> r, x, a -> r, b);
	}
	else {
		b = t;
	    split (t -> l, x, a, b -> l);
	}
}

void dfs (Treap *cur, int pos) {
	if (cur == nullptr) {
		depth = max (pos-1, depth);
		return;
	}

	dfs (cur -> l, pos+1);

	for (int i = 0; i < pos; i++) cout << " ";
	cout << cur -> key << '\n';

	dfs (cur -> r, pos+1);
}

int main() {
	srand(time(NULL));

	Treap *root = nullptr;
	for (int i = 1; i <= 100000; i++) {
		root = merge (root, new Treap(i));
	}

	dfs (root, 0);

	cout << '\n' << root -> key << '\n';
	cout << depth << '\n';
	
	return 0;
}
